#include <stdio.h>
#include "fonctions.h"

int main()
{
    // Init
    long int x,y;

    // On demande la variable x
    x=demanderVariableEntiere('x');
    affichageDonneesVariable(x,'x');

    // On demande la variable y
    y=demanderVariableEntiere('y');
    affichageDonneesVariable(y,'y');

    // Affichage
    printf("\nLe nombre de combinaisons est de %ld",comb(x,y));

    if(estDivisible(y,x))
        printf("\ny est divisible par x");
    else
        printf("\ny n'est pas divisible par x");
    printf("\n\n");
    return 0;
}
