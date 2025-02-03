#include <stdio.h>
#include <stdlib.h>/* pour system() / malloc / free */
#include <string.h> /*pour strlen*/
#include <ctype.h> /* pour toupper() */
#include <conio.h> /* pour getch() */
#include "TP_header.h"


/*-------------------------------------------------Declaration des fonction------------------------------------------------------------------------------*/
void affichage_interface()
{
    printf("\n");
    int delay = 50;
    printf("\n\n");
    printf("\t\t\t\t      @@@@@@@@@@@@@        @@@@@@@@@@@@@    ");Sleep(delay);
    printf("\033[0;34m&&&&&&&&&&    \n");Sleep(delay);
    printf("\033[0m");
    printf("\t\t\t\t    @@@@@@@@@@@@@@@@      @@@@@@@@@@@@@@@   ");Sleep(delay);
    printf("\033[0;34m&&&&&&&&&&    \n");Sleep(delay);
    printf("\033[0m");
    printf("\t\t\t\t   @@@@@@@@  @@@@@@@@    @@@@@@@  @@@@@@@   ");Sleep(delay);
    printf("\033[0;34m&&&&&&&&&&    \n");Sleep(delay);
    printf("\033[0m");
    printf("\t\t\t\t   @@@@@@@@  @@@@@@@@    @@@@@@@  @@@@@@@    ");Sleep(delay);
    printf("\033[0;34m&&&&&&&&&&   \n");Sleep(delay);
    printf("\033[0m");
    printf("\t\t\t\t   @@@@@@@@  @@@@@@@@    @@@@@@@  @@@@@@@     ");Sleep(delay);
    printf("\033[0;34m&&&&&&&&&&   \n");Sleep(delay);
    printf("\033[0m");
    printf("\t\t\t\t   @@@@@@@@  @@@@@@@@    @@@@@@@  @@@@@@@    @@@@@@@@     \n");Sleep(delay);
    printf("\t\t\t\t   @@@@@@@@  @@@@@@@@    @@@@@@@  @@@@@@@    @@@@@@@@     \n");Sleep(delay);
    printf("\t\t\t\t   @@@@@@@@  @@@@@@@@    @@@@@@@             @@@@@@@@     \n");Sleep(delay);
    printf("\t\t\t\t   @@@@@@@@  @@@@@@@@    @@@@@@@@@@@@@@@@    @@@@@@@@     \n");Sleep(delay);
    printf("\t\t\t\t   @@@@@@@@@@@@@@@@@@    @@@@@@@@@@@@@@@@    @@@@@@@@     \n");Sleep(delay);
    printf("\t\t\t\t   @@@@@@@@                       @@@@@@@    @@@@@@@@     \n");Sleep(delay);
    printf("\t\t\t\t   @@@@@@@@  @@@@@@@@    @@@@@@@  @@@@@@@    @@@@@@@@     \n");Sleep(delay);
    printf("\t\t\t\t   @@@@@@@@  @@@@@@@@    @@@@@@@  @@@@@@@    @@@@@@@@     \n");Sleep(delay);
    printf("\t\t\t\t   @@@@@@@@  @@@@@@@@    @@@@@@@  @@@@@@@    @@@@@@@@     \n");Sleep(delay);
    printf("\t\t\t\t   @@@@@@@@  @@@@@@@@    @@@@@@@  @@@@@@@    @@@@@@@@     \n");Sleep(delay);
    printf("\t\t\t\t   @@@@@@@@  @@@@@@@@    @@@@@@@  @@@@@@@    @@@@@@@@     \n");Sleep(delay);
    printf("\t\t\t\t    @@@@@@@  @@@@@@@@    @@@@@@@  @@@@@@@    @@@@@@@@     \n");Sleep(delay);
    printf("\t\t\t\t     @@@@@@@@@@@@@@@      @@@@@@@@@@@@@@     @@@@@@@@     \n");Sleep(delay);
   ;

    printf("\033[4;34m\n\t\t\t\t\t\t\tTP 1  ALSDD");

    printf("\n\t\t\t\t\t");
  printf("\033[0m");
  printf("\n\t\t\t\t\t Ce programme prend des entrees du clavier.\n");
    printf("\t\t\t\t    Veuillez utiliser les touches flechees pour naviguer.\n");
    printf("\033[0;31m\n\t\t\t\t\tAppuyez sur une touche pour commencer ... ");
    printf("\033[0m");
    getch();
}
void affichage_entete ()
{
        system("cls");
        printf("\n   |===================================================================================================================|\n");
        printf("   |                                   Ecole National Superieur d Informatique                                         |\n");
        printf("   |                             Algorithmique et Structures des Donnees Dynamiques                                    |\n");
        printf("   |                                                                                                                   |\n");
        printf("   |Realise par :                          Touat Malak & Fellahi Abderraouf                       | 1CP01 |   2022/2023|\n");
        printf("   |===================================================================================================================|\n");
        printf("   |                                                                                                                   |\n");
        printf("   | TP:1 ALSDD                             SIMULATEUR DE FILES D ATTENTES                                             |\n");
        printf("   |                                                                                                                   |\n");
        printf("   |===================================================================================================================|\n\n");

}


//Procedure qui alloue un espace memoire pour un maillon client.
void allouer (Maillon **p)
{
    *p =malloc(sizeof(Maillon));
}

//Procedure pour creer une file d'attente.
void creerfile(File *pf)
{
    pf-> tete = NULL;
    pf-> queue = NULL;
}

//Procedure pour la création du centre : allocation des guichets, création des files d'attente.
void alloc_guichets(Guichet **acc, int *nb_gui)
{
    repeat:
        printf("\n\n\t\t-> Preciser le nombre de guichets: ");
        scanf("%d", nb_gui);                //nb_gui étant le nombre des guichets du centre.
        if((*nb_gui) < 1) {printf("\n\t\t\tLe nombre de guichets doit etre superieure ou egal a 1. Veuillez reessayer."); fflush(stdin); goto repeat;}

    (*acc) = malloc(sizeof(Guichet));   //acc représente le guichet d'accueil, celui qui contient tous les clients presents dans le centre.
    creerfile(&((*acc)->file));
    Guichet *curr;
    Guichet *prec = *acc;
    printf("\n\n\t\t-> Il y a %d guichets:\n\t\t", *nb_gui);
    int new_line = 1;
    for (int i =0; i <(*nb_gui); i++)
    {
        curr = malloc(sizeof(Guichet));         //allocation du guichet.
        creerfile(&(curr->file));               //creation de la file.
        prec->suiv = curr;
        curr->nom = (char)(i+65);               //pour affecter le nom du guicheton utilise le code ASCII des lettres commençant par  A = 65.
        curr->suiv = NULL;
        prec = curr;
        if((new_line % 5) == 0){printf("\n\n\t\t");}
        new_line++;
        printf("\t-%c",curr->nom);
    }
    getch();                   //attendre la saisie de l'utilisateur.

}

//Fonction qui retourne 1 si la file est vide.
int filevide(File f)
{
    return (f.tete == NULL);
}

//Fonction qui retourne 1 si la file est pleine.
int filepleine(File f)
{
    return 0;
}

//Fonction qui retourne le nombre de clients dans la file d'attente.
int Longueur(File *pf)
{
    int i=0;
    Maillon *curr = pf->tete;
    while(curr != NULL)
    {
        i++;
        curr = curr->suiv;
    }
return i;
}

//Fonction qui retourne 1 si le client a été enfilé avec succès.
int enfiler_client(Maillon **p, Guichet *gui)
{
    File *pf = &(gui -> file);
    if (( filepleine(*pf) )||( (*p) == NULL )) {return 0;}  //retourne 0 si la file est pleine ou qu'il y a eu un problème d'allocation de p.
    if ( pf->queue != NULL )    //si la file n'est pas vide
    {
        pf->queue->suiv = (*p);
        pf->queue = (*p);
    }
    else
    {
        pf->tete = (*p);
        pf->queue = (*p);
    }
    (*p)->suiv = NULL;
return 1;
}

//Fonction qui retourne 1 si le client a été enfilé avec succès.
int defiler_client(Maillon **p, Guichet * gui)
 {
    File *pf = &(gui -> file);
    if ( filevide(*pf) ) return 0;  //pas de défilement si la file est vide
    (*p)=pf->tete;
    pf->tete = pf->tete->suiv;
    if ( pf->tete == NULL ) // si la file devient vide
    {
        pf->queue = NULL;
    }
    return 1;
}

//Fonction qui retourne 1 si le client a été inseré à la propre position selon son numéro de ticket.
int insert_client(Maillon **p, Guichet * gui)
{
    File *pf = &(gui -> file);
    if ((filepleine(*pf))||((*p) == NULL)) {return 0;}//retourne 0 si la file est pleine ou qu'il y a eu un problème d'allocation de p.
    Maillon *curr = pf->tete;
    Maillon *prec = NULL;
    while ((curr != NULL) && (curr->client.ticket < (*p)->client.ticket))   //parcourir la file en comparant le num de ticket de p et celui des maillons
    {
        prec = curr;
        curr = curr->suiv;
    }

    (*p)->suiv = curr;
    if (prec == NULL)   //La  file est vide ou le num de ticket de p est inférieure à celui de la tete.
    {
        pf->tete = (*p);
    }
    else
    {
        prec->suiv = (*p);
    }

    if (curr == NULL)   //on est arrivé à la fin de la file.
    {
        pf->queue = (*p);
    }

    return 1;
}

//Fonction qui retourne 1 si le client ayant un certain numéro de ticket a été supprimé de la file.
int supprimer_client(int ticket, Guichet * gui)
{
    File *pf = &(gui -> file);
    Maillon *curr = pf->tete;
    Maillon *prec;
    while ((curr != NULL) && ( curr->client.ticket!= ticket))   //parcourir la file en comparant le num de ticket de p et celui des maillons
    {
        prec = curr;
        curr = curr->suiv;
    }
    if ( curr->client.ticket == ticket)
    {
        if (curr == pf->tete)   //le client recherché est premier dans la file
        {
            pf-> tete = curr->suiv;
        }
        else
        {
            prec->suiv = curr->suiv;
        }
        if(curr == pf->queue)   //le client recherché est dernier dans la file
        {
            pf->queue = prec;
        }
        free(curr);
        if ( pf->tete == NULL ) // si la file devient vide
        {
        pf->queue = NULL;
        }
        return 1;
    }
    return 0;
}

//Fonction qui retourne un pointeur vers un guichet selon son nom.
Guichet * acc_gui (Guichet *acc, char G, int nb_gui)
{
    int i=0;
    Guichet* p = acc->suiv;
    while ((i< nb_gui) & (G!= p->nom))  //parcourir la liste des guichets jusqu'à trouver le guichet recherché par son nom G.
    {
        p = p->suiv;
        i++;
    }
    if (G == p->nom)
    {
        return p;
    }
    else
    {
        return NULL;
    }
}

//Procedure qui permet de dupliquer le maillon p en q.
void duplicate(Maillon *p, Maillon ** q)
{
    //Cette procedure a été créée pour avoir une copie du maillon d'un client dans le guichet accueil.

    (*q)->client.guichet= p->client.guichet;
    strcpy((*q)->client.nom, p->client.nom);
    (*q)->client.ticket = p->client.ticket;

}

//Procedure pour ajouter un client au centre.
void ajout_client(Guichet *acc, int *ticket, int nb_gui)
{
    Maillon *p, *q;
    allouer(&p);    //pour contenir le client.
    allouer(&q);    //pour contenir sa copie dans le guichet accueil.
    char c;
    char nom[100];
    do
    {  //Lecture du nom jusqu'à ce qu'il est non vide.
        printf("\n\t\t\t*Entrer le nom du client: ");
        fflush(stdin);
        fgets(nom, 100, stdin);     //pour accepte les caractère espaces dans la chaine.
        nom[strlen(nom)-1] = '\0';      //pour supprimer la \n de la chaine.
        if(strlen(nom) == 0) {printf("\t\t\t\tLe nom du client ne doit pas etre vide, veuillez reessayer");}
    }while(strlen(nom) == 0);

        //Affichage des guichets disponibles.
    printf("\n\n\t\tLes guichets disponibles sont: ");
    for (Guichet * pg = acc->suiv; pg != NULL; pg=pg->suiv){printf("-%c  ", pg->nom);}

    do
    {
        printf("\n\t\t\t*A quel guichet affecter ce client: ");
        scanf(" %c",&c);
        if((toupper(c)< 65) || (toupper(c)>=(65 + nb_gui))){printf("\t\t\t\tCe guichet n existe pas, veuillez reessayer"); fflush(stdin);}
    }while((toupper(c)< 65) || (toupper(c)>=(65 + nb_gui)));

        //Affectation des informations du client au maillon.
    p->client.guichet = toupper(c);
    strcpy(p->client.nom, nom);
    p->client.ticket = (*ticket);

        //Affectation du client au guichet accueil et au guichet choisis.
    duplicate(p, &q);
    (*ticket)++; //Incrémentation du ticket pour le prochain client.
    Guichet * gui =acc_gui(acc,p->client.guichet,nb_gui);
    if ((enfiler_client(&p,gui)) && (enfiler_client(&q,acc)))
    {
        printf("\n\t\t\tLe client <%s> a ete affecter au guichet %c", p->client.nom, p->client.guichet);
    }
    else
    {
        printf("\n\t\t\til semble avoir une erreur, veuillez reessayer");
    }
    c = getch();
}

//Procedure qui permet de choisir un guichet pour une certaine opération.
void choix_gui(Guichet *acc, Guichet **gui, int nb_gui, int fonct, char dest, int num_red)
{
    char choix =1;
    char c;
    int max_choix = (nb_gui +1);
repeat :
    (*gui) = NULL;
do
    {
    affichage_entete();

//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!REMARQUE!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                                /* cette procedure prend plusieurs paramètres tel que fonct, qui permettent d'afficher un message selon la fonction appelante.  */
                               /* ceci est à cause du system("cls") présent dans l'affichage entete(), qui efface l'écran tant qu'on est dans le do-while loop.*/


    switch(fonct)// Le message a afficher selon la fonction
    {
    case 0:
       printf("\n\n\t\t->Vous avez choisis l'option b. Reception des clients.");
       printf("\n\n\t\t\tChoisir le guichet:\n\n");
       break;
    case 1:
        printf("\n\n\t\t->Vous avez choisis l'option b. Reception des clients ii.Redirection du client.");
        printf("\n\n\t\t\tChoisir le guichet:\n\n");
        break;
    case 2:
        printf("\n\n\t\t->Vous avez choisis d.Operations sur les files i.Rediriger une file sur 'n' autre guichets.");
        printf("\n\n\t\t\tChoisir le guichet a rediriger :\n\n");
        break;
     case 3:
        printf("\n\n\t\t->Vous avez choisis d.Operations sur les files ii. Redirection de files vers le meme guichet.\n\n\t\t\tCommencez par choisir le guichet destination.\n\n");
        break;
     case 4:
        printf("\n\n\t\t->Vous avez choisis d.Operations sur les files ii. Redirection de files vers le meme guichet.\n\n\t\t\tLe guichet destination selectionne est %c",dest);  //dest représente le guichet destination
        printf("\n\n\n\t\t\tChoisissez le '%d' guichet a rediriger vers %c.\n\n", num_red, dest);     //num_red permet de tracker le nombre de guichet à rediriger vers dest déjà sélectionnés.
     default :
        break;
    }

            //Affichage de la liste des guichets.
            int new_line = 1;
        for (int i = 1; i <= max_choix; i++)
        {
            if((new_line % 5) == 0){printf("\n\n");}
            new_line++;
            printf("\t\t");
            if(i == max_choix)
            {
                printf("\n\n\t\t");
            }
            if (i == choix)
            {
                printf("~~> "); // Highlight l'option selectionnée.
            }
            if (i <= nb_gui)
            {
                printf("-%c",(char)(64+i)); // Afficher le nom du guichet.
            }
            else
            {
                printf("-Retour a l ecran precedent");
            }
        }
        c = getch(); //attendre input de l'utilisateur.

        //Update selon le input.
        switch (c)
        {
        case 75: // Flèche vers la gauche.
            if (choix > 1)
            {
                choix--; //Modifier la séléction vers le haut ou vers la gauche.
            }
            break;
        case 77: // Flèche vers le bas ou Flèche vers la droite.
            if (choix < max_choix)
            {
                choix++; //Modifier la séléction vers le bas ou vers la droite.
            }
            break;
        default:
            break; // Ignorer les autres.
        }

    } while (c != 13); //tant que input est différent de la touche entrer.

    if (choix == max_choix ) {return;} //exiter si le choix selectionné est retour a l'écran precedent.
    else
    {
        (*gui) = acc_gui(acc,(char)(64+choix), nb_gui);   //acceder au guichet selectionné.

            //Afficher les messages d'erreurs selon la fonction.
        switch(fonct)
        {
        case 0:
            if(Longueur(&((*gui)->file))== 0){printf("\n\n\t\t\tLa file d attente du guichet %c est vide. Veuillez ajouter des clients puis reessayer.",(*gui)->nom);getch();}
            break;
        case 2:
            if(Longueur(&((*gui)->file))== 0){printf("\n\n\t\t\tLe guichet %c est vide. Veuillez reessayer.", (*gui)->nom);getch();goto repeat;}
            break;
        case 4:
            if((*gui)->nom == dest){printf("\n\n\t\t\tLe guichet %c est le guichet destination. Veuillez reessayer.",dest);getch();goto repeat;}
            else if(Longueur(&(*gui)->file) == 0){printf("(\n\n\t\t\tLe guichet %c est vide. Veuillez reessayer.", (*gui)->nom);getch();goto repeat;}
            break;
        default:
            break;
        }
    }
}

//Fonction qui retourne 1 si le nom du guichet d'un client du guichet d'accueil est modifié au nom du guichet du maillon p avec succès.
int changegui_acc(Guichet * acc, Maillon *p)
{
        //Cette fonction est utilisé lors du redirectionnement d'un client vers un autre guichet, pour changer le nom de son guichet dans la file d'accueil.
    Maillon *curr = acc->file.tete;
    while((curr->client.ticket != p->client.ticket)&&(curr != NULL))        //parcours de la file d'accueil à l'aide du numéro de ticket.
    {
        curr = curr->suiv;
    }
    if(curr != NULL)
    {
        curr->client.guichet = p->client.guichet;
        return 1;
    }
    else
    {
        return 0;
    }
}

//Fonction qui retourne 1 si le premier client d'une file est redirectionné vers une autre file avec succès.
int redirect_client(Guichet *acc,Guichet **gui, Guichet **gui_red)
{
  Maillon *p;
  if (defiler_client(&p, *gui))
  {
      p->client.guichet = (*gui_red)->nom;  //Changement du nom du guichet.
      if(insert_client(&p, *gui_red))
      {
          if(changegui_acc(acc, p)){return 1;}  //Changement du nom du guichet dans le guichet accueil.
      }
  }
    return 0;
}

//Procedure qui permet d'afficher une file d'attente d'un guichet.
void afficher_file (Guichet*gui)
{
    int i = 1;
    File *pf = &(gui->file);
    if(Longueur(pf) == 0)
    {
        printf("\n\n\t\tLe guichet %c est vide.", gui->nom);
    }
    else
    {
        if (gui->nom == '\0') // le guichet accueil.
        {
            printf("\n\n\t\tAffichage de la file d'attente du guichet accueil:\n");
            if(Longueur(pf) == 0)
            {
                printf("\n\n\t\tLe guichet accueil est vide.");
            }
        else
        {
            printf("\n\n\t\t->Affichage de la file d'attente du guichet %c:\n", gui->nom);

            }
        }
        for (Maillon *curr = pf->tete ; curr != NULL ; curr = curr ->suiv) //parcourir la file et afficher tous les clients
        {
            printf ("\n\t\t\tClient n°%d:\n\t\t\t\t-Nom:%s\t\t\t-Guichet:%c\t\t\t-Ticket:%d\n", i,curr->client.nom,curr->client.guichet,curr->client.ticket);
            i ++;
        }
    }

}

//Procedure qui permet d'afficher les files de tous les guichets du centre.
void afficher_global(Guichet * acc)
{
    affichage_entete();
    Guichet * gui = acc->suiv;
    Maillon *p;
    char choice = 1;
    int max_choice = 3;
    char c;
    char options[3][100] = {"a. Affichage de la file du guichet d accueil.", "b. Affichage des files de tous les guichets separement.", "c. Retour a l ecran precedent."};
    do
    {
        affichage_entete();
        printf("\n\n\t\t->Vous avez choisis l Affichage Global.\n\n\t\t\tChoisir un mode d'affichage:\n");
        for (int i = 1; i <= max_choice; i++)
        {
            printf("\n\n\t\t\t");
            if (i == choice)
            {
                printf("~~> "); // Highlight l'option selectionnée.
            }
            printf("%s", options[i-1]); // Afficher l'option.
        }
        c = getch();//attendre input de l'utilisateur.


        // Update selon le input
        switch (c)
        {
        case 72: // Flèche vers le haut.
            if (choice > 1)
            {
                choice--; //Modifier la séléction vers le haut.
            }
            break;
        case 80: // Flèche vers le bas
            if (choice < max_choice)
            {
                choice++; //Modifier la séléction vers le bas.
            }
            break;
        default:
            break; // Ignorer les autres.
        }
     } while (c != 13);//tant que input est différent de la touche entrer.
        //Affichage
    affichage_entete();
    switch(choice)
    {
    case 1: //Affiche la file du guichet d'accueil.
        printf("\n\n\t\t->Vous avez choisis l'option %s", options[0]);
        afficher_file(acc);
        getch();
        break;
    case 2: //Affiche le contenu de chaque file séparemment.
        printf("\n\n\t\t->Vous avez choisis l'option %s", options[1]);
        while (gui != NULL)
        {
            printf("\n\n\t\t\t*Guichet %c: ", gui->nom);
            if(Longueur(&(gui->file)) == 0)
            {
                printf("\n\n\t\t\t\tCe guichet est vide.");
            }
            else
            {
                p = gui->file.tete;
                while (p != NULL)
                {
                    printf("\n\t\t\t\t-Nom: %s\t\t\t-Guichet: %c\t\t\t-Ticket: %d\n", p->client.nom, p->client.guichet, p->client.ticket);
                    p = p->suiv;
                }
            }
            gui  = gui->suiv;
        }
        getch();
        break;
    default :
        break;
    }
}

//Procedure de l'option b.réception d'un client.
void reception_client (Guichet *acc, Guichet *gui, int nb_gui)
{
    char choix =1;
    char c;
    int i;
    int max_choix = 3;
    char oper[3][100] ={"i. Afficher la liste des clients dans la file d attente","ii. Recevoir un client","iii. Retourner a l ecran precedent"};
    char opt[3][100] ={"* Traiter la requete du client.","* Redirection du client vers un autre guichet.", "* Retourner a l ecran precedent."};
    Guichet * gui_red = NULL;
    Maillon *p;
    char nom[100];
do
    {
    affichage_entete();
    printf("\n\n\t\t->Vous avez choisis l'option b. Reception des clients.");
    printf("\n\n\t\t\tVous avez choisis le guichet %c.\n\n\t\tChoisir une operation: ", gui->nom);
        for (i = 1; i <= max_choix; i++)
        {
            printf("\n\n\t\t\t");
            if (i == choix)
            {
                printf("~~> "); // Highlight l'option selectionnée.
            }
            printf("%s", oper[i-1]);
        }

        c = getch(); //attendre input de l'utilisateur.

           switch (c)
        {
        case 72: // Flèche vers le haut.
            if (choix > 1)
            {
                choix--; //Modifier la séléction vers le haut.
            }
            break;
        case 80: // Flèche vers le bas.
            if (choix < max_choix)
            {
                choix++; //Modifier la séléction vers le bas.
            }
            break;
        default:
            break; // Ignorer les autres.
        }
    } while (c != 13); //tant que input est différent de la touche entrer.

    //Traitement du choix.
    switch (choix)
    {
    case 1://Affichage de la file d'attente.
        affichage_entete();
        afficher_file(gui);
        c = getch();
        break;
    case 2://Reception d'un client
        choix = 1;
    do
    {
        affichage_entete();
        printf("\n\n\t\t->Vous avez choisis l'option b. Reception des clients.");
        printf("\n\n\t\t->Vous avez choisis le guichet %c.\n\n\t\tChoisir une operation: \n\n\t\t\t%s\n\n\t\t\t>%s\n\n\t\t\t\t<Client:%s>:", gui->nom, oper[0],oper[1],gui->file.tete->client.nom);
        for (i = 1; i <= 3; i++)
        {
            printf("\n\n\t\t\t\t\t\t");
            if (i == choix)
            {
                printf("~~> "); // Highlight l'option selectionnée.
            }
            printf("%s", opt[i-1]);
        }
        printf("\n\n\t\t\t%s", oper[2]);

        c = getch(); //attendre input de l'utilisateur.

           switch (c)
        {
        case 72: // Flèche vers le haut.
            if (choix > 1)
            {
                choix--; //Modifier la séléction vers le haut.
            }
            break;
        case 80: // Flèche vers le bas.
            if (choix < max_choix)
            {
                choix++; //Modifier la séléction vers le bas .
            }
            break;
        default:
            break; // Ignorer les autres.
        }

    } while (c != 13); //tant que input est différent de la touche entrer.

    //Traitement du choix;
    switch(choix)
    {
    case 1://Traitement de la requete
        affichage_entete();
        printf("\n\n\t\t->Vous avez choisis l'option b. Reception des clients * Traiter la requete du client.");
        //Taiter la requete du client veut dire le supprimer du centre
        if (defiler_client(&p, gui)) // suppression de la file de son guichet
        {
            if (supprimer_client(p->client.ticket , acc)) //suppression de l'accueil.
            {
                printf("\n\n\t\t\tLa requete de <%s> a ete traitee.", p->client.nom);
                free(p);
            }
        }
        c = getch();
        break;
    case 2: //Redirection du client
        choix_gui(acc, &gui_red, nb_gui, 1, 0, 0);
        strcpy(nom , gui->file.tete->client.nom);//preserver le nom du client pour l'affichage
        if (gui_red != NULL)
        {
            if (redirect_client(acc,&gui, &gui_red))
            {
                printf("\n\n\t\tLe client <%s> a ete redirectionne.", nom);
            }
        c = getch();
        }
        break;
    default:
        break;
    }
        break;
    default:
        break;
        }
}

//Fonction qui retourne le nombre de guichets vides.
int nbgui_vide(Guichet * acc)
{
    int i = 0;
    for(Guichet * gui = acc->suiv ; gui!= NULL; gui = gui->suiv)
    {
        if (Longueur(&(gui->file)) == 0)
        {
            i++;
        }
    }
    return i;
}

//Fonction qui retourne 1 si 2 files sont fusionnées avec succès.
int fusion_files(Guichet *acc ,Guichet * gui_dest, Guichet * gui)
{
    Maillon *p;
    while(Longueur(&(gui->file))!= 0)
    {
        if(defiler_client(&p, gui))
        {
            p->client.guichet=gui_dest->nom; //changement du nom du guichet.
            changegui_acc(acc, p);          //changement du nom du guichet dans la file d'accueil.
            insert_client(&p, gui_dest);
        }
    }
    return 1;
}

//Procedure de redirection d'une file d'attente d'un guichet sur 'n' autres guichets.
void redirect_file(Guichet * acc, Guichet * gui, int n, int nb_gui, int nb_vide, char noms [])
{
    Guichet * pg[n]; //Un tableau de guichets intermediaire.
    Maillon *p;

        //Creation des n files intermediaire
    for (int i = 0; i < n; i++)
    {
        pg[i] =(malloc(sizeof(Guichet)));
        creerfile(&(pg[i]->file));
    }

        //Eclatement de la file du guichet sur les guichets intermediaires.
    do
    {
        for (int i = 0; i < n; i++)
        {
            if(defiler_client(&p, gui))
            {
                enfiler_client( &p, pg[i]);
            }
        }
    }while(Longueur(&(gui->file))!= 0);

    int j=0;
    Guichet *curr = acc->suiv;
    int l =Longueur(&(pg[j]->file));

        //Redirection du contenu des guichets intermediares vers n guichets vides du centre.
    do
    {
        if((curr != gui)&(Longueur(&(curr->file))==0))
           {
               for(int i = 0; i<l; i++)
               {
                    if(defiler_client(&p, pg[j]))
                    {
                        p->client.guichet = curr->nom; //changement du nom du guichet.
                        changegui_acc(acc, p);         // changement du nom du guichet dans la file d'accueil.
                        enfiler_client(&p, curr);
                    }
               }
               noms[j] = curr -> nom; //Préserver les noms des guichets vers lesquels la file a été redirectionnée, raison d'affichage
               j++;
           }
        curr=curr->suiv;
    }while(j < n);
}

//Fonction qui retourne 1 si les numéros des guichets ont été reinitialisé avec succès.
int reinit_ticket (Guichet *acc)
{
    if(Longueur(&(acc->file)) == 0){return 0;}
    int ticket = (acc->file.tete->client.ticket - 1);   //tant que l'accueil est ordonnée, le ticket de sa tete est le plus petit ticket.
    for(Guichet * gui = acc; gui != NULL; gui = gui->suiv)
    {
        for(Maillon * curr = gui->file.tete; curr != NULL ; curr = curr->suiv)
        {
            curr->client.ticket = curr->client.ticket - ticket; //reinitialiser tous les tickets de l'accueil jusqu'au dernier guichet.
        }
    }
    return 1;
}

//Fonction qui retourne 1 si les files des tous les guichets sont rééquilibrées.
int reequilibrer_files(Guichet *acc, int nb_gui)
{
    int total_cli= Longueur(&(acc->file)); //10
    int tai_moy_file = ( total_cli / nb_gui); //3
    int diff_max = (total_cli % nb_gui) > 0 ? 1 : 0; //1
    Maillon *p;

    for(Guichet *gui_source = acc->suiv ; gui_source != NULL; gui_source = gui_source->suiv)
    {
        repeat :
        while(Longueur(&(gui_source->file))> (tai_moy_file + diff_max)) // la longueur de la file depasse la limite max
        {
            defiler_client(&p, gui_source); Guichet *gui_dest;
            for(gui_dest = acc->suiv ; gui_dest != NULL; gui_dest = gui_dest->suiv)
            {
                if((gui_dest != gui_source))
                {
                if((Longueur(&(gui_dest->file)) < tai_moy_file)||((Longueur(&(gui_dest->file))==tai_moy_file) && (gui_dest->nom > gui_source->nom)))//
                   {
                       break;//On a trouver un guichet vers lequel on peut redirectionner des clients
                   }

                }
            }
            if(gui_dest != NULL)//inserer ce client dans le guichet
            {
                p->client.guichet = gui_dest->nom;
                changegui_acc(acc, p);
                insert_client(&p, gui_dest);
            }

        }
    }
    return 1;
}

//Procedure des opérations en vrac sur les files.
void operations (Guichet * acc, int nb_gui)
{
    char choix =1;
    char c;
    int i, n;
    int max_choix = 5;
    char opt[5][100] ={"i.Rediriger une file d un guichet sur 'n' autre guichets","ii.Rediriger deux files ou plus vers le meme guichet","iii. Reequilibrer les files d attente des guichets","iv. Reinitialiser tous les numeros de tickets","v. Annuler."};
    Guichet * gui = NULL;

    do
    {
    affichage_entete();
    printf("\n\n\t\tChoisir une operation:\n\n\t\t\ta. Ajouter des clients\n\n\t\t\tb. Reception des clients\n\n\t\t\tc. Afficher la file d attente globale\n\n\t\t\t>d. Operations sur les files d attente.");
         for (i = 1; i <= max_choix; i++)
        {
            printf("\n\n\t\t\t\t\t");
            if (i == choix)
            {
                printf("~~> "); // Highlight ~l'option selectionnée
            }

            printf("%s", opt[i-1]); // Affiche l'option.
        }
    printf("\n\n\t\t\te. Quitter le programme");

        c = getch();//attendre input de l'utilisateur.

    switch (c)
        {
        case 72: // Flèche vers le haut.
            if (choix > 1)
            {
                choix--; //Modifier la séléction vers le haut.
            }
            break;
        case 80: // Flèche vers le bas.
            if (choix < max_choix)
            {
                choix++; //Modifier la séléction vers le bas .
            }
            break;
        default:
            break; // Ignorer les autres.
        }
    } while (c != 13); //tant que input est différent de la touche entrer.

char noms[n];
Guichet * gui2;

        //Traitement des choix
    switch (choix)
    {
    case 1://Rediriger une file sur n files
        if((nb_gui >= 2)&&(nbgui_vide(acc) < nb_gui)) //si tous les guichets sont vides on  ne va rien rediriger.
           {
                choix_gui(acc, &gui,nb_gui, 2,0,0);
                if (gui != NULL)
                {
                do
                {
                    affichage_entete();
                    printf("\n\n\t\t->Vous avez choisis d.Operations sur les files i.Rediriger une file sur 'n' autre guichets.");
                    printf("\n\n\t\t->Vous avez choisis le guichet %c\n\n\t\t\t*Il y a %d guichets vides et la file d attente du guichet %c contient %d clients.", gui->nom,nbgui_vide(acc), gui->nom, Longueur(&(gui->file)));
                    printf("\n\n\t\t\t\tEntrer n: ") ;
                    scanf(" %d", &n);

                    if (n>nbgui_vide(acc))
                    {
                        printf("\n\n\t\t\tIl y a %d guichets vides. Veuillez reessayer.",nbgui_vide(acc));fflush(stdin);getch();
                    }
                    else if((Longueur(&(gui->file))<n))
                    {
                        printf("\n\n\t\t\tLa file d attente du guichet %c contient %d clients.Veuillez reessayer.",gui->nom, Longueur(&(gui->file)));fflush(stdin);getch();
                    }
                }while((n>nbgui_vide(acc)) || (Longueur(&(gui->file))<n));
                redirect_file(acc, gui, n, nb_gui,nbgui_vide(acc),noms);
                printf("\n\n\t\t\tLa file du guichet %c a ete rediriger sur les guichets: ", gui->nom);
                for(int i = 0; i<n; i++)
                {
                    printf("%c ", noms[i]);
                }
                getch();
                }
            }
            else
            {
                affichage_entete();
                printf("\n\n\t\t->Vous avez choisis d.Operations sur les files i.Rediriger une file sur 'n' autre guichets.");
                if(nb_gui < 2){printf("\n\n\t\tCette operation necessite un minimum de 2 guichets.");}
                else if (nbgui_vide(acc) == nb_gui) {printf("\n\n\t\tToutes les files sont vides. Veuillez ajouter des clients puis reessayer.");}
                getch();
            }

    break;
  case 2://Redirection de min 2 files vers le meme guichet
      if((nb_gui >=3)&&(nbgui_vide(acc) < nb_gui - 1)) //il faut avoir un minimum de 3 guichets pour rediriger 2 vers 1
      {
          choix_gui(acc, &gui, nb_gui, 3, 0, 0);
          if(gui != NULL)
          {
          do
          {
            affichage_entete();
            printf("\n\n\t\t->Vous avez choisis d.Operations sur les files ii. Redirection de files vers le meme guichet.");
            printf("\n\n\t\t->Choisir le nombre de files d attente a rediriger vers le guichet %c: ", gui->nom);
            scanf("%d", &n);
            if (n<2)
            {
              printf("\n\n\t\t\tVeuillez entrer un nombre superieure ou egal a 2.");fflush(stdin);getch();
            }
            else if(n>=nb_gui)
            {
              printf("\n\n\t\t\tLe nombre entre est superieure au nombre de guichets disponibles.Veuillez reessayer.");fflush(stdin);getch();
            }
          }while((n<2)||(n>=nb_gui));
          if(((nb_gui - nbgui_vide(acc))>n)||(((nb_gui - nbgui_vide(acc)) == n) && (Longueur(&(gui->file)) == 0)))
            //Le nombre de guichets non vide disponible à redirectionner >= à n
          {
              for(int i = 0; i< n; i++)
              {
                  choix_gui(acc, &gui2, nb_gui, 4, gui->nom, (i+1));
                  if(gui2 != NULL)
                  {
                      if(fusion_files(acc, gui, gui2))
                      {
                          printf("\n\n\t\tla file d'attente du guichet %c a ete rediriger vers le guichet %c", gui2->nom, gui->nom);
                      }
                      getch();
                  }
                  else{goto out;}
              }
          }
          else
          {
              printf("\n\n\t\tIl n y a pas assez de guichets non vides pour effectuer cette operation. Veuillez reessayer.");
              getch();
          }
          }
      }
      else out:
      { if(gui2 != NULL)
      {
        affichage_entete();
        printf("\n\n\t\t->Vous avez choisis d.Operations sur les files ii. Redirection de files vers le meme guichet.");
        if (nb_gui< 3){printf("\n\n\t\tCette operation necessite un minimum de 3 guichets.");getch();}
        else if(nbgui_vide(acc) >= nb_gui - 1){printf("\n\n\t\tCette operation necessite au moins 2 guichets non vides.Veuillez reessayer.");getch();}
        getch();

      }
      }

    break;
  case 3://Reequilibrer les files
      affichage_entete();
      printf("\n\n\t\t->Vous avez choisis d.Operations sur les files %s ", opt[2]);
      if(nb_gui >= 2)
      {
        if(reequilibrer_files(acc, nb_gui))
          {
              printf("\n\n\t\t\tToutes les files d attentes ont ete reequilibrer");
          }
      }
      else
      {
        printf("\n\n\t\tCette operation necessite un minimum de 2 guichets.");
      }
      getch();
    break;
  case 4 ://Reinitialiser les tickets
      affichage_entete();
      printf("\n\n\t\t->Vous avez choisis d.Operations sur les files %s ", opt[3]);
      if(reinit_ticket(acc))
      {
          printf("\n\n\t\t\tLes numeros des tickets ont ete reinitialises.");
      }
      else
      {
          printf("\n\n\t\t\tLes guichets sont vides. Ajoutez des clients puis reessayer.");
      }
      getch();
    break;
    default:
    break;
}
}

/*-------------------------------------------------Fin de la declaration des fonction------------------------------------------------------------------------------*/
int main()
{
    Guichet *acc;//accueille
    Guichet *gui = NULL;
    int nb_gui;
    int ticket = 1;
    affichage_interface();
    affichage_entete();
    alloc_guichets(&acc, &nb_gui);
    char choice = 1;                      // option selectionnée à defaut.
    int max_choice = 5;
    char c;
    char options[5][100] ={"a. Ajouter des clients","b. Reception des clients","c. Afficher la file d attente globale","d. Operations sur les files d attente","e. Quitter le programme"};
  do
  {
    do
    {
        affichage_entete();
        printf("\n\n\t\t->Choisir une option:\n");
        for (int i = 1; i <= max_choice; i++)
        {
            printf("\n\n\t\t\t");
            if (i == choice)
            {
                printf("~~> "); // Highlight l'option selectionnée.
            }
            printf("%s", options[i-1]); // Afficher les options.
        }

        c = getch(); //attendre input de l'utilisateur.

        switch (c) //Update selon input
            {
            case 72: // Flèche vers le haut.
                if (choice > 1)
                {
                    choice--; //Modifier la séléction vers le haut.
                }
                break;
            case 80: // Flèche vers le bas.
                if (choice < max_choice)
                {
                    choice++; //Modifier la séléction vers le bas .
                }
                break;
            default:
                break; // Ignorer les autres.
            }
    } while (c != 13); //tant que input est différent de la touche entrer.


    // Traitement des choix
    switch (choice)
    {
    case 1: //Ajouter des clients
        affichage_entete();
        printf("\n\n\t\t->Vous avez choisis l'option %s\n", options[choice-1]);
        ajout_client(acc, &ticket, nb_gui);
        break;
    case 2: //Reception cliens
        choix_gui(acc,&gui,nb_gui, 0, 0, 0);
        if (( gui != NULL)&&(Longueur(&(gui->file)) != 0))
        {
         reception_client(acc, gui, nb_gui);
        }
        break;
    case 3://Affichage global
        affichage_entete();
        printf("\n\n\t\t->Vous avez choisis l'option %s\n", options[choice-1]);
        afficher_global(acc);
        break;
    case 4://Operations sur les files
        operations(acc, nb_gui);
        break;
    default:
        break;

    }
  }while(choice != 5);//Quitter le programme
return 0;
}
