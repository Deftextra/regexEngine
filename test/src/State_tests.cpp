#include <state.h>
#include "Transition_tests.h"
#include "transition.h"
using namespace engine;


INSTANTIATE_TYPED_TEST_CASE_P(TestStateEmptyTransition,EmptyTransitionTest ,State);

INSTANTIATE_TYPED_TEST_CASE_P(TestcharacterTransition, CharacterTransitionTest, State);

