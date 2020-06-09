#include "state.h"
#include <vector>

using Transitions = engine::Transition<engine::State>;
using Transition_ptr = engine::Transition<engine::State>*;

engine::State::State()
  :isEnd{true}, transitions{} {}

std::vector<Transition_ptr> engine::State::getTransitions() const 
{ 
  return transitions;
}

bool engine::State::isEmpty() const 
{ 
  return transitions.empty();
}

bool engine::operator==(const engine::State& lhs, const engine::State& rhs) 
{ 
  return (lhs.getTransitions() == rhs.getTransitions());
}


