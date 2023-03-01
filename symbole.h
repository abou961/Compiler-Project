#pragma once

#include <string>
#include <map>
using namespace std;

enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR, EXPRESSION };

const string Etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR", "EXPRESSION" };

class Symbole {
   public:
      Symbole(int i, bool terminal) : ident(i), terminal(terminal) {  }
      virtual ~Symbole() { }
      bool isTerminal() { return terminal; }
      operator int() const { return ident; }
      virtual void Affiche();

   protected:
      bool terminal;
      int ident;
};

class Entier : public Symbole {
   public:
      Entier(int v) : Symbole(INT, true), valeur(v) { }
      ~Entier() { }
      virtual void Affiche();
   protected:
      int valeur;
};

class Expr : public Symbole {
   public:
      Expr() : Symbole(EXPRESSION, false) { }
      ~Expr() { }
      virtual double eval(const map<string, double> & valeurs) = 0;
};

class ExprBin : public Expr {
   public:
      ExprBin(Expr * e1, Expr * e2) : e1(e1), e2(e2) { }
      ~ExprBin() { }
   protected:
      Expr * e1;
      Expr * e2;
};

class ExprCste : public Expr {
   public:
      ExprCste(int a) : val(a) { }
      ~ExprCste() { }
   private:
      int val;
};

class ExprPlus : public ExprBin {
   public:
      ExprPlus(Expr * e1, Expr * e2) : ExprBin(e1, e2) { }
      ~ExprPlus() { }
      double eval(const map<string, double> & valeurs);
};

class ExprMult : public ExprBin {
   public:
      ExprMult(Expr * e1, Expr * e2) : ExprBin(e1, e2) { }
      ~ExprMult() { }
      double eval(const map<string, double> & valeurs);
};