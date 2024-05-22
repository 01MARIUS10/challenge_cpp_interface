#include "./Equipe/Equipe.hpp"
#include "../Jeu.hpp"

class Foot : public Jeu{
    private :
        Equipe E1;
    public :
        Foot();
        ~Foot();
        bool isStart;
        int getChoice(int i);
        int randomGoalKeeper();
        int executeChoice(int choice,Equipe &j);

        void start() ;
        void restart() ;
        int quit() ;

};
