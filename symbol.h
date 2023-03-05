#pragma once

#include <string>
#include <map>
using namespace std;

enum Identificateurs { OPENPAR, CLOSEPAR, PLUS, MULT, INT, FIN, ERREUR, EXPRESSION };

const string Etiquettes[] = { "OPENPAR", "CLOSEPAR", "PLUS", "MULT", "INT", "FIN", "ERREUR", "EXPRESSION" };

class Symbol {
   public:
      Symbol(int i, bool terminal) : ident(i), terminal(terminal) { }
      virtual ~Symbol() { }
      operator int() const { return ident; }
      string getIdent(){ return Etiquettes[ident]; }
      bool isTerminal() { return terminal; }
      virtual void Affiche();

   protected:
      int ident;
      bool terminal;
};

class Entier : public Symbol {
   public:
      Entier(int v) : Symbol(INT, true), val(v) { }
      ~Entier() { }
      virtual void Affiche();
      int eval() { return val; };
   
   private:
      int val;
};

class Expr : public Symbol {
   public:
      Expr(int v = 0) : Symbol(EXPRESSION, false), val(v) { }
      ~Expr() { }
      virtual int eval() { return val; };

   protected:
      int val;
};

class ExprCste : public Expr {
   public:
      ExprCste(int v) : Expr(v) { }
      ~ExprCste() { }
};

class ExprBin : public Expr {
   public:
      ExprBin(Expr * e1, Expr * e2) { expr1 = e1; expr2 = e2;}
      ~ExprBin() { }
   
   protected:
      Expr * expr1;
      Expr * expr2;
};

class ExprPlus : public ExprBin {
   public:
      ExprPlus(Expr * e1, Expr * e2) : ExprBin(e1, e2) { }
      ~ExprPlus() { }
      int eval() { return expr1->eval() + expr2->eval(); }
};

class ExprMult : public ExprBin {
   public:
      ExprMult(Expr * e1, Expr * e2) : ExprBin(e1, e2) { }
      ~ExprMult() { }
      int eval() { return expr1->eval() * expr2->eval(); }
};
