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
    using Transition_ptr = Transition<State>*;

    friend class Automata;

    public:
      State();
      ~State();

      State& addTransition(Transition_ptr);
      std::vector<Transition_ptr> getTransitions() const;

      bool isEmpty() const;
      bool getIsEnd() const;

    private:
      std::vector<Transition_ptr> transitions; 
  }; 

  bool operator==(const State&,const State&);

}

#endif //STATE_H
