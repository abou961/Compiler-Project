#include <iostream>
#include "state.h"

using namespace std;

Automate::Automate(string chaine) {
    this->lexer = new Lexer(chaine);
    end_reached = false;
    stateStack.push(new State0);
}

void PrintStateStack(stack<State *> s)
{
    if (s.empty())
        return;
    State * x = s.top();
    s.pop();
    PrintStateStack(s);
    cout << x->getName() << " ";
    s.push(x);
}

void PrintSymbolStack(stack<Symbol *> s)
{
    if (s.empty())
        return;
    Symbol * x = s.top();
    s.pop();
    PrintSymbolStack(s);
    if(x==dynamic_cast<Entier *>(x))
        cout << "int:" <<((Entier *)x)->eval() << " ";
    else if (x==dynamic_cast<Expr *>(x))
        cout << "exp:" << ((Expr *)x)->eval() << " ";
    else
        cout << x->getIdent() << " ";
    
    s.push(x);
}

bool Automate::lecture(){
    Symbol * s;
    while(!end_reached) {
        s=lexer->Consulter();
        if(!stateStack.top()->transition(*this, s)){
            break;
        }
    }
    if (*symbolStack.top() != ERREUR)
    {
        result = dynamic_cast<Expr *>(symbolStack.top())->eval();
        return true;
    }
    return false;
}

void Automate::decalage(State * state, Symbol * symbol){
    // Empiler State
    stateStack.push(state);

    // Empiler Symbol
    symbolStack.push(symbol);

    // Avancer tête de lecture si le symbol est terminal
    if (symbol->isTerminal()) {
        lexer->Avancer();
    }
}

void Automate::decalageNonTerminal(State * state, Symbol * symbol){
    // Empiler State
    stateStack.push(state);

    // Empiler Symbol
    symbolStack.push(symbol);
}


void Automate::reduction(int n, Symbol * symbol){
    for(int i = 0; i < n; i++){
        stateStack.pop();
    }
    stateStack.top()->transition(*this, symbol);
}
        
Symbol * Automate::popSymbol(){ 
    Symbol * top = symbolStack.top();
    symbolStack.pop();
    return top;
}