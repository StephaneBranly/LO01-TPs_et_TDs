#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

// On cree nos structures, point et segment propres à l'exercice, chaine servant à l'execution et l'enregistrement dans le main
typedef struct point{
    float x,y;
} point;

typedef struct segment{
    point* a;
    point* b;
    point* m; // point du milieu
    int milieu;
} segment;

typedef struct chaine{
    segment* s; // segment
    struct chaine* p; // prochaine chaine
} chaine;

// entetes des fonctions utilisées
point* creerPoint(float, float);
segment* creerSegment(point*, point*);
chaine* creerChaine(segment*);
float demanderValeur(char);
point* demanderPoint(char);
segment* demanderSegment(int);
void afficherSegment(segment*);
int calculeMilieu(float, float, float, float, float *, float *);


#endif // FONCTIONS_H_INCLUDED


