#include "state.h"
#include "transitions/transition.h"
#include <iostream>
#include <vector>

using namespace Automata;
Automata::State::State(std::string name)
  : transitions{}
  , name{ name }
{}

State_ptr
Automata::State::create(std::string name)
{
    return std::make_shared<State>(State{ name });
}

State_ptr
Automata::State::addTransition()
{
    State_ptr end = create();

    transitions.push_back(Transition::create(end));

    return end;
}

State_ptr
Automata::State::addTransition(char symbol)
{
    State_ptr end = create();

    transitions.push_back(Transition::create(symbol, end));

    return end;
}

void
Automata::State::addTransition(Transition t)
{
    transitions.push_back(t);
}

void
Automata::State::addTransition(State_ptr toState)
{
    transitions.push_back(Transition::create(toState));
}

void
Automata::State::addTransition(char symbol, State_ptr toState)
{
    transitions.push_back(Transition::create(symbol, toState));
}

std::vector<State>
Automata::State::operator[](char symbol) const
{
    std::vector<State> states;

    for (const auto& transition : transitions) {
        if (transition.getSymbol() == symbol)
            states.push_back(*transition.getHead());
    }

    return states;
}

std::vector<State>
Automata::State::operator[](Transition::Type t) const
{
    std::vector<State> states;

    if (t == Transition::symbol) {
        for (const auto& transition : transitions) {
            if (!transition.IsEpsilon())
                states.push_back(*transition.getHead());
        }
    }

    if (t == Transition::epsilon) {
        for (const auto& transition : transitions) {
            if (transition.IsEpsilon())
                states.push_back(*transition.getHead());
        }
    }
    return states;
}

std::vector<State_ptr>
Automata::State::getEndsFrom(char symbol)
{
    std::vector<State_ptr> states;

    for (const auto& transition : transitions) {
        if (transition.getSymbol() == symbol)
            states.push_back(transition.getHead());
    }
    return states;
}

std::vector<State_ptr>
Automata::State::getEndsFrom(Transition::Type t)
{
    std::vector<State_ptr> states;

    if (t == Transition::symbol) {
        for (const auto& transition : transitions) {
            if (!transition.IsEpsilon())
                states.push_back(transition.getHead());
        }
    }

    if (t == Transition::epsilon) {
        for (const auto& transition : transitions) {
            if (transition.IsEpsilon())
                states.push_back(transition.getHead());
        }
    }
    return states;
}

bool
Automata::State::hasEpsilonTransitionTo(const State& state)
{
    for (const auto& stateFromEpsilon : (*this)[Transition::epsilon]) {
        if (stateFromEpsilon == state) {
            return true;
        }
    }
    return false;
}

bool
Automata::State::hasEpsilonTransitionTo(State_ptr state)
{
    for (const auto& stateFromEpsilon : getEndsFrom(Transition::epsilon)) {
        if (stateFromEpsilon == state) {
            return true;
        }
    }
    return false;
}

bool
Automata::State::hasSymbolTransitionTo(State_ptr state)
{
    for (const auto& stateFromSymbol : getEndsFrom(Transition::symbol)) {
        if (stateFromSymbol == state) {
            return true;
        }
    }
    return false;
}

bool
Automata::State::hasSymbolTransitionTo(const State& state)
{
    for (const auto& stateFromSymbol : (*this)[Transition::symbol]) {
        if (stateFromSymbol == state) {
            return true;
        }
    }
    return false;
}

bool
Automata::operator==(const State& lhs, const State& rhs)
{
    return lhs.transitions == rhs.transitions;
}

bool
Automata::State::operator==(const State& rhs)
{
    return transitions == rhs.transitions;
}

std::ostream&
Automata::operator<<(std::ostream& os, const State& s)
{
    os << s.getName() << std::endl;

    return os;
}
