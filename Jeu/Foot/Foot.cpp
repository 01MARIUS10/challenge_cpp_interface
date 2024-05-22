#include "./Foot.hpp"
#include "./Equipe/Equipe.hpp"
#include <iostream>
using namespace std;

Foot::Foot(){

}
Foot::~Foot(){
    
}

int Foot::getChoice(int i){
    int choice(0);
    bool isNotIn(true);
    while(isNotIn){
        cout<< "==== | FAITE LE TIR (joueur "<<i+11<<") | ===="<<endl;
        cout<<" 1. tirer a gauche"<<endl;
        cout<<" 2. tirer a droite"<<endl;
        cout<<" 0. to exit"<<endl;
        cout<< "choice: ";
        cin>>choice;

        if(choice==0) quit();

        if(choice<0 && choice>2){
            cout<<endl<<"erreur , choix inexistant , reesayer"<<endl;
        }
        else{
            isNotIn = false;
        }
    }
    return choice;
}

int Foot::randomGoalKeeper(){
    srand(time(NULL));
    return (rand() > (RAND_MAX / 2))? 1:2;
}
int Foot::executeChoice(int choice , Equipe &j){
    int goalDIrection(0);

    goalDIrection = randomGoalKeeper();
    j.tir(choice,goalDIrection);
    return 1;
}

void Foot::start(){
    int choice(0);

    while(true){
        // cout<<endl<<"Au tour de Joueur 1"<<endl<<endl;
        choice = getChoice(E1.getTirFait());
        executeChoice(choice,E1);

        E1.display();

        if(E1.isWin()){
            cout<<"L'equipe a gagner"<<endl;
            quit();
        }
        if(E1.isLose()){
            cout<<"L'equipe a perdu"<<endl;
            quit();
        }
    }

}

void Foot::restart(){
    cout<<endl <<"RESTARTING.................."<<endl;
    start();
}
int Foot::quit(){
    cout<<endl <<"EXITING.................."<<endl;
    exit(-1);
}
