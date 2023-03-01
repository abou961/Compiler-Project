#include "automate.h"

using namespace std;

Automate::Automate() {
    pileEtats.push(new E0);
}

void Automate::decalage(Etat * etat, Symbole * symbole){
    // Empiler Etat
    this->pileEtats.push(etat);

    // Empiler Symbole
    this->pileSymboles.push(symbole);

    // Avancer tête de lecture si le symbole est terminal
    if (symbole->isTerminal()) {
        this->lexer->Avancer();
    }
}

void Automate::decalageTer(Etat * etat, Symbole * symbole){
    // Empiler Etat
    this->pileEtats.push(etat);

    // Empiler Symbole
    this->pileSymboles.push(symbole);
}


void Automate::reduction(int n, Symbole * symbole){
    // Symbole s
    for(int i = 0; i < n; i++){
        this->pileEtats.pop();
    }
    this->pileEtats.top()->transition(*this, symbole);
}

void Automate::accepter(){
    this->end_reached = true;
}
        