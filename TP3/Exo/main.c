#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COUT_KEROSENE 1.2
#define NBR_PLACES 800
#define DECOUPAGE_CLASSE 32

float calcul_cout_voyage(int distance, int cout_fixe)
{
    return cout_fixe +(1200/100*distance*COUT_KEROSENE);
}

void affichage_combinaisons(int distance, int cout_fixe, int prix_premiere, int prix_affaire, int prix_eco, int vol_premiere, int vol_affaire, int vol_eco)
{

    float cout = calcul_cout_voyage(distance,cout_fixe);
    float prix_place;
    int i,j,k,places_premiere, places_affaire, places_eco;

    printf("\nDistance du vol (km) : %d",distance);
    printf("\nPrix du vol : %.2f\n",cout);

    printf("\nPrix du billet en premiere classe\t: %d",prix_premiere);
    printf("\nPrix du billet en classe affaire\t: %d",prix_affaire);
    printf("\nPrix du billet en classe economique\t: %d\n",prix_eco);

    printf("\n# Premiere\t|# Affaire\t|# Economique\t|\tTotal");
    printf("\n--------------------------------------------------------------------");

    for(i=0;i<=(NBR_PLACES/DECOUPAGE_CLASSE);i++)
    {
        places_premiere = i*DECOUPAGE_CLASSE;
        for(j=0;j<=(NBR_PLACES/DECOUPAGE_CLASSE);j++)
        {
            places_affaire = j*DECOUPAGE_CLASSE;
            for(k=0;k<=(NBR_PLACES/DECOUPAGE_CLASSE);k++)
            {
                places_eco = k*DECOUPAGE_CLASSE;
                if(places_premiere+places_eco+places_affaire<=NBR_PLACES)
                {
                    prix_place = places_affaire/vol_affaire * prix_affaire + places_premiere/vol_premiere * prix_premiere + places_eco/vol_eco * prix_eco;
                    if(prix_place<=(2*cout) && prix_place>=cout)
                        printf("\n\t%d\t|\t%d\t|\t%d\t|\t%.2f",places_premiere/vol_premiere,places_affaire/vol_affaire,places_eco/vol_eco,prix_place);
                }
            }
        }
    }
}


void affichage_combinaison_proba(int distance, int prix_premiere, int prix_affaire, int prix_eco)
{
    srand(time(NULL));
    int i,randomNumber;
    int places_premiere=0, places_affaire=0, places_eco=0;
    float prix_place;
    for(i=0;i<=NBR_PLACES;i++)
    {
        randomNumber=rand()%100;
        if(randomNumber>=20 && randomNumber<=50)
            places_premiere++;
        else if(randomNumber>=40 && randomNumber<=80)
            places_affaire++;
        else if(randomNumber>=60 && randomNumber<=95)
            places_eco++;
    }
    printf("\nDistance du vol (km) : %d",distance);

    printf("\nPrix du billet en premiere classe\t: %d",prix_premiere);
    printf("\nPrix du billet en classe affaire\t: %d",prix_affaire);
    printf("\nPrix du billet en classe economique\t: %d\n",prix_eco);

    printf("\n# Premiere\t|# Affaire\t|# Economique\t|\tTotal");
    printf("\n--------------------------------------------------------------------");
    prix_place = places_affaire * prix_affaire + places_premiere * prix_premiere + places_eco * prix_eco;
    printf("\n\t%d\t|\t%d\t|\t%d\t|\t%.2f",places_premiere,places_affaire,places_eco,prix_place);
}


int main() {
    int distance, cout_fixe, prix_premiere, prix_affaire, prix_eco, choix, result;

    do
    {
        printf("Rentrez la distance a parcourir\n> ");
        result=scanf("%d",&distance);
        fflush(stdin);
    }while(result==0 || distance<=0);

    do
    {
        printf("Rentrez le cout fixe\n> ");
        result=scanf("%d",&cout_fixe);
        fflush(stdin);
    }while(result==0 || cout_fixe<=0);

    do
    {
        printf("\nRentrez le prix du billet en premiere classe\n> ");
        result=scanf("%d",&prix_premiere);
        fflush(stdin);
    }while(result==0 || prix_premiere<=0);

    do
    {
        printf("Rentrez le prix du billet en classe affaire\n> ");
        result=scanf("%d",&prix_affaire);
        fflush(stdin);
    }while(result==0 || prix_affaire<=0);

    do
    {
        printf("Rentrez le prix du billet en classe economique\n> ");
        result=scanf("%d",&prix_eco);
        fflush(stdin);
    }while(result==0 || prix_eco<=0);

    do
    {
        printf("\n\nQuelle methode voulez-vous utiliser ?\nMethode q2 - 2\nMethode q3 - 3\nMethode q4 - 4\n> ");
        scanf("%d",&choix);
        fflush(stdin);
    }while(choix!=2 && choix!=3 && choix!=4);


    switch(choix){
        case 2: //QUESTION 2
            printf("\n## Utilisation de la methode q2 ##");
            affichage_combinaisons(distance,cout_fixe,prix_premiere,prix_affaire,prix_eco,1,1,1);
            break;
        case 3: //QUESTION 3
            printf("\n## Utilisation de la methode q3 ##");
            affichage_combinaisons(distance,cout_fixe,prix_premiere,prix_affaire,prix_eco,8,4,1);
            break;
        case 4: //QUESTIO 4
            printf("\n## Utilisation de la methode q4 ##");
            affichage_combinaison_proba(distance,prix_premiere,prix_affaire,prix_eco);
            break;
        default:
            break;
    }

    return 0;
}
