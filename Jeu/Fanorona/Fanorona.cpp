#include "Fanorona.hpp"

Fanorona::Fanorona()
{
    cout<<endl<<"_________________________________________________________________________________________"<<endl;
    cout<<endl<<"_________________________________________________________________________________________"<<endl;
    cout<<endl<<"sachant que les ligne et colonne sont de 1 a 3 "<<endl;
          cout<<"NOTEZ BIEN ! , l'index 0 est invalide"<<endl<<endl;
          cout<<"Bon jeux :xD  "<<endl<<endl;
          cout<<"Demarer!!!!!!"<<endl;

    cout<<endl<<"____________________________________"<<endl<<endl;
          cout<<" ||\t\t\t\t||"<<endl;
          cout<<" ||\t\t\t\t||"<<endl;
          cout<<"\t||FANORONA TELO||"<<endl;
          cout<<" ||\t\t\t\t||"<<endl;
          cout<<" ||\t\t\t\t||"<<endl;
    cout<<"____________________________________"<<endl<<endl;

    play=true;
    initDeplacementCoordone();
        
    }
void Fanorona::initDeplacementCoordone()
{
    deplacementCoordone [0][0]=-1;
    deplacementCoordone [0][1]=-1;
    deplacementCoordone [1][0]=-1;
    deplacementCoordone [1][1]=-1;
}
Joueur Fanorona::J1_()
{
    return J1;
}
Joueur Fanorona::J2_()
{
    return J2;
}
Terrain Fanorona::terrain_()
{
    return terrain;
}
int Fanorona::switch_joueur(int joueur)
{
    if(joueur==1)
    {
        return 2;
    }
    else if(joueur==2)
    {
        return 1;
    }
    else
        cout<<"error switch joueur,joueur different de 1 et 2"<<endl;
    return -1;
}
int Fanorona::inputLine()
{
    int x(-1);
    cout<<"ligne\t: ";
    cin>>x;
    return x;
}
int Fanorona::inputColumn()
{
    int y(-1);
    cout<<"colonne\t: ";
    cin>>y;
    return y;
}

void Fanorona::restart(){
    cout<<endl <<"RESTARTING.................."<<endl;
    start();
}
int Fanorona::quit(){
    cout<<endl <<"EXITING.................."<<endl;
    exit(-1);
}

//-----------------------------------------------------------
void Fanorona::start()
{
    int vainceur(0);
    play=!placer();
    if(play)
    {
        vainceur=deplacer();
        cout<<" PARTI FINI : "<<endl;
        cout<<"le Joueur "<<vainceur<<" a gagner la partie"<<endl;
    }
}
//step1 - remplir le terrain piece par piece/return play
bool Fanorona::placer()
{
    int x(-1),y(-1);
    int compteur1(0);
    int compteur2(0);
    for (int numero_piece=0;numero_piece<3;numero_piece++)//mettre en places les trois pieces 
    {
        for(int joueur=1;joueur<=2;joueur++) //le tour de jeu switch entre les deux joueurs 
        {
            //saisi des coordonnees
            cout<<"entrer le "<<numero_piece+1<<"eme piece du JOUEUR"<<joueur<<"! "<<endl;
            x=inputLine();
            y=inputColumn();

            //nuance index realite et programme
            x--;
            y--;

            //verifier la compatibilites des valeus saisi par les joueurs 
            while( 
                (!terrain.getpiece(x,y)==0) || 
                (x<0) || 
                (x>2) || 
                (y<0) || 
                (y>2)
            )
            {
                if(
                    (x<0) || 
                    (x>2 )|| 
                    (y<0) || 
                    (y>2)
                )
                {
                    cout<<"case inexistant,reesayer a nouveau"<<endl;
                }
                else if(terrain.getpiece(x,y)!=0)/////////////////////////////////////////////////
                {
                    cout<<"error ,place deja engage ,retapez a nouveau "<<endl;
                }

                //en cas d'erreur(incompatibilite des valeurs) le programme redemande au joueur de saisir de nouveau
                x=inputLine();
                y=inputColumn();
                cout<<endl;

                //nuance index realite et programme
                x--;
                y--;
            }
                
            //les coordonnes filtrée sont entrer dans le terrain
            terrain.deplacerLaPiece(joueur,x,y);

            //puis dans les donnes des joueurs ,le tableau pieces 3*2
            if(joueur==1)
            {
                J1.deplacerPiece(compteur1,x,y);
                compteur1++;
            }
            else if(joueur==2)
            {
                J2.deplacerPiece(compteur2,x,y);
                compteur2++;
            }

            //afficher le tableau apres chaque pieces placeés  
            terrain.affiche();

            //control si le joueur a gagner
            if(numero_piece==2)
            {
                play=is_win(joueur);
                if(play)
                {
                    cout<<"PARTI FINI :"<<endl;
                    cout<<"le joueur"<<joueur<<" a gagner la partie"<<endl;
                    return play;
                }
            }
        }
    }
    return false;
}
   
//etape 2 deplacement des pieces
int Fanorona::deplacer()
{
    cout<<endl<<"les pieces sont mis en place, deplacez maintenant"<<endl;
    int joueur(1);
    while(play)
    {
            
        cout<<"JOUEUR "<<joueur<<" :";

            //deplacement de chaque joueur
            play=deplacerPiece(joueur);
            //uploader les valeurs du terrain
            terrain.refresh_terrain(deplacementCoordone,joueur);
            //afficher le tableau apres chaque pieces placeés  
            terrain.affiche();

            //switcher les tour des joueurs
            joueur=switch_joueur(joueur);
            cout<<"--------------------------------"<<endl<<endl;
        }
        return joueur;
    }
//regarde si la partie est fini
bool Fanorona::deplacerPiece(int joueur)//---------------------------->>>void deplacer
    {
        int numero_piece;
        bool refresh(true);
        //demande ,analyse les coordonnees saisi
        // et stock dans deplacementCoordone[0]
        initDeplacementCoordone();
        while(refresh)
        {
            getInputDeplacement(joueur);
            refresh=deplacerPieceJoueur(joueur);
        }
        
        //mettre a jour les coordonnées de la pieces deplacer
        if(joueur==1)
        {
            numero_piece=J1.getNumeroPiece(deplacementCoordone[0][0],deplacementCoordone[0][1]);
            J1.deplacerPiece(numero_piece,(deplacementCoordone[1][0]),deplacementCoordone[1][1]);
        }
        else if(joueur==2)
        {
            numero_piece=J2.getNumeroPiece(deplacementCoordone[0][0],deplacementCoordone[0][1]);
            J2.deplacerPiece(numero_piece,(deplacementCoordone[1][0]),deplacementCoordone[1][1]);
        }
        
        return !is_win(joueur);
    }
//verifie si le joueur a gagnée
bool Fanorona::is_win(int joueur)
    {
        if(joueur==1)
        {
            return J1.isAligner();
        }
        else if(joueur==2)
        {
            return J2.isAligner();
        }

        return false;
    }
    
//prend la piece(x,y) a deplacer etla stocke dans deplacementCoordone[joueur] 
void Fanorona::getInputDeplacement(int joueur)
    {
        //demmander la piece a bouger
        cout<<endl<<endl;
        cout<<"Deplacer quel pieces(tapez 0,0 pour quitter)(tapez 9,9 pour restartez) :"<<endl;
        int x=inputLine();
        int y=inputColumn();

        if(x==0 && y==0) quit();
        if(x==9 && y==9) restart();

        //nuance index realite et programme
        x--;
        y--;

        //verifiere si la case appartient au joueur
        while(  (terrain.getpiece(x,y)!=joueur) || (x<0) || (x>2)|| (y<0) || (y>2)  )
        {
            if((x<0) || (x>2 )|| (y<0) || (y>2))
            {
                cout<<"ERREUR :case inexistant,reesayer a nouveau"<<endl;
            }
            else if(terrain.getpiece(x,y)!=0)
            {
                cout<<"ERREUR :piecesn introuvable ,retapez a nouveau "<<endl;
            }
            //en cas d'erreur(incompatibilite des valeurs) le programme redemande au joueur de saisir de nouveau
            x=inputLine();
            y=inputColumn();
            cout<<endl;

            //nuance index realite et programme
            x--;
            y--;

        }
        //apres verification .........
        joueur--;
        deplacementCoordone[0][0]=x;//on stock l'abscisse
        deplacementCoordone[0][1]=y;//on stock l'ordonne*
        /* piece a bouger OK */
    }
//get la place a deplacer la piece dans deplacementCoordone[0]
bool Fanorona::deplacerPieceJoueur(int joueur)
    {
        //cette booleen reinitialise le sais de la piece a deplacer apres 3essai
        int compteur_erreur(3);
        int inputxIndex(-1) , inputyIndex(-1);
        bool is_legal_move(false);

        while(!is_legal_move)
        {
            cout<<"Deplacer ou :"<<endl;
            inputxIndex=inputLine();
            inputyIndex=inputColumn();
            cout<<endl;

            inputxIndex--;
            inputyIndex--;

            while( 
                ((terrain.getpiece(inputxIndex,inputyIndex)!=0)) || 
                (inputxIndex<0) || 
                (inputxIndex>2) || 
                (inputyIndex<0) || 
                (inputyIndex>2)
            )
            {
                if(
                    (inputxIndex<0) || 
                    (inputxIndex>2 )|| 
                    (inputyIndex<0) || 
                    (inputyIndex>2)
                )
                {
                    cout<<"ERREUR :case inexistant,reesayer a nouveau"<<endl;
                }
                else if(terrain.getpiece(inputxIndex,inputyIndex)!=0)
                {
                    cout<<"ERREUR :place deja prise ,retapez a nouveau "<<endl;
                }
                //en cas d'erreur(incompatibilite des valeurs) le programme redemande au joueur de saisir de nouveau
                inputxIndex=inputLine();
                inputyIndex=inputColumn();
                cout<<endl;

                inputxIndex--;
                inputyIndex--;
                //compter les nbr d'erreur sur la place choisi a mettre 
                //apres 3 essai on reprend une nouvelle pieces a deplacer
                compteur_erreur--;
                if(compteur_erreur==0)
                    return true;

            }
            is_legal_move=etudeDeDeplacement(inputxIndex,inputyIndex);
        }
        
        //apres verification .........
        joueur--;
         
        return false;//les erreur n'a pas depasser le compteur
    }
//est ce que le deplacement est legal
bool Fanorona::etudeDeDeplacement(int x,int y)//--------------------->>>deplacerPieceJoueur
    {
        //Aucun mouvement
        if(deplacementCoordone[0][0]==x && deplacementCoordone[0][1]==y)
        {
            cout<<"ERREUR :vous n'avez effectuer aucun deplacement"<<endl<<endl;
            return false;
        }
        //trier le depl diagonal pres non authoriser
        if( ( ((deplacementCoordone[0][0]==1)||(deplacementCoordone[0][1]==1)) && ((deplacementCoordone[0][0]!=deplacementCoordone[0][1])) )   &&   ( ((x==1)||(y==1)) && (x!=y)) )
        {
            cout<<"ERREUR :deplacement diagonal non authoriser"<<endl<<endl;
            return false;
        }
        //tout mouvement qui saute des casses
        if( ((deplacementCoordone[0][0]-x==-2)||(deplacementCoordone[0][0]-x==2)) && ((deplacementCoordone[0][1]-y==-2)||(deplacementCoordone[0][1]-y==2)))
        {
            cout<<"ERREUR :le saut de case est interdit "<<endl;
            return false;
        }
        deplacementCoordone[1][0]=x;
        deplacementCoordone[1][1]=y;
        return true;
    }

