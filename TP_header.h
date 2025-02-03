#ifndef TP_header



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*---------------------------- declaration des structures ----------------------------------------------------------------*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


typedef struct Clients
{
    char nom[100];
    char guichet;
    int ticket;
}Clients;
typedef struct Maillon
{
    Clients client;
    struct Maillon *suiv;
} Maillon;
typedef struct File
{
    struct Maillon *tete, *queue;
}File;
typedef struct Guichet
{
    char nom;
    File file;
    struct Guichet *suiv;
}Guichet;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/*---------------------------- fin de la declaration des structures ----------------------------------------------------------------*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/*-------------------------------------------debut de la declaration des procedures---------------------------------------------------------------*/



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    //Pour l'affichage:

void affichage_interface();
void affichage_entete ();

    //Fin des procedures d'affichage.

    //Procedures standards des machines abtraites :

//Procedure qui alloue un espace memoire pour un maillon client.
void allouer (Maillon **p);

//Procedure pour creer une file d'attente.
void creerfile(File *pf);

//Procedure pour la cr�ation du centre : allocation des guichets, cr�ation des files d'attente.
void alloc_guichets(Guichet **acc, int *nb_gui);

//Fonction qui retourne 1 si la file est vide.
int filevide(File f);

//Fonction qui retourne 1 si la file est pleine.
int filepleine(File f);

//Fonction qui retourne le nombre de clients dans la file d'attente.
int Longueur(File *pf);

//Procedure qui permet de dupliquer le maillon p en q.
void duplicate(Maillon *p, Maillon ** q);

    // Fin des procedures standards des machines abtraites.


    //Procedures de manipulation des clients:

//Fonction qui retourne 1 si le client a �t� enfil� avec succ�s.
int enfiler_client(Maillon **p, Guichet *gui);

//Fonction qui retourne 1 si le client a �t� enfil� avec succ�s.
int defiler_client(Maillon **p, Guichet * gui);

//Fonction qui retourne 1 si le client a �t� inser� � la propre position selon son num�ro de ticket.
int insert_client(Maillon **p, Guichet * gui);

//Fonction qui retourne 1 si le client ayant un certain num�ro de ticket a �t� supprim� de la file.
int supprimer_client(int ticket, Guichet * gui);

//Procedure pour ajouter un client au centre.
void ajout_client(Guichet *acc, int *ticket, int nb_gui);

//Fonction qui retourne 1 si le premier client d'une file est redirectionn� vers une autre file avec succ�s.
int redirect_client(Guichet *acc,Guichet **gui, Guichet **gui_red);

//Procedure de l'option b.r�ception d'un client.
void reception_client (Guichet *acc, Guichet *gui, int nb_gui);

    //Fin des procedures de manipulation des clients.

    //Procedures de manipulation des guichets:

//Fonction qui retourne un pointeur vers un guichet selon son nom.
Guichet * acc_gui (Guichet *acc, char G, int nb_gui);

//Procedure qui permet de choisir un guichet pour une certaine op�ration.
void choix_gui(Guichet *acc, Guichet **gui, int nb_gui, int fonct, char dest, int num_red);

//Fonction qui retourne 1 si le nom du guichet d'un client du guichet d'accueil est modifi� au nom du guichet du maillon p avec succ�s.
int changegui_acc(Guichet * acc, Maillon *p);

//Fonction qui retourne le nombre de guichets vides.
int nbgui_vide(Guichet * acc);

//Fonction qui retourne 1 si les num�ros des guichets ont �t� reinitialis� avec succ�s.
int reinit_ticket (Guichet *acc);

//Procedure des op�rations en vrac sur les files.
void operations (Guichet * acc, int nb_gui);

    // Fin des procedures de manipulation des guichets.

    //Procedures de manipulation des files

//Procedure qui permet d'afficher une file d'attente d'un guichet.
void afficher_file (Guichet*gui);

//Procedure qui permet d'afficher les files de tous les guichets du centre.
void afficher_global(Guichet * acc);

//Fonction qui retourne 1 si 2 files sont fusionn�es avec succ�s.
int fusion_files(Guichet *acc ,Guichet * gui_dest, Guichet * gui);

//Procedure de redirection d'une file d'attente d'un guichet sur 'n' autres guichets.
void redirect_file(Guichet * acc, Guichet * gui, int n, int nb_gui, int nb_vide, char noms []);

//Fonction qui retourne 1 si les files des tous les guichets sont r��quilibr�es.
int reequilibrer_files(Guichet *acc, int nb_gui);

    // Fin des procedures de manipulation des files.
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



/*---------------------------------------------fin de la declaration des procedures---------------------------------------------------------------*/



//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#endif
