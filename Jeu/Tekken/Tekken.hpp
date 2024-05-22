#include "./Joueur/Joueur.hpp"
#include "../Jeu.hpp"

class Tekken : public Jeu{
    private :
        Joueur J1;
        Joueur J2;
    public :
        Tekken();
        ~Tekken();
        bool isStart;
        int getChoice();
        int executeChoice(int choice,Joueur &j);

        void start() ;
        void restart() ;
        int quit() ;

};