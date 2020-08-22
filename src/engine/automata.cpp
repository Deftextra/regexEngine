#include <sstream>
#include <algorithm>
#include <vector>
#include "parser/parser.h"
#include "automata.h"
#include "states/state.h"

using namespace Automata;

Automata::NDFA::NDFA()
{ 
  start = State::create();
  end = start->addTransition();
}


Automata::NDFA::NDFA(char symbol)
{  
  start = State::create();
  end = start->addTransition(symbol);
}

Automata::NDFA::NDFA(const std::string& regex)
{
  if (regex.empty())
  {
    start = State::create();
    start->addTransition();
  }
  else
  {
    //TODO: Deal with expceptions by using try and catch.
    std::istringstream sRegex{Parser::convertToExplictConcatPostFixExpression(regex)};

    char token;
    std::vector<NDFA> workSpace;

    while (sRegex >> token)
    {
      if (token == '*')
      {
        workSpace.back().closure();
        continue;
      }

      if (token == '.')
      {
        workSpace.rbegin()[1].concat(workSpace.back());
        workSpace.pop_back();
        continue;
      }

      if (token == '|')
      {
        workSpace.rbegin()[1].Union(workSpace.back());
        workSpace.pop_back();
        continue;
      }

      workSpace.push_back(NDFA {token});
    }

    this->start = workSpace.back().start;
    this->end = workSpace.back().end;
  }

}


NDFA& Automata::NDFA::concat(const NDFA& a)
{
  this->end->addTransition(a.start);
  this->end = a.end;

  return *this;
}

NDFA&  Automata::NDFA::Union(const NDFA& a)
{
  State_ptr newStart = State::create();

  newStart->addTransition(start);
  newStart->addTransition(a.end);

  this->start = newStart;

  State_ptr newEnd = State::create();

  this->end->addTransition(newEnd);
  a.end->addTransition(newEnd);

  this->end = newEnd;

  return *this;
}

NDFA& Automata::NDFA::closure()
{
  State_ptr newStart = State::create();
  State_ptr newEnd = State::create();

  newStart->addTransition(newEnd);
  newStart->addTransition(this->start);

  this->end->addTransition(newEnd);
  this->end->addTransition(this->start);

  start = newStart;
  end = newEnd;

  return *this;
}

bool Automata::NDFA::match(std::istream& text)
{
  char token;
  text >> std::noskipws;

  std::vector<State> currentStates {getStart()};


  while (text >> token)
  {
    std::vector<State> newStates;

    for (const auto& state : currentStates)
    {
      for (const auto& newState : symbolTransiton(token,state))
        newStates.push_back(newState);
    }

    if (newStates.empty()) 
      return false;

    currentStates = newStates;
  }

  return true;
}

bool Automata::NDFA::isVistedState(const State& s)
{
  auto end = visitedStates.cend();

  return std::find(visitedStates.cbegin(), end, s) != end;
}


std::vector<State> Automata::NDFA::symbolTransiton(char symbol, const State& s)
{
  endStates.clear();
  visitedStates.clear();
  walk(s, symbol);

  return endStates;
}

void Automata::NDFA::walk(const State& s, char symbol)
{
    if (isVistedState(s))
    return;

  visitedStates.push_back(s);

  for (const auto& state : s[symbol])
    endStates.push_back(state);

  for (const auto& state : s[Transition::epsilon])
    walk(state, symbol);

}
