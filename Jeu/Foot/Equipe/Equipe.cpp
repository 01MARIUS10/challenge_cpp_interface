#include <iostream>
#include <cstdlib>
#include <ctime>
#include "./Equipe.hpp"

using namespace std;

Equipe::Equipe(){
    tirPossible=7;
    nbrBut=0;
    tirFait=0;
}

Equipe::~Equipe(){
    
}
int Equipe::getTirFait(){
    return tirFait;
}

void Equipe::tir(int direction,int goalDirection){
    tirPossible-=1;
    tirFait+=1;
    cout<<endl;
    
    if(direction==goalDirection){
        cout<<endl<<"GOAAAAALLLLLLLL.............."<<endl;
        nbrBut+=1;
    }
}
bool Equipe::isWin(){
    return nbrBut>=5? true:false;   
}
bool Equipe::isLose(){
    return (tirPossible<=0 && nbrBut<5)? true:false;   
}

void Equipe::display(){
    cout<<"but = "<<nbrBut<<endl;
    cout<<"nbr tir restant = "<<tirPossible<<endl;
}
