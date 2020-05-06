#include <stdio.h>


int puissance(int x, int n) // De l'exercice 7.2, mais en int
{
    if(n)
        return x*puissance(x,n-1);
    return 1;
}

int nbDeChiffre(int x)
{
    if(x)
        return 1+nbDeChiffre(x/10);
    return 0;
}

int nbChestPaire(int x)
{
    return (nbDeChiffre(x)+1)%2;
}

/*
int extraitNombre(int x, int n, int lg)
{
    // x =123456789 ; n= 3 ; lg=2
    x /= puissance(10,n-1); // 1234567 ; tronque la partie droite
    x %= puissance(10,lg); // 67 ; tronque la partie gauche
    return x;
}
*/
int extraitNombre(int x, int n, int lg)
{
    return (x%puissance(10,n+lg-1))/puissance(10,n-1);
}


int sommeDesChiffres(int x)
{
    if(x)
        return x%10+sommeDesChiffres(x/10);
    return 0;
}

int main()
{
    int n;
    printf("Rentrez n\n> ");
    scanf("%d",&n);
    printf("Dans %d, il y a %d chiffre(s)",n,nbDeChiffre(n));
    printf("\nEst-ce pair ? %d",nbChestPaire(n));

    int longueur=nbDeChiffre(n);
    if(nbChestPaire(n))
    {
        int partie_gauche=extraitNombre(n,longueur/2+1,longueur/2);
        int partie_droite=extraitNombre(n,1,longueur/2);
        printf("\nSomme des chiffres partie gauche(%d)? %d",partie_gauche,sommeDesChiffres(partie_gauche));
        printf("\nSomme des chiffres partie droite(%d)? %d",partie_droite,sommeDesChiffres(partie_droite));
        if(sommeDesChiffres(partie_gauche)==sommeDesChiffres(partie_droite))
            printf("\n\nNombre couicable");
        else(printf("\n\nNombre NON couicable"));
    }
    else(printf("\n\nNombre NON couicable"));


    return 0;
}
