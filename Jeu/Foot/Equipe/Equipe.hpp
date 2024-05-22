#ifndef EQUIPE_HPP
#define EQUIPE_HPP

class Equipe {
    private:
        int tirPossible;
        int tirFait;
        int nbrBut;
    public:
        Equipe();
        ~Equipe();

        //1 if gauche
        //2 if droite
        void tir(int direction,int goalDirection);
        int getTirFait();

        void display();

        bool isLose();
        bool isWin();


        void start() ;
        void restart() ;
        int quit() ;
};

#endif