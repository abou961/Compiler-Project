#include <iostream>
#include <string>
#include "state.h"

using namespace std;

int main(void) {

   string codeUser("Y");

   cout << "____________Automate___________\n\n\n";
   
   while(codeUser != "n"){
      codeUser = "";
      string chain("");
      cout << "Please enter the chain you want to calculate :" << endl;
      cin >> chain;

      
      
      Automate * automate = new Automate(chain); // changer
      if(!automate->lecture()){
         cout << "Erreur !" << endl;
      } else {
         cout << "Result : " << automate->getResult() << endl; // ajouter
      }

      while(codeUser != "Y" && codeUser != "n"){
         cout << "Do you want to continue ? (Y/n)" << endl;
         cin >> codeUser;
      }
   }
   return 0;
}

