#include <memory>
#include "transitions/transition.h"


using namespace Automata;

Transition::Transition(State_ptr head)
  :head{head},epsilonValue{true}, symbolValue{0} {}

Transition::Transition(char symbol, State_ptr head)
  :head{head}, epsilonValue{false}, symbolValue(symbol) {}

Transition& Automata::Transition::changeHead(State_ptr head)
{
  this->head = head;

  return *this;
}

Transition Automata::Transition::create(State_ptr head) {
    return Transition {head};
}

Transition Automata::Transition::create(char symbol,State_ptr head)
{
    return Transition {symbol, head};
}

bool Automata::operator==(const Automata::Transition& lhs, const Automata::Transition& rhs)
{
  return (lhs.head == rhs.head) &&
    (lhs.epsilonValue == rhs.epsilonValue) &&
    lhs.symbol == rhs.symbol;
}


