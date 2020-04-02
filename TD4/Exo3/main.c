#include <stdio.h>

int main()
{
    float mult=1, current=1;

    do
    {
        mult*=current;
        printf("Rentrez un nombre :\n> ");
        scanf("%f",&current);
    }while(current);

    printf("\nLe multiple global est %f",mult);
    return 0;
}
