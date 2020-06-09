#include "transition.h"
#include "state.h"


template <typename T>
engine::Transition<T>::Transition()
  :head{new T{}}, symbol{0}, isEpsilon{true}{}


template <typename T>
engine::Transition<T>::Transition(char s)
  :head{new T{}}, symbol{s}, isEpsilon{false} {}

template <typename T>
engine::Transition<T>::~Transition()
{
  delete head;
}

template <typename T>
inline T*  engine::Transition<T>::getHead() const
{
  return head;
}

template <typename T>
inline char engine::Transition<T>::getSymbol() const
{
  return symbol;
}

template <typename T>
inline bool engine::Transition<T>::getIsEpsilon() const
{
  return isEpsilon;
}


template class engine::Transition<int>;
template class engine::Transition<engine::State>;
