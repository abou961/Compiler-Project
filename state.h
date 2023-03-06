#include "automate.h"
#include <string>

using namespace std;

class State{
    public:
        State(string name) : name(name) { }
        ~State() { }
        virtual bool transition(Automate & automate, Symbol * symbol) = 0;
        string getName() { return name; }
    
    protected:
        string name;
};

class State0 : public State{
    public:
        State0() : State("State0") {  }
        bool transition(Automate & automate, Symbol * symbol);
};

class State1 : public State{
    public:
        State1() : State("State1") { }
        bool transition(Automate & automate, Symbol * symbol);
};

class State2 : public State{
    public:
        State2() : State("State2") { }
        bool transition(Automate & automate, Symbol * symbol);
};

class State3 : public State{
    public:
        State3() : State("State3") { }
        bool transition(Automate & automate, Symbol * symbol);
};

class State4 : public State{
    public:
        State4() : State("State4") { }
        bool transition(Automate & automate, Symbol * symbol);
};

class State5 : public State{
    public:
        State5() : State("State5") { }
        bool transition(Automate & automate, Symbol * symbol);
};

class State6 : public State{
    public:
        State6() : State("State6") { }
        bool transition(Automate & automate, Symbol * symbol);
};

class State7 : public State{
    public:
        State7() : State("State7") { }
        bool transition(Automate & automate, Symbol * symbol);
};

class State8 : public State{
    public:
        State8() : State("State8") { }
        bool transition(Automate & automate, Symbol * symbol);
};

class State9 : public State{
    public:
        State9() : State("State9") { }
        bool transition(Automate & automate, Symbol * symbol);
};