#ifndef STATE_H
#define STATE_H

#include "transitions/transition.h"
#include <memory>
#include <vector>

namespace Automata {
class State
{
    friend bool operator==(const State&, const State&);

    using Transitons = std::vector<Transition>;

  public:
    static State_ptr create(std::string name = "default");

    State_ptr addTransition();
    State_ptr addTransition(char symbol);

    void addTransition(Transition t);
    void addTransition(State_ptr toState);
    void addTransition(char symbol, State_ptr);

    //  What if we create a general transition.
    std::vector<State> operator[](char symbol) const;
    std::vector<State> operator[](Transition::Type t) const;
    bool operator==(const State&);

    std::vector<State_ptr> getEndsFrom(char symbol);
    std::vector<State_ptr> getEndsFrom(Transition::Type t);

    bool hasEpsilonTransitionTo(State_ptr);
    bool hasEpsilonTransitionTo(const State&);
    bool hasSymbolTransitionTo(State_ptr);
    bool hasSymbolTransitionTo(const State&);

    Transitons getTransition() const { return transitions; }
    bool isEmpty() const { return transitions.empty(); }
    std::string getName() const { return name; }
    void giveName(std::string name) { this->name = name; }

  private:
    // TODO: maybe add move constructor and assignment.
    State(std::string name);

    std::string name;
    Transitons transitions;
};

std::ostream&
operator<<(std::ostream& os, const State& s);

bool
operator==(const State&, const State&);
} // namespace Automata

#endif // STATE_H
