#include "fonctions.h"
#include <stdlib.h>
#include <stdio.h>

point* creerPoint(float x, float y) // creation d'un point
{
    point* n_point;
    n_point = malloc(sizeof(point)); // allocation dynamique de memoire

    n_point->x=x;
    n_point->y=y;

    return n_point;
}

segment* creerSegment(point* a, point* b) // creation d'un segment
{
    segment* n_segment;
    n_segment = malloc(sizeof(segment));  // allocation dynamique de memoire

    n_segment->a=a;
    n_segment->b=b;
    n_segment->m=creerPoint(0,0);
    n_segment->milieu=calculeMilieu(a->x,a->y,b->x,b->y,&n_segment->m->x,&n_segment->m->y);

    return n_segment;
}

chaine* creerChaine(segment* s)  // creation d'une chaine
{
    chaine* n_chaine;
    n_chaine = malloc(sizeof(chaine));  // allocation dynamique de memoire

    n_chaine->s=s;
    n_chaine->p=NULL; // initialisation de la prochaine chaine par NULL par defaut

    return n_chaine;

}
float demanderValeur(char c) // on demande une valeur
{
    float value;
    int result;

    do
    {
        printf("\nRentrez la valeur de %c\n> ",c);
        result=scanf("%f",&value); // On récupère result qui permet de controler qu'on a bien entrer le bon type
        fflush(stdin); // On vide le buffer
    }while(result==0);

    return value;
}

point* demanderPoint(char c) // on demande un point
{
    point* n_point;
    float x,y;

    printf("\n## Rentrez le point %c ##",c);
    x=demanderValeur('x');
    y=demanderValeur('y');
    n_point = creerPoint(x,y);

    return n_point;
}

segment* demanderSegment(int n) // on demande un segment
{
    segment* n_segment;
    point* a;
    point* b;

    printf("\n#### Rentrez le segment numero %d ####",n);
    a = demanderPoint('A');
    b = demanderPoint('B');
    n_segment = creerSegment(a, b);

    return n_segment;
}

void afficherSegment(segment* s) // afficage d'un segment
{
    printf("\n\nx--------------------------x--------------------------x");
    printf("\nA(%.2f,%.2f)               (%.2f,%.2f)                 B(%.2f,%.2f)",s->a->x,s->a->y,s->m->x,s->m->y,s->b->x,s->b->y);
}

int calculeMilieu(float xa, float ya, float xb, float yb, float *xm, float *ym) // calcul du milieu, coordonnees du milieu changees par pointeur
{
    *xm = (xa + xb)/2.;
    *ym = (ya + yb)/2.;

    if(*xm==0 && *ym==0) // on retourne la bonne valeur en fonction de la localisation du point
        return 2;
    else if((*xm)*(*ym)==0)
        return 1;
    return 0;
}
