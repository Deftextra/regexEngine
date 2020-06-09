#include <state.h>
#include "Transition_tests.h"
#include "transition.h"
#include "gtest/gtest.h" 

using namespace engine;
using Transition_ptr = Transition<State>*;


INSTANTIATE_TYPED_TEST_CASE_P(TestStateEmptyTransition,EmptyTransitionTest ,State);

INSTANTIATE_TYPED_TEST_CASE_P(TestcharacterTransition, CharacterTransitionTest, State);

class emptyStateTest : public ::testing::Test
{
  protected:
    emptyStateTest() : value_{new State{}} {}

    virtual ~emptyStateTest() { delete value_; }

    State *value_;
};


class AddTransitionTest : public emptyStateTest, public ::testing::WithParamInterface<Transition<State>*>
{
  protected:
    AddTransitionTest()
    {
      value_->addTransition(GetParam());
    };
};

TEST_F(emptyStateTest, hasEmptyState) { EXPECT_TRUE(value_); }

TEST_F(emptyStateTest, hasNoTransitions)
{
  EXPECT_TRUE(value_->isEmpty() && value_->getTransitions().empty());
}

TEST_P(AddTransitionTest, addsTransition)
{

  EXPECT_EQ(value_->getTransitions().front(), GetParam());
}

INSTANTIATE_TEST_CASE_P(Default, AddTransitionTest,
    testing::Values(
      new Transition<State> {},
      new Transition<State> {'a'},
      new Transition<State> {'b'},
      new Transition<State> {'c'}
      )
    );
