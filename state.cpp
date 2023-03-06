#include "state.h"

bool State0::transition(Automate & automate, Symbol * symbol){
    switch(*symbol){
        case OPENPAR:
        {
            automate.decalage(new State2, symbol);
            break;
        }
        case INT:
        {
            automate.decalage(new State3, symbol);
            break;
        }
        case EXPRESSION:
        {
            automate.decalageNonTerminal(new State1, symbol);
            break;
        }
        default:
            automate.decalage(nullptr, new Symbol(ERREUR, true));
            return false;
    }   
    return true;
}

bool State1::transition(Automate & automate, Symbol * symbol){
    switch(*symbol){
        case PLUS:
        {
            automate.decalage(new State4, symbol);
            break;
        }
        case MULT:
        {
            automate.decalage(new State5, symbol);
            break;
        }
        case FIN:
        {
            automate.accepter();
            break;
        }
        default:
            automate.decalage(nullptr, new Symbol(ERREUR, true));
            return false;
    }
    return true;
}

bool State2::transition(Automate & automate, Symbol * symbol){
    switch(*symbol){
        case OPENPAR:
        {
            automate.decalage(new State2, symbol);
            break;
        }
        case INT:
        {
            automate.decalage(new State3, symbol);
            break;
        }
        case EXPRESSION:
        {
            automate.decalageNonTerminal(new State6, symbol);
            break;
        }
        default:
            automate.decalage(nullptr, new Symbol(ERREUR, true));
            return false;
    }
    return true;
}

bool State3::transition(Automate & automate, Symbol * symbol){
    switch(*symbol){
        case PLUS:
        case MULT:
        case CLOSEPAR:
        case FIN:
        {
            ExprCste * val = new ExprCste(((Entier *) automate.popSymbol())->eval());
            automate.reduction(1, val);
            break;
        }
        default:
            automate.decalage(nullptr, new Symbol(ERREUR, true));
            return false;
    }
    return true;
}

bool State4::transition(Automate & automate, Symbol * symbol){
    switch(*symbol){
        case OPENPAR:
        {
            automate.decalage(new State2, symbol);
            break;
        }
        case INT:
        {
            automate.decalage(new State3, symbol);
            break;
        }
        case EXPRESSION:
        {
            automate.decalageNonTerminal(new State7, symbol);
            break;
        }
        default:
            automate.decalage(nullptr, new Symbol(ERREUR, true));
            return false;
    }
    return true;
}

bool State5::transition(Automate & automate, Symbol * symbol){
    switch(*symbol){
        case OPENPAR:
        {
            automate.decalage(new State2, symbol);
            break;
        }
        case INT:
        {
            automate.decalage(new State3, symbol);
            break;
        }
        case EXPRESSION:
        {
            automate.decalageNonTerminal(new State8, symbol);
            break;
        }
        default:
            automate.decalage(nullptr, new Symbol(ERREUR, true));
            return false;
    }
    return true;
}

bool State6::transition(Automate & automate, Symbol * symbol){
    switch(*symbol){
        case PLUS:
        {
            automate.decalage(new State4, symbol);
            break;
        }
        case MULT:
        {
            automate.decalage(new State5, symbol);
            break;
        }
        case CLOSEPAR:
        {
            automate.decalage(new State9, symbol);
            break;
        }
        default:
            automate.decalage(nullptr, new Symbol(ERREUR, true));
            return false;
    }
    return true;
}

bool State7::transition(Automate & automate, Symbol * symbol){
    switch(*symbol){
        case PLUS:
        case CLOSEPAR:
        case FIN:
        {
            Expr * s1 = (Expr *) automate.popSymbol();
            automate.popSymbol();
            Expr * s2 = (Expr *) automate.popSymbol();
            ExprPlus * s_gauche = new ExprPlus(s1, s2);
            automate.reduction(3, s_gauche);
            break;
        }
        case MULT:
        {
            automate.decalage(new State5, symbol);
            break;
        }
        default:
            automate.decalage(nullptr, new Symbol(ERREUR, true));
            return false;
    }
    return true;
}

bool State8::transition(Automate & automate, Symbol * symbol){
    switch(*symbol){
        case PLUS:
        case MULT:
        case CLOSEPAR:
        case FIN:
        {
            Expr * s1 = (Expr *) automate.popSymbol();
            automate.popSymbol();
            Expr * s2 = (Expr *) automate.popSymbol();
            ExprMult * s_gauche = new ExprMult(s1, s2);
            automate.reduction(3, s_gauche);
            break;
        }
        default:
            automate.decalage(nullptr, new Symbol(ERREUR, true));
            return false;
    }
    return true;
}

bool State9::transition(Automate & automate, Symbol * symbol){
    switch(*symbol){
        case PLUS:
        case MULT:
        case CLOSEPAR:
        case FIN:
        {
            automate.popSymbol();
            Expr * e = new Expr(((Expr *)automate.popSymbol())->eval());
            automate.popSymbol();
            automate.reduction(3, e);
            break;
        }
        default:
            automate.decalage(nullptr, new Symbol(ERREUR, true));
            return false;
    }
    return true;
}