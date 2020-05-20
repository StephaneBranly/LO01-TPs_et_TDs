#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define DIMENSION 5

void ajouter_bateaux(int nbr, int ocean[DIMENSION][DIMENSION])
{
    int i, x,y, place=0;
    for(i=0;i<nbr;i++)
    {
        place=0;
        while(!place)
        {
            x=rand()%DIMENSION;
            y=rand()%DIMENSION;
            if(!ocean[x][y])
            {
                ocean[x][y]=1;
                place=1;
            }
        }
    }
}

int reste_bateau(int ocean[DIMENSION][DIMENSION])
{
    int i, j;
    for(i=0;i<DIMENSION;i++)
    {
        for(j=0;j<DIMENSION;j++)
        {
            if(ocean[i][j]==1)
                return 1;
        }
    }
    return 0;
}

void afficher_ocean(int ocean[DIMENSION][DIMENSION], int afficher_bateau)
{
    int i, j;
    printf("  |  0   1   2   3   4");
    for(i=0;i<DIMENSION;i++)
    {
        printf("\n%d | ",i);
        for(j=0;j<DIMENSION;j++)
        {
            if(ocean[i][j]==1 && afficher_bateau)

                printf("[_] ");
            else if(ocean[i][j]==2)
                printf("&!# ");
            else
                printf("~~~ ");
        }
    }
}
int main()
{
    int x, y;
    srand(time(NULL));
    int ocean[DIMENSION][DIMENSION]={{0}};

    afficher_ocean(ocean,0);

    ajouter_bateaux(5,ocean);
    while(reste_bateau(ocean))
    {
        printf("\n\nChoisissez les coordonnees x y\n>");
        scanf("%d %d",&x,&y);
        if(ocean[x][y]==1)
        {
             printf("COULE !!!\n");
             ocean[x][y]=2;
        }

        else
            printf("AUCUN IMPACT...\n");
        afficher_ocean(ocean,0);
    }

    printf("\nFelicitations? ! Tous les bateaux ont ete coules");
    return 0;
}
