#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 100

int recherche_premiere_occurence(int x, int tableau[MAX])
{
    int i=0;
    for(i=0;i<MAX;i++)
    {
        if(tableau[i]==x)
            return i;
    }
    return -1;


}


int main()
{
    int tableau[MAX];
    int i,x;

    srand(time(NULL));

    for(i=0;i<MAX;i++)
    {
        tableau[i]=rand()%1001;
        printf("[%d] = %d\n",i,tableau[i]);
    }
    printf("\nQuelle valeur voulez vous cherchez ?\n> ");
    scanf("%d",&x);
    printf("retour recherche : %d",recherche_premiere_occurence(x,tableau));
    return 0;
}
