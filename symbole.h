#pragma once

#include <string>
using namespace std;

enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR, EXPRESSION };

const string Etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR", "EXPRESSION" };

class Symbole {
   public:
      Symbole(int i) : ident(i) {  }
      virtual ~Symbole() { }
      operator int() const { return ident; }
      virtual void Affiche();

   protected:
      int ident;
};

class Entier : public Symbole {
   public:
      Entier(int v) : Symbole(INT), valeur(v) { }
      ~Entier() { }
      virtual void Affiche();
   protected:
      int valeur;
};

class Expr : public Symbole {
   public:
      Expr() : Symbole(EXPRESSION) { }
      ~Expr() { }
      int Eval();
}

class ExprBin : public Expr {
   public:
      ExprBin(Expr * e1, Expr * e2) : e1(e1), e2(e2) { }
      ~ExprBin() { }
   protected:
      Expr * e1;
      Expr * e2;
}

class ExprCste : public Expr {
   public:
      ExprCste(int a) : val(a) { }
      ~ExprCste() { }
   private:
      int val;
}

class ExprPlus : public ExprBin {
   public:
      ExprPlus(Expr * e1, Expr * e2) : ExprBin(e1, e2) { }
      ~ExprPlus() { }
}

class ExprMult : public ExprMult {
   public:
      ExprMult(Expr * e1, Expr * e2) : ExprBin(e1, e2) { }
      ~ExprMult() { }
}