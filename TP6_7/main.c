#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "fonctions.h"

int main()
{
    param p1 = {.a=0.1, .b=0.5, .l=1.0, .s=0.05, .e=0.01}; // Parametres p1
    param p2 = {.a=0.1, .b=0.75, .l=1.0, .s=0.05, .e=0.3}; // Parametres p2


    float dt=0.5, tmax, error;

    int action=1, sousaction=1, i, nb;

    trace traces[NBSLOTS];
    trace* pointer = NULL;
    trace* pointer2 = NULL;

    for(i=0;i<NBSLOTS;i++) // Initialisation des traces situées dans les différents slots
    {
        pointer=&traces[i];
        pointer->nbpts=-1;
        pointer->value=NULL;
        pointer->time=NULL;
        strcpy(pointer->comment, " - ");
    }

    char name[MAXC];

	printf("\n#### Vous disposez de %d slots (de 1 a %d) pour sauvegarder vos traces ####",NBSLOTS,NBSLOTS);

    while(action)
    {
        printf("\n\nQue voulez-vous faire ?");
        printf("\n0 - quitter");
        printf("\n1 - creer une trace");
        printf("\n2 - charger une trace depuis un fichier");
        printf("\n3 - sauvegarder une trace dans un fichier");
        printf("\n4 - afficher une trace");
        printf("\n5 - calculer l'erreur entre 2 traces");

        action=askValue();

        switch(action) // Switch case pour sélectionner le bon menu
        {
            case 1:
                printf("\n\nVoulez-vous creer une trace avec les parametres 1(1), 2(2) ou trace expected(3) ?");
                sousaction=askValue();
                printf("\nVeuillez indiquer le slot :");
                askSlot(&pointer, traces);
                if(sousaction==3)
                    expeTrace(pointer);
                else
                {
                    printf("\nIndiquez le nom de la trace");
                    askName(pointer->comment);
                    printf("\nIndiquez le nombre de points de la trace");
                    pointer->nbpts=askValue();
                    nb=pointer->nbpts;
                    tmax=(float)((nb)*dt);
                    if(sousaction==1)
                        simuTrace(tmax,dt,&p1,pointer);
                    else if(sousaction==2)
                        simuTrace(tmax,dt,&p2,pointer);
                }
                break;
            case 2:
                printf("\n\nVoulez-vous ouvrir un fichier structure(0) ou texte(1) ?");
                sousaction=askValue();
                if(sousaction)
                {
                   printf("\nVeuillez entrer le nom du fichier texte :");
                    askName(name);
                    printf("\nVeuillez indiquer le slot :");
                    askSlot(&pointer, traces);
                    readTraceTxt(name,pointer);
                }
                else
                {
                    printf("\nVeuillez entrer le nom du fichier structure :");
                    askName(name);
                    printf("\nVeuillez indiquer le slot :");
                    askSlot(&pointer, traces);
                    readTraceBin(name,pointer);
                }
                break;
            case 3:
                printf("\n\nVoulez-vous sauvegarder dans un fichier structure(0) ou texte(1) ?");
                sousaction=askValue();
                if(sousaction)
                {
                    printf("\nVeuillez entrer le nom du fichier texte :");
                    askName(name);
                    printf("\nVeuillez indiquer le slot :");
                    askSlot(&pointer, traces);
                    saveTraceTxt(name,pointer);
                }
                else
                {
                    printf("\nVeuillez entrer le nom du fichier structure :");
                    askName(name);
                    printf("\nVeuillez indiquer le slot :");
                    askSlot(&pointer, traces);
                    saveTraceBin(name,pointer);
                }
                break;
            case 4:
                printf("\n\nIndiquez le slot de la trace que vous voulez afficher :");
                askSlot(&pointer, traces);
                printTrace(pointer);
                break;
            case 5:
                printf("\n\nIndiquez le slot de la trace 1 :");
                askSlot(&pointer, traces);
                printf("\n\nIndiquez le slot de la trace 2 :");
                askSlot(&pointer2, traces);
                error=errorTrace(pointer,pointer2);
                if(error==-1)
                    printf("\nL'erreur n'a pas ete calculee, il semblerait que les 2 traces n'aient pas le meme nombre de points...");
                else
                    printf("\nL'erreur est de %f",error);
                break;
        }
    }

    for(i=0;i<NBSLOTS;i++) // Libération de l'espace alloué dynamiquement avant de quitter le programme
    {
        if(traces[i].value!=NULL)
            free(&traces[i].value);
        if(traces[i].time!=NULL)
            free(&traces[i].time);
    }

    return 0;
}

