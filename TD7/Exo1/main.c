#include <stdio.h>

long int fact(long int x)
{
    if(x)
        return x*fact(x-1);
    return 1;
}

int main()
{
    long int n;
    printf("Rentrez un nombre\n> ");
    scanf("%ld",&n);
    printf("Le resultat de %d factorielle est %ld",n,fact(n));
    return 0;
}
