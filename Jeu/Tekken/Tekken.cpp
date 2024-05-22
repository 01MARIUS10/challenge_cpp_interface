#include "./Tekken.hpp"
#include "./Joueur/Joueur.hpp"
#include <iostream>
using namespace std;

Tekken::Tekken(){

}
Tekken::~Tekken(){
    
}

int Tekken::getChoice(){
    int choice(0);
    bool isNotIn(true);
    while(isNotIn){
        cout<< "==== | MENU | ===="<<endl;
        cout<<" 1. to coutDePied(-2)"<<endl;
        cout<<" 2. to coutDeTete(-1)"<<endl;
        cout<<" 3. to percut(-4)"<<endl;
        cout<<" 4. to quick(-3)"<<endl;;
        cout<<" 0. to exit"<<endl;
        cout<< "choice: ";
        cin>>choice;
        if(choice<0 && choice>4){
            cout<<endl<<"erreur , choix inexistant , reesayer"<<endl;
        }
        else{
            isNotIn = false;
        }
    }
    return choice;
}
int Tekken::executeChoice(int choice , Joueur &j){
    switch(choice) {
        case 1:
            cout<<"cout de pied"<<endl;
            j.coutDePied();
            break;
        case 2:
            j.coutDeTete();
            break;
        case 3:
            j.percut();
            break;
        case 4:
            j.quick();
            break;
        case 0:
            cout<<endl<<"BYE........"<<endl;
            exit(1);
            break;
        default:
            cout << "Choix invalide. Veuillez choisir entre 0 et 4."<<endl;
            break;
    }
    return 1;
}

void Tekken::start(){
    int tour(1);
    int choice(0);

    while(true){
        if(tour==1){
            cout<<"Au tour de Joueur 1"<<endl;
            choice = getChoice();
            executeChoice(choice,J2);
        }

        if(tour==2){
            cout<<endl<<"Au tour de Joueur 2"<<endl;
            choice = getChoice();
            executeChoice(choice,J1);
        }

        J1.display();
        J2.display();

        if(J1.isKO()){
            cout<<"Le gagnant est  Joueur 2"<<endl;
            quit();
        }
        if(J2.isKO()){
            cout<<"Le gagnant est  Joueur 1"<<endl;
            quit();
        }
        tour = (tour==1)? 2:1;
    }

}

void Tekken::restart(){
    cout<<endl <<"RESTARTING.................."<<endl;
    start();
}
int Tekken::quit(){
    cout<<endl <<"EXITING.................."<<endl;
    exit(-1);
}
