#include<iostream>
#include<vector>

using namespace std;

class Terrain
{
private:
    vector<vector<int>> terrain;
public:
    Terrain(); 
    //place la piece du joueur dans le terrain
    //donne la valeur de la pieces dans une case de coordonne x,y
    void deplacerLaPiece(int joueurChar,int x,int y);
    int getpiece(int x,int y);

    
    //affiche le terrain en numero (0 et 1 et 2)
    void affiche();
    void refresh_terrain(int move[][2],int joueur);
};