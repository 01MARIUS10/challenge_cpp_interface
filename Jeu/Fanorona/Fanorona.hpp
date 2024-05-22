#include<iostream>

#include "./Joueur/Joueur.hpp"
#include "./Terrain/Terrain.hpp"
#include "./../Jeu.hpp"

using namespace std;

class Fanorona : public Jeu
{
private:
    bool play;
    Joueur J1;
    Joueur J2;
    Terrain terrain;

    int deplacementCoordone[2][2];
    void initDeplacementCoordone();

    int inputLine();
    int inputColumn();
    void getInputDeplacement(int joueur);

public:
    Fanorona();
    void start() override;
    void restart() override;
    int quit() override;
    Joueur J1_();
    Joueur J2_();
    Terrain terrain_();
    int switch_joueur(int joueur);

    bool placer();
    int deplacer();

    bool is_win(int joueur);

    bool deplacerPiece(int joueur);
    bool deplacerPieceJoueur(int joueur);
    bool etudeDeDeplacement(int x,int y);
};
