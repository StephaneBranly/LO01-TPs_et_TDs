#include <stdio.h>

float puissance(float x, int n)
{
    if(n<0)
        return 1/puissance(x,-n);
    else if(n>0)
        return x*puissance(x,n-1);
    return 1;
}

int main()
{
    float x;
    int n;
    printf("Rentrez x n\n> ");
    scanf("%f%d",&x,&n);
    printf("Le resultat de %f puissance %d est %f",x,n,puissance(x, n));
    return 0;
}
