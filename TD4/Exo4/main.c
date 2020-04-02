#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

int main()
{
    int random, current, compteur, continu;
    srand(time(NULL));

    do
    {
        compteur=0;
        random=(rand()%MAX)+1;
        do
        {
            printf("Rentrez un nombre :\n> ");
            scanf("%d",&current);
            compteur++;
            if(random>current)
                printf("\nTrop petit :(\n");
            else if(random<current)
                printf("\nTrop grand :(\n");
            else
                printf("\nWaaa vous avez trouvé le nombre en %d coup(s)\n",compteur);
        }while(current!=random);

        printf("\n\nVoulez-vous continuer ? [0-Non, 1-Oui]\n>");
        scanf("%d",&continu);
        printf("\n\n");
    }while(continu);

    return 0;
}
