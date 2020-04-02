#include <stdio.h>

int main()
{
    int type=0, sexe=0, age=0, statut=0;
    float tarif, reduction=1, majoration=1;
    while(type != 1 && type != 2 && type != 3)
    {
        printf("\nQuel type de couverture souhaitez vous?\n1 (300 euros)\n2 (400 euros)\n3 (450 euros)\n");
        scanf("%d",&type);
    }

    while(sexe != 1 && sexe != 2 && sexe != 3)
    {
        printf("\nQuel est votre sexe ?\n1 - homme\n2 - femme\n3 - autre\n");
        scanf("%d",&sexe);
    }

    printf("\nQuel age avez-vous ?\n");
    scanf("%d",&age);

    while(statut != 1 && statut != 2)
    {
        printf("\nQuel est votre statut ?\n1 - etudiant\n2 - chomeur\n");
        scanf("%d",&statut);
    }

    switch(type)
    {
        case 1:
            tarif=300;
            break;
        case 2:
            tarif=400;
            break;
        case 3:
            tarif=450;
            break;
        default:
            printf("\n! Il doit y avoir une erreur dans le type de couverture indique...\n");
            break;
    }

    if(statut==2 && reduction>0.9)
        reduction=0.9;
    else if(age>25 && statut==1)
        reduction=0.8;
    else if(sexe==2)
        reduction=0.75;
    else if(age>=17 && age <= 25)
    {
        if(statut==1)
            reduction=0.5;
        else
            reduction=0.7;
    }

    if(age>=60)
        majoration=1.1;
    else if(age<=21)
        majoration=1.2;

    printf("\nTarif initial de %f euros", tarif);
    printf("\nVous avez une reduction de %f pourcents",(1-reduction)*100);
    printf("\nVous avez une majoration de %f pourcents",(majoration-1)*100);
    tarif *= reduction;
    tarif *= majoration;
    printf("\nTarif final (avec prise en compte de majoration et reduction) de %f euros\n\n", tarif);
    return 0;
}
