#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#include "fonctions.h"

int main()
{
    param p1 = {.a=0.5, .b=0.5, .l=1.0, .s=0.05, .e=0.01};
    param p2 = {.a=0.1, .b=0.75, .l=1.0, .s=0.05, .e=0.3};


    float dt=0.5, tmax;

    int action=1, sousaction=1, i, nb;

    trace traces[10];
    for(i=0;i<10;i++)
    {
        traces[i].nbpts=-1;
        traces[i].value=NULL;
        traces[i].time=NULL;
        strcpy(traces[i].comment, " - ");
    }
    strcpy(traces[0].comment, " 1 ");
    strcpy(traces[1].comment, " 2 ");
    trace* pointer = NULL;
    trace* pointer2 = NULL;
    char name[MAXC];

	printf("\nLa trace esperee a ete correctement chargee");

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

        switch(action)
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
                    printf("\n\nH1");
                    nb=pointer->nbpts;
                    printf("\n\nH2");
                    tmax=(float)((nb*dt)+1);
                    printf("\n\nH3 ; tmax=%f, nbpts=%d",tmax,nb);
                    if(sousaction==1)
                        simuTrace(tmax,dt,&p1,pointer);
                    else if(sousaction==2)
                        simuTrace(tmax,dt,&p2,pointer);
                        printf("\n\nH4");
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
                printf("\n%f",errorTrace(pointer,pointer2));
                break;
        }
    }

    for(i=0;i<10;i++)
    {
        if(traces[i].value!=NULL)
            free(&traces[i].value);
        if(traces[i].time!=NULL)
            free(&traces[i].time);
    }

    return 0;
}

