#include "symbol.h"
#include <iostream>

void Symbol::Affiche() {
   cout<<Etiquettes[ident];
}

void Entier::Affiche() {
   Symbol::Affiche();
   cout<<"("<<val<<")";
}

