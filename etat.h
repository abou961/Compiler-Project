#include "automate.h"
#include <string>

using namespace std;

class Etat{ // abstraite
    public:
        Etat(string name) : name(name) { }
        ~Etat() { }
        virtual bool transition(Automate & automate, Symbole * liste_symboles) = 0;
    
    protected:
        string name;
};

class E0 : public Etat{
    public:
        E0() : Etat("E0") {}
        bool transition(Automate & automate, Symbole * liste_symboles);
};

class E1 : public Etat{
    public:
        E1() : Etat("E1") {}
        bool transition(Automate & automate, Symbole * liste_symboles);
};

class E2 : public Etat{
    public:
        E2() : Etat("E2") {}
        bool transition(Automate & automate, Symbole * liste_symboles);
};

class E3 : public Etat{
    public:
        E3() : Etat("E3") {}
        bool transition(Automate & automate, Symbole * liste_symboles);
};

class E4 : public Etat{
    public:
        E4() : Etat("E4") {}
        bool transition(Automate & automate, Symbole * liste_symboles);
};

class E5 : public Etat{
    public:
        E5() : Etat("E5") {}
        bool transition(Automate & automate, Symbole * liste_symboles);
};

class E6 : public Etat{
    public:
        E6() : Etat("E6") {}
        bool transition(Automate & automate, Symbole * liste_symboles);
};

class E7 : public Etat{
    public:
        E7() : Etat("E7") {}
        bool transition(Automate & automate, Symbole * liste_symboles);
};

class E8 : public Etat{
    public:
        E8() : Etat("E8") {}
        bool transition(Automate & automate, Symbole * liste_symboles);
};

class E9 : public Etat{
    public:
        E9() : Etat("E9") {}
        bool transition(Automate & automate, Symbole * liste_symboles);
};