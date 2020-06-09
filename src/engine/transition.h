#ifndef TRANSITION_H
#define TRANSITION_H

#include <iostream>
#include <stdexcept>


namespace engine 
{
  template <typename T>
    class Transition 
    {
      public:
        Transition();
        explicit Transition(char s);

        ~Transition();

        char getSymbol() const;
        T* getHead() const;
        bool getIsEpsilon() const;

      private:
        T* head;
        char symbol;
        bool isEpsilon;
    };
}

#endif //TRANSITION_H
