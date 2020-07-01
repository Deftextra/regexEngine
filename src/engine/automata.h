#ifndef AUTOMATA_H
#define AUTOMATA_H

#include "states/state.h"
#include <memory>

namespace Automata
{
  class NDFA
  {
    public:
      // ----------- Basis ----------
      NDFA();
      NDFA(char a);
      //-------------------------------
      NDFA(const std::string& regex); 

      State& getStart() const { return *start; }
      State& getEnd() const { return *end; }

      NDFA& Union(const NDFA& a);
      NDFA& concat(const NDFA& a);
      NDFA& closure();
      
      bool match(std::istream& text);

    private:
      State_ptr start;
      State_ptr end;

      std::vector<State> symbolTransiton(char symbol, const State& s);
      void walk(const State& s, char symbol);

      bool isVistedState(const State& s);

      std::vector<State> visitedStates;
      std::vector<State> endStates;



  };

}

#endif //AUTOMATA_H
