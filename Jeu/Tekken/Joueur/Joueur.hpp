#ifndef JOUEUR_HPP
#define JOUEUR_HPP

class Joueur {
    private:
        int vie;
    public:
        Joueur();
        ~Joueur();
        void setVie(int v);
        void coutDePied();
        void coutDeTete();
        void percut();
        void quick();
        bool isKO();

        void display();
};

#endif