#include <stack>
#include "lexer.h"
#include "symbol.h"
class State;

using namespace std;

class Automate {
    public:
        Automate(string chaine);
        ~Automate() { } 
        bool lecture();
        void decalage(State * state, Symbol * symbol);
        void decalageNonTerminal(State * state, Symbol * symbol);
        void reduction(int n, Symbol * symbol); 
        void accepter() { end_reached = true; }
        Symbol * popSymbol();
        int getResult() { return result; }

    private:
        stack<State *> stateStack;
        stack<Symbol *> symbolStack;
        Lexer * lexer;
        bool end_reached;
        int result;
};