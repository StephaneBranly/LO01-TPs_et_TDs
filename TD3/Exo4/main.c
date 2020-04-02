#include <stdio.h>

int main()
{
    char type = 'a';
    float r1, r2, r3, req;

    printf("\nChoisissez le type de montage\np - Parallele\ns - Serie\n");
    scanf("%c",&type);

    printf("\nRentrez la valeur des résistances r1 r2 r3\n");
    scanf("%f %f %f",&r1,&r2,&r3);

    if(type=='p')
    {
        if(r1*r2*r3 == 0)
            req = 0;
        else
        {
            req = 1/(1/r1 + 1/r2 + 1/r3);
        }
        printf("\nLa valeur de la resistance equivalente pour un montage en parallele est de %f \n",req);
    }
    else
    {
        req = r1 + r2 + r3;
        printf("\nLa valeur de la resistance equivalente pour un montage en serie est de %f \n",req);
    }

    return 0;
}
