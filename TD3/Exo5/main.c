#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c, delta,zede1,zede2;
    printf("Nous avons une équation de la forme ax^2 + bx+ c = 0\n");
    printf("Donnez le coefficient a\n");
    scanf("%f",&a);

    printf("Donnez le coefficient b\n");
    scanf("%f",&b);

    printf("Donnez le coefficient c\n");
    scanf("%f",&c);

    delta=b*b-4*a*c;

    if(delta==0)
    {
        zede1=-b/(2*a);
        printf("\nVoici l'unique solution : \nx1=%f\n",zede1);
    }
    else
        if(delta>0)
        {
            zede1=(-b-sqrt(delta))/(2*a);
            zede2=(-b+sqrt(delta))/(2*a);

            printf("\nVoici les 2 solutions : \nx1=%f\nx2=%f",zede1,zede2);
        }
        else
            printf("\nLe delta de cette equation est negatif :(");

    return 0;
}
