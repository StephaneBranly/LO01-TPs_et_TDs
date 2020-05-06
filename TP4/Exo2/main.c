#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"

int main()
{
    // init
    float continuer=1;
    chaine* tete;
    chaine* current_chaine;
    chaine* old_chaine;
    segment* current_segment;

    int i=0;
    do
    {
        current_segment=demanderSegment(i); // on demande à l'utilisateur d'entrer un segment
        current_chaine=creerChaine(current_segment); // on ajoute une chaine à notre liste chainée
        if(i==0)
            tete=current_chaine; // s'il s'agit de la première chaine, on l'enregistre en tant que tete de liste
        else
            old_chaine->p=current_chaine; // sinon on s'assure de bien lier les chaines entre elles
        old_chaine=current_chaine;
        printf("\nVoulez vous ajouter un autre segment ? (NON-0 ; OUI-1)");
        continuer=demanderValeur('c');
        i++;
    }
    while(continuer);

    current_chaine=tete; // on demarre à la tete de liste
    int compteur_origine=0, compteur_axe=0, compteur_autre=0;
    while(current_chaine!=NULL) // on parcours toute la liste chainee tant que la chaine actuelle est non NULL
    {
        afficherSegment(current_chaine->s); // affichage du segment
        if(current_chaine->s->milieu==2) // on compte suivant où se situe le milieu
            compteur_origine++;
        else if(current_chaine->s->milieu==1)
            compteur_axe++;
        else
            compteur_autre++;
        old_chaine=current_chaine; //on enregistre la localisation de l'ancienne chaine
        current_chaine=current_chaine->p; // on passe à la prochaine chaine
        free(old_chaine->s->a); // on supprimer et libere l'espace ce toutes les informations de l'ancienne chaine
        free(old_chaine->s->b);
        free(old_chaine->s->m);
        free(old_chaine->s);
        free(old_chaine);
    }

    printf("\n\nIl y a %d milieu(x) confondu avec l'origine, %d appartenant a un seul des deux axes et %d situes autre part.",compteur_origine,compteur_axe,compteur_autre);
    return 0;
}
