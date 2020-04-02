#include <stdio.h>
#define MAX 11
int main()
{
    int i,j;

    printf("\t");
    for(i=1;i<=MAX;i++) printf("\t%d",i);

    printf("\n");

    for(i=0;i<MAX+1;i++)printf("\t*");

    for(i=1;i<=MAX;i++)
    {
        printf("\n%d\t*\t",i);
        for(j=1;j<=MAX;j++)
        {
            if(j==i || j==5)
                printf("%d",j*i);
            printf("\t");
        }
    }

    printf("\n");
    return 0;
}
