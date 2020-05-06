#include <stdio.h>


void ordre(int*a, int*b, int*c)
{
    if(*a>*b)
        permute(a,b);
    if(*b>*c)
        permute(b,c);
    if(*a>*b)
        permute(a,b);
}

void permute(int *a, int *b)
{
    int tmp=*a;
    *a=*b;
    *b=tmp;
}

int main()
{
    int a,b,c;
    printf("Rentrez a b c\n> ");
    scanf("%d%d%d",&a,&b,&c);
    printf("\nOrdre a b c actuel (%d,%d,%d)\n",a,b,c);
    ordre(&a,&b,&c);
    printf("\nOrdre a b c apres appel fonction (%d,%d,%d)\n",a,b,c);
    return 0;
}
