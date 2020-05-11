#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <engine.h>



TEST(TransitionTests, emptyTransitionIsEpsilon)
{
  Transition<int> t;

  ASSERT_NE(nullptr, t.getHead());
  ASSERT_TRUE(t.getIsEpsilon()); 
  ASSERT_EQ(0, t.getSymbol());

} 


