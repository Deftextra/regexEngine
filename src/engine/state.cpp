#include "state.h"
#include "transition.h"
#include <vector>

using Transition_ptr = engine::Transition<engine::State>*;
using Transition = engine::Transition<engine::State>;

engine::State::State()
  :transitions{} {}

engine::State::~State()
{
  for (const Transition_ptr& transition : transitions)
    delete transition;
}

std::vector<Transition_ptr> engine::State::getTransitions() const 
{ 
  return transitions;
}

bool engine::State::isEmpty() const 
{ 
  return transitions.empty();
}

engine::State& engine::State::addTransition(Transition_ptr t)
{
  transitions.push_back(t);

  return *(t->getHead());
}

bool engine::operator==(const engine::State& lhs, const engine::State& rhs) 
{ 
  return lhs.getTransitions() == rhs.getTransitions();
}


