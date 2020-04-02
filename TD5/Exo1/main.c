#include <stdio.h>
#include <math.h>

int main(){
    long int numero_compte, copie, longueur, i=0, somme=0, chiffre;

    printf("Entrez le numero du compte\n> ");
    scanf("%ld",&numero_compte);

    copie=numero_compte;

    printf("\nLa longueur du numero de carte est de %ld", longueur);

    while(copie!=0)
    {
        chiffre=copie%10;
        if(i%2)
        {
            chiffre*=2;
            chiffre=chiffre%10+chiffre/10;
        }
        somme+=chiffre;
        copie=copie/10;
        i++;
    }

    printf("\n\nLa somme finale est de %ld\n",somme);
    longueur=i;
    printf("\nLa longueur du numero de carte est de %ld", longueur);

    if(somme%10)
        printf("\nCarte non correcte");
    else
    {
        printf("\nCarte correcte");

        if(longueur>=13 && longueur<=16 && (numero_compte%(long)pow(10,longueur-1) == 4))
            printf("\nIl s'agit d'une carte Visa");

        else if(longueur==16 && (numero_compte%(long)pow(10,14) == 54 || numero_compte%(long)pow(10,14) == 55))
                printf("\nIl s'agit d'une MasterCard");
        else
            printf("\nIl s'agit d'une autre carte");
    }
    return 0;
}
