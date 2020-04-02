#include <stdio.h>

int main()
{
    int nbr_Aa=0;;
    char c;

    do
    {
        fflush(stdin);
        printf("Rentrez un caractere :\n> ");
        c = getchar();

        if(c=='a' || c=='A')
            nbr_Aa++;
    }while(c!='.');

    printf("\nNombre de Aa:%d",nbr_Aa);
    return 0;
}
