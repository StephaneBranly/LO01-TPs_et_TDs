#include <stdio.h>

int main()
{
    int i;
    float min, current;
    printf("Rentrez un nombre :\n> ");
    scanf("%f",&min);
    for(i=0;i<49;i++)
    {
        printf("Rentrez un nombre :\n> ");
        scanf("%f",&current);
        if(current<min)
            min=current;
    }

    printf("\nLe plus petit nombre est %f",min);
    return 0;
}
