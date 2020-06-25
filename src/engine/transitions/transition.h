#ifndef TRANSITION_H
#define TRANSITION_H

#include <memory>

namespace Automata
{

  class State;

  using State_ptr = std::shared_ptr<State>;

  class Transition 
  {

    friend  bool operator==(const Transition&, const Transition& rhs);
    friend class State;
    friend class NDFA;

    public:
      enum Type {symbol, epsilon};
      bool IsEpsilon() const { return epsilonValue; }
      char getSymbol() const { return symbolValue;}
      State_ptr getHead() const { return head; }

    private:
      static  Transition create(State_ptr); 
      static Transition create(char symbol, State_ptr head);

      explicit Transition(State_ptr head);
      explicit Transition(char a, State_ptr head);
      Transition& changeHead(State_ptr head);

      char symbolValue;
      State_ptr head;
      bool epsilonValue;
  };
  

  bool operator==(const Transition&, const Transition&);
}
#endif //TRANSITION_H



