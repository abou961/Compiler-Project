#include "automate.h"
#include <vector>

using namespace std;

void Automate::decalage(Etat& etat, Symbole symbole){
    // Empiler Etat
    this->pileEtats.push(etat);

    // Empiler Symbole
    this->pileSymboles.push(symbole)

    // Avancer tête de lecture
    this->lexer.Avancer();
}

void Automate::decalageTer(Etat& etat, Symbole symbole){
    // Empiler Etat
    this->pileEtats.push(etat);

    // Empiler Symbole
    this->pileSymboles.push(symbole)
}


void Automate::reduction(int n, Symbole s){
    // Symbole s
    for(int i = 0; i < n; i++){
        this->pileEtats.pop();
    }

    transition(this->pileEtats.top(), s)

}

void Automate::accepter(){
    this->end_reached = true;
}
        