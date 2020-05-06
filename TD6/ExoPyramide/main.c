#include <stdio.h>

int main() {
    int result,n,i,j;

    do
    {
        printf("Rentrez le nombre de lignes\n> ");
        result=scanf("%d",&n);
        fflush(stdin);
    }while(result==0 || n<1 || n>9);


    for(i=1;i<=n;i++)
    {
        printf("\n");
        for(j=0;j<n-i;j++) // Espaces devant la série de nombres
        {
            printf("   ");
        }
        for(j=1;j<=i;j++) // Partie croissante
        {
            printf(" %d ",j);
        }
        for(j=i-1;j>=1;j--) // Partie décroissante
        {
            printf(" %d ",j);
        }
    }
    return 0;
}
