#include<iostream>
#include<vector>

using namespace std;


class Joueur
{
private:
    vector<vector<int>> pieces;
public:
    Joueur(); 
    void deplacerPiece(int numero_piece,int x,int y) ;
    int getNumeroPiece(int x,int y);
    int getXPiece(int numero_piece);
    int getYPiece(int numero_piece);

    void debug_tableau();
    bool isAligner();
    
};
