#include <stdio.h>

const float pi = 3.14159265;
int main()
{
    float r, surface, volume;
    printf("Donnez le rayon de la sphere \n");
    scanf("%f",&r);

    surface = 4.*pi*r*r;
    volume = (4./3.)*pi*r*r*r;
    printf("La surface de la sphere est de %f \n",surface);
    printf("Le volume de la sphere est de %f \n",volume);
    return 0;
}
