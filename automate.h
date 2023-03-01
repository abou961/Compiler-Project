#include "symbole.h"
#include "lexer.h"
#include <stack>
class Etat;

using namespace std;

class Automate {
    public:
        Automate(Lexer * l) : lexer(l), end_reached(false) { }
        Etat * topPileEtats() { return pileEtats.top(); }
        void decalage(Etat * etat, Symbole * symbole);
        void decalageTer(Etat * etat, Symbole * symbole);
        void reduction(int n, Symbole * symbole); 
        void accepter();
        ~Automate(); 

    private:
        stack<Etat *> pileEtats;
        stack<Symbole *> pileSymboles;
        Lexer * lexer;
        bool end_reached;
};