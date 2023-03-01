#include <iostream>
#include "lexer.h"
#include "automate.h"
#include "etat.h"

int main(void) {
   string chaine("(1+34)*123");

   Lexer l(chaine);

   Automate automate(&l);

   Symbole * s;
   while(*(s=l.Consulter())!=FIN) {
      s->Affiche();
      cout<<endl;
      automate.topPileEtats()->transition(automate, s);
      l.Avancer();
   }
   return 0;
}

