#include <iostream>
#include <string>
#include "state.h"

int main(void) {
   string chaine("(1+34)*123");

   Automate * automate = new Automate(chaine);
   automate->lecture();

   return 0;
}

