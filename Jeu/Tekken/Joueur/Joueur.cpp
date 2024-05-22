#include <iostream>
#include "./Joueur.hpp"

using namespace std;

Joueur::Joueur(){
    vie=20;
}

Joueur::~Joueur(){
    
}

void Joueur::setVie(int v){
    vie=v;
}
void Joueur::coutDePied(){
    cout<<"  |"<<vie<<endl;
    vie-=2;
    cout<<"  |"<<vie<<endl;
}
void Joueur::coutDeTete(){
    vie-=1;
}
void Joueur::percut(){
    vie-=4;
}
void Joueur::quick(){
    vie-=3;
}
bool Joueur::isKO(){
    return vie>=0 ? false:true ;
}
void Joueur::display(){
    cout<<"vie = "<<vie<<endl;;
}