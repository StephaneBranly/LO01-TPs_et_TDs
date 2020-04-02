#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c, delta,zede1,zede2,reel,imaginaire;
    printf("Nous avons une équation de la forme ax^2 + bx+ c = 0\n");
    printf("Donnez le coefficient a\n");
    scanf("%f",&a);

    printf("Donnez le coefficient b\n");
    scanf("%f",&b);

    printf("Donnez le coefficient c\n");
    scanf("%f",&c);

    printf("\n");
    if(a==0){
        if(b==0)
            printf("Il n y a pas de solution a cette equation.");
        else
            printf("Il s agit d une equation du premier degre, la solution est : x=%f",-c/b);
    }
    else{
        delta=b*b-4*a*c;
        printf("Le delta est de %f",delta);
        if(delta==0)
        {
            printf("\n\nLe delta est nul, une seule solution");
            zede1=-b/(2*a);
            printf("\nVoici l'unique solution : \nx1=%f\n",zede1);
        }
        else
            if(delta>0)
            {
                printf("\n\nLe delta est positif (et strictement superieur a 0), deux solutions reelles");
                zede1=(-b-sqrt(delta))/(2*a);
                zede2=(-b+sqrt(delta))/(2*a);

                printf("\nVoici les 2 solutions : \nx1=%f\nx2=%f",zede1,zede2);
            }
            else
            {
                printf("\n\nLe delta est negatif (et strictement inferieur a 0), deux solutions complexes");
                reel=-b/(2*a);
                imaginaire=(sqrt(fabs(delta)))/(2*a);
                printf("\nVoici les 2 solutions : \nz1=%f + %fi\nz2=%f + %fi",reel,-imaginaire,reel,imaginaire);
            }
    }

    return 0;
}
