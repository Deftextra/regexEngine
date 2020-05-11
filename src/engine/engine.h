
#ifndef ENGINE_H
#define ENGINE_H

#include <iostream>
#include <stdexcept>


template <typename T>
class Transition {
  T* head;
  char symbol;
  bool isEpsilon;
  
  public:
    Transition()  // We are assuming T has a default construtor. Can we remove this?
      :head{new T{}}, symbol{0}, isEpsilon{true} {} 
    
    Transition(char s)
      :head{new T{}}, symbol{s}, isEpsilon{false} {}
    ~Transition() { delete head; }

    char getSymbol() const { return symbol; }
    T* getHead() const { return head; }
    bool getIsEpsilon() const { return isEpsilon; }
  
};




#endif //ENGINE_H
