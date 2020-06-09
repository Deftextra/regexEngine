#ifndef TRANSITION_TESTS_HEADER
#include <transition.h> 
#include "gtest/gtest.h" 
#include "gtest/gtest-typed-test.h"
#include <vector>

// Review maybe combine these test cases in one suite?
template <class T>
class EmptyTransitionTest : public ::testing::Test {
 protected:
  EmptyTransitionTest() 
    :value_(new engine::Transition<T> {}), emptyHead{new T{}} {}
      
  T* emptyHead;

  ~EmptyTransitionTest() override { delete value_; delete emptyHead; }

  engine::Transition<T>* const value_;
};

template <class T>
class CharacterTransitionTest : public ::testing::Test {
 protected:
  
   CharacterTransitionTest() 
     :symbols{'a','b','c'},
      emptyHead{new T {}} 
   {
     for (char c : symbols)
       CharacterTransitionIntializations[c] = new engine::Transition<T> {c};
   }

  ~CharacterTransitionTest() override { delete emptyHead;}

  T* emptyHead;

  std::vector<char> symbols;

  std::map<char, engine::Transition<T>*> CharacterTransitionIntializations;
  
};

#if GTEST_HAS_TYPED_TEST_P

TYPED_TEST_CASE_P(EmptyTransitionTest);

TYPED_TEST_P(EmptyTransitionTest, CreatesEmptyHead)
{
  EXPECT_EQ(*(this->value_->getHead()), *(this->emptyHead)); 
}

TYPED_TEST_P(EmptyTransitionTest, hasEmptyTransition)
{
  EXPECT_TRUE(this->value_);
}

TYPED_TEST_P(EmptyTransitionTest, IsNotSymbol)
{
  EXPECT_FALSE(this->value_->getSymbol());
}

TYPED_TEST_P(EmptyTransitionTest, IsEpsilon)
{
  EXPECT_TRUE(this->value_->getIsEpsilon());
}

REGISTER_TYPED_TEST_CASE_P
(
 EmptyTransitionTest, 
 CreatesEmptyHead,
 hasEmptyTransition,
 IsEpsilon,
 IsNotSymbol
);

TYPED_TEST_CASE_P(CharacterTransitionTest);


TYPED_TEST_P(CharacterTransitionTest,hasCharacterTransition)
{
  for (auto transition : this->CharacterTransitionIntializations)
    EXPECT_TRUE(transition.second);
}

TYPED_TEST_P(CharacterTransitionTest, IsSymbol )
{
  for (auto transition : this->CharacterTransitionIntializations)
    EXPECT_EQ( transition.first, transition.second->getSymbol());
}


TYPED_TEST_P(CharacterTransitionTest, IsNotEpsilon)
{
  for (auto transition : this->CharacterTransitionIntializations)
    EXPECT_FALSE(transition.second->getIsEpsilon());
}

TYPED_TEST_P(CharacterTransitionTest, CreatesEmptyHead)
{
  for (auto transition : this->CharacterTransitionIntializations)
    EXPECT_EQ(*(transition.second->getHead()), *(this->emptyHead));
}

REGISTER_TYPED_TEST_CASE_P
(
 CharacterTransitionTest, 
 hasCharacterTransition,
 IsSymbol,
 IsNotEpsilon,
 CreatesEmptyHead
);

#endif // GTEST_HAS_TYPED_TEST_P 
#endif // TRANSITION_TESTS_HEADER

