#include "automate.h"

using namespace std;

class Etat{ // abstarite
    public:
        Etat() { }
        ~Etat() { }

        void transition(Automate & automate, Symbole * liste_symboles) = 0;
}

class E0 : public Etat{
    public:
        void transition(Automate & automate, Symbole * liste_symboles);
}

class E1 : public Etat{
    public:
        void transition(Automate & automate, Symbole * liste_symboles);
}

class E2 : public Etat{
    public:
        void transition(Automate & automate, Symbole * liste_symboles);
}

class E3 : public Etat{
    public:
        void transition(Automate & automate, Symbole * liste_symboles);
}

class E4 : public Etat{
    public:
        void transition(Automate & automate, Symbole * liste_symboles);
}

class E5 : public Etat{
    public:
        void transition(Automate & automate, Symbole * liste_symboles);
}

class E6 : public Etat{
    public:
        void transition(Automate & automate, Symbole * liste_symboles);
}

class E7 : public Etat{
    public:
        void transition(Automate & automate, Symbole * liste_symboles);
}

class E8 : public Etat{
    public:
        void transition(Automate & automate, Symbole * liste_symboles);
}

class E9 : public Etat{
    public:
        void transition(Automate & automate, Symbole * liste_symboles);
}