#include "etat.h"

void E0::transition(Automate & automate, Symbole * symbole){
    switch(*symbole){
        case OPENPAR:
            automate.decalage(new E2, symbole);
            break;
        case INT:
            automate.decalage(new E3, symbole);
            break;
        case EXPRESSION:
            automate.decalageTer(new E1, symbole);
        default:
            //err
    }   
}

void E1::transition(Automate & automate, Symbole * symbole){
    switch(*symbole){
        case PLUS:
            automate.decalage(new E4, symbole);
            break;
        case MULT:
            automate.decalage(new E5, symbole);
            break;
        case FIN:
            automate.accepter();
            break;
        default:
            //err
    }
}

void E2::transition(Automate & automate, Symbole * symbole){
    switch(*symbole){
        case OPENPAR:
            automate.decalage(new E4, symbole);
            break;
        case INT:
            automate.decalage(new E5, symbole);
            break;
        case EXPRESSION:
            automate.decalageTer(new E6, symbole);
            break;
        default:
            //err
    }
}

void E3::transition(Automate & automate, Symbole * symbole){
    switch(*symbole){
        case PLUS:
            ExprCste * val = (ExprCste *) automate.pileSymboles.pop();
            automate.reduction(1, val);
            break;
        case MULT:
            ExprCste * val = (ExprCste *) automate.pileSymboles.pop();
            automate.reduction(1, val);
            break;
        case CLOSEPAR:
            ExprCste * val = (ExprCste *) automate.pileSymboles.pop();
            automate.reduction(1, val);
            break;
        case FIN:
            ExprCste * val = (ExprCste *) automate.pileSymboles.pop();
            automate.reduction(1, val);
        default:
            //err
    }
}

void E4::transition(Automate & automate, Symbole * symbole){
    switch(*symbole){
        case OPENPAR:
            automate.decalage(new E2, symbole);
            break;
        case INT:
            automate.decalage(new E3, symbole);
            break;
        case EXPRESSION:
            automate.decalageTer(new E7, symbole);
            break;
        default:
            //err
    }
}

void E5::transition(Automate & automate, Symbole * symbole){
    switch(*symbole){
        case OPENPAR:
            automate.decalage(new E2, symbole);
            break;
        case INT:
            automate.decalage(new E3, symbole);
            break;
        case EXPRESSION:
            automate.decalageTer(new E8, symbole);
            break;
        default:
            //err
    }
}

void E6::transition(Automate & automate, Symbole * symbole){
    switch(*symbole){
        case PLUS:
            automate.decalage(new E4, symbole);
            break;
        case MULT:
            automate.decalage(new E5, symbole);
            break;
        case CLOSEPAR:
            automate.decalage(new E9, symbole);
            break;
        default:
            //err
    }
}

void E7::transition(Automate & automate, Symbole * symbole){
    switch(*symbole){
        case PLUS:
            Expr * s1 = automate.pileSymboles.pop();
            automate.pileSymboles.pop();
            Expr * s2 = automate.pileSymboles.pop();
            Symbole s_gauche = new ExprPlus(s1, s2);
            automate.reduction(3, s_gauche);
            break;
        case MULT:
            automate.decalage(new E5, symbole);
            break;
        case CLOSEPAR:
            Expr * s1 = automate.pileSymboles.pop();
            automate.pileSymboles.pop();
            Expr * s2 = automate.pileSymboles.pop();
            Symbole s_gauche = new ExprPlus(s1, s2);
            automate.reduction(3, s_gauche);
            break;
        case FIN:
            Expr * s1 = automate.pileSymboles.pop();
            automate.pileSymboles.pop();
            Expr * s2 = automate.pileSymboles.pop();
            Symbole s_gauche = new ExprPlus(s1, s2);
            automate.reduction(3, s_gauche);
            break;
        default:
            //err
    }
}

void E8::transition(Automate & automate, Symbole * symbole){
    switch(*symbole){
        case PLUS:
            Expr * s1 = automate.pileSymboles.pop();
            automate.pileSymboles.pop();
            Expr * s2 = automate.pileSymboles.pop();
            Symbole s_gauche = new ExprMult(s1, s2);
            automate.reduction(3, s_gauche);
            break;
        case MULT:
            Expr * s1 = automate.pileSymboles.pop();
            automate.pileSymboles.pop();
            Expr * s2 = automate.pileSymboles.pop();
            Symbole s_gauche = new ExprMult(s1, s2);
            automate.reduction(3, s_gauche);
            break;
        case CLOSEPAR:
            Expr * s1 = automate.pileSymboles.pop();
            automate.pileSymboles.pop();
            Expr * s2 = automate.pileSymboles.pop();
            Symbole s_gauche = new ExprMult(s1, s2);
            automate.reduction(3, s_gauche);
            break;
        case FIN:
            Expr * s1 = automate.pileSymboles.pop();
            automate.pileSymboles.pop();
            Expr * s2 = automate.pileSymboles.pop();
            Symbole s_gauche = new ExprMult(s1, s2);
            automate.reduction(3, s_gauche);
            break;
        default:
            //err
    }
}

void E9::transition(Automate & automate, Symbole * symbole){
    switch(*symbole){
        case PLUS:
            automate.pileSymboles.pop();
            Expr * s = automate.pileSymboles.pop();
            automate.pileSymboles.pop();
            automate.reduction(3, *s);
            break;
        case MULT:
            automate.pileSymboles.pop();
            Expr * s = automate.pileSymboles.pop();
            automate.pileSymboles.pop();
            automate.reduction(3, *s);
            break;
        case CLOSEPAR:
            automate.pileSymboles.pop();
            Expr * s = automate.pileSymboles.pop();
            automate.pileSymboles.pop();
            automate.reduction(3, *s);
            break;
        case FIN:
            automate.pileSymboles.pop();
            Expr * s = automate.pileSymboles.pop();
            automate.pileSymboles.pop();
            automate.reduction(3, *s);
            break;
        default:
            //err
    }
}