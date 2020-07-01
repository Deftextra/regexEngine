#include "transitions/transition.h"


using namespace Automata;

Transition::Transition(State_ptr head)
  :head{head},type{epsilon}, symbolValue{epsilon} {}

Transition::Transition(char symbol, State_ptr head)
  :head{head}, type{Transition::symbol}, symbolValue{symbol} {}

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
    (lhs.type == rhs.type) &&
    lhs.symbol == rhs.symbol;
}


