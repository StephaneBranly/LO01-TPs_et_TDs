#include <stdio.h>

int main()
{
    float min,a,b,c,d;
    printf("Donnez 5 nombres, nous vous donnerons le minimum\n\n");
    scanf("%f %f %f %f %f",&min,&a,&b,&c,&d);
    //scanf("FORMAT",&variable):
    // %d -> entier , %f -> float

    if(a<min)
        min=a;

    if(b<min)
        min=b;

    if(c<min)
        min=c;

    if(d<min)
        min=d;

    printf("\nVoici le nombre minimum : %f \n",min);
    return 0;
}
