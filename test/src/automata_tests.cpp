#include <automata.h>
#include "gtest/gtest.h" 
#include <vector>

using namespace Automata;

class BasisTest : public ::testing::Test
{
  protected:
      BasisTest() 
      :epsilonBasis{ new NDFA {} }, symbolBasis{ new NDFA {'s' } }
    {
      epsilonBasis->getStart().giveName(" Intial start of epsilonBasis");
      epsilonBasis->getEnd().giveName(" Initial end of epsilonBasis");
      symbolBasis->getStart().giveName("Initial start of symbolBasis");

    }

    virtual ~BasisTest() { delete epsilonBasis; delete symbolBasis; }

    NDFA* epsilonBasis;
    NDFA* symbolBasis;

};



TEST_F(BasisTest, createsBasis)
{
  EXPECT_TRUE(epsilonBasis->getStart().hasEpsilonTransitionTo(epsilonBasis->getEnd()));
  EXPECT_TRUE(symbolBasis->getStart().hasSymbolTransitionTo(symbolBasis->getEnd()));
}

TEST_F(BasisTest, concatOperation )
{

  const State& endOfEpsilonBeforeConcat = epsilonBasis->getEnd();
  epsilonBasis->concat(*symbolBasis);

  const std::vector<State> result = epsilonBasis->getStart()[Transition::epsilon];

  ASSERT_TRUE(!result.empty());

  ASSERT_EQ(symbolBasis->getEnd(), epsilonBasis->getEnd());

  EXPECT_EQ(endOfEpsilonBeforeConcat, result.front());

  EXPECT_EQ(result[0][Transition::epsilon][0], symbolBasis->getStart());

  EXPECT_EQ(result[0][Transition::epsilon][0]['s'][0], epsilonBasis->getEnd());
}

struct InputValue
{
  InputValue(std::string regex, std::string matchingWord)
    :regex{regex}, MatchingWord{matchingWord} {}

  std::string regex;
  std::string MatchingWord;
};

class MatcherTest : public ::testing::WithParamInterface<InputValue>,
                     public ::testing::Test
{
  protected:
    MatcherTest() :regexToNDFA{new NDFA {GetParam().regex}} {}

  NDFA* regexToNDFA;
};

TEST_P(MatcherTest, TestingMatcher)
{
  std::stringstream sWord {GetParam().MatchingWord};

  ASSERT_TRUE(regexToNDFA->match(sWord));
}


INSTANTIATE_TEST_CASE_P(Default, MatcherTest,
  testing::Values(
    InputValue("abc","abc"),
    InputValue("ab*c","abbbc") ,
    InputValue("ab*c","abbbc") ,
    InputValue("ab*c","abbbbbbc") ,
    InputValue("firstName|lastName","firstName")
    )
);

