#include <state.h>
#include <memory>
#include <utility>
#include "gtest/gtest.h" 

using namespace Automata;

class SymbolTransitionTest 
: public
  ::testing::WithParamInterface<std::pair<char,State_ptr>>,
  public ::testing::Test
{
  protected:
    SymbolTransitionTest()
    {
      end_ = State::create();
    };

    State_ptr end_;
};

TEST(StateTest, factoryCreatesState)
{
  EXPECT_TRUE(State::create());
}

TEST(StateTest, factoryCreatesEmptyStates)
{
  State_ptr state = State::create();
  
  EXPECT_TRUE(state->isEmpty());
}

TEST(StateTest, addsEpsilonTransitionToState)
{
  State_ptr start = State::create();
  State_ptr end = State::create();

  start->addTransition(end);

  EXPECT_TRUE(start->hasEpsilonTransitionTo(start->addTransition()));
  EXPECT_TRUE(start->hasEpsilonTransitionTo(end));
}



TEST_P(SymbolTransitionTest, addsSymbolTransitonToState)
{
  State_ptr start = State::create();
  char symbol = GetParam().first;

  start->addTransition(symbol, end_);

  EXPECT_TRUE(start->hasSymbolTransitionTo(start->addTransition(symbol)));
  EXPECT_TRUE(start->hasSymbolTransitionTo(end_));
}

INSTANTIATE_TEST_CASE_P(Default, SymbolTransitionTest,
  testing::Values(
    std::make_pair('a', State::create()),
    std::make_pair('b', State::create()),
    std::make_pair('c', State::create())
    )
);
