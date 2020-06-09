#ifndef STATE_H
#define STATE_H

#include <iostream>
#include <vector>
#include <stdexcept>
#include "transition.h"

namespace engine
{
  class State
  {
    using Transitions = Transition<State>;
    using Transition_ptr = Transition<State>*;

    friend class Automata;

    public:
      State();

      std::vector<Transition_ptr> getTransitions() const;
      bool isEmpty() const;


    private:
    // End states should always be empty
      bool isEnd;
      std::vector<Transition_ptr> transitions;
  };

  bool operator==(const State&,const State&);

}

#endif //STATE_H
