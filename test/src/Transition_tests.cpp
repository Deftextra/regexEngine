#include <transition.h> 
#include "gtest/gtest.h" 
#include "gtest/gtest-typed-test.h"
// define this as a .h file and include in the state testing class.

using namespace engine;
template <class T>
class EmptyTransitionTest : public ::testing::Test {
 protected:
  EmptyTransitionTest() :value_(new Transition<T> {}) {}

  ~EmptyTransitionTest() override { delete value_; }

  Transition<T>* const value_;
};

template <class T>
class SymbolTansitionTest : public ::testing::Test, testing::WithParamInterface<char>  {
 protected:
   SymbolTansitionTest() {
     
   }

  ~SymbolTansitionTest() override { delete value_; }

  Transition<T>* const value_;
};

#if GTEST_HAS_TYPED_TEST_P

// ---------- Empty Transition Test Cases ----------------
TYPED_TEST_CASE_P(EmptyTransitionTest);

TYPED_TEST_P(EmptyTransitionTest, hasEmptyTransition)
{
  EXPECT_TRUE(this->value_);
}

TYPED_TEST_P(EmptyTransitionTest, emptyTransitionIsEpsilon)
{
  EXPECT_TRUE(this->value_->getIsEpsilon());
  EXPECT_FALSE(this->value_->getSymbol());
}

TYPED_TEST_P(EmptyTransitionTest, emptyTransitionIsNotSymbol)
{
  EXPECT_TRUE(this->value_->getIsEpsilon());
  EXPECT_FALSE(this->value_->getSymbol());
}



REGISTER_TYPED_TEST_CASE_P
(
 EmptyTransitionTest, 
 hasEmptyTransition,
 emptyTransitionIsEpsilon,
 emptyTransitionIsNotSymbol
 );


#endif // GTEST_HAS_TYPED_TEST_P


