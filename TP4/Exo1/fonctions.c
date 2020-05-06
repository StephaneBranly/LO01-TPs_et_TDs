#include <stdio.h>
#include "fonctions.h"

long int fact(long int x) // Factorielle, par récursivité
{
    if(x<0) // Cas où l'entrée est incorrecte
        return 0;
    if(x) // Recursivité tant que x!=0
        return x*fact(x-1);
    return 1; // Condition d'arret
}

void permute(long int *x, long int *y) // permtation par pointeurs car nous devons modifier 2 valeurs et nous ne voulons pas non plus créer de copie locale
{
    if(x!=NULL && y!=NULL) // Verification que les pointeurs ne sont pas nulls
    {
        long int tmp = *x; // Creation d'une variable tampon pour faire l'échange
        *x = *y;
        *y = tmp;
    }
}

long int comb(long int n,long int p)
{
    if(n<0 || p<0) // Verification des arguments
        return 0;
    if(n<p) // Permutation si necessaire, par passage d'adresse
        permute(&n,&p);
    return fact(n)/(fact(n-p)*fact(p)); // Retour de la formule de Combinaison p parmi n
}

long int estDivisible(long int a, long int b)
{
    if(a*b==0 || a%b) // Verification arguments non nulls, puis modulo pour voir s'il y a un reste = non divible
        return 0;
    return 1;
}

long int estPremier(long int n)
{
    if(n<2) // Verification argument non inferieur a 2 (non negatif, si = 0 ou 1, il ne sera pas premier non plus
        return 0;
    long int d=2;
    while(d<=n-1) // Boucle pour tester la divisibilite
    {
        if(estDivisible(n,d)) // Si il y est divisible une seule fois par un nombre dans [2;n-1], on peut faire un return, il ne sera pas premier
            return 0;
        d++;
    }
    return 1;
}

long int demanderVariableEntiere(char c)
{
    long int n,result;
    do
    {
        printf("Rentrez la valeur entiere de %c\n> ",c);
        result=scanf("%ld",&n); // On récupère result qui permet de controler qu'on a bien entrer le bon type
        fflush(stdin); // On vide le buffer
    }while(result==0 || n<0);
    return n;
}

void affichageDonneesVariable(long int n, char c)
{
    if(estPremier(n))
        printf("%c est premier",c);
    else
        printf("%c n'est pas premier",c);

    printf("\nLa factorielle de %c est %ld\n\n",c,fact(n));
}
