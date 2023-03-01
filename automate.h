#include "symbole.h"
#include "lester.h"
class Etat;

using namespace std;

class Automate {
    public:
        Automate() : pileEtats(nullptr), pileSymboles(nullptr) {}
        void decalage(Etat etat, Symbole symbole);
        void decalageTer(Etat etat, Symbole symbole);
        void reduction(int n, Symbole s); 
        void accepter(); 
        ~Automate(); 

    protected:
        stack<Etat> pileEtats;
        stack<Etat> pileSymboles;
        Lexer lexer;
        bool end_reached;
}