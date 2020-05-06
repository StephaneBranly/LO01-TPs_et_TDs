#include <stdio.h>


int main(){
    int *pmin;
    int n1,n2,n3;

    printf("Entrez trois nombres\n> ");
    scanf("%d %d %d",&n1,&n2,&n3);

    pmin=&n1;

    if(*pmin>n2)
        pmin=&n2;
    if(*pmin>n3)
        pmin=&n3;


    printf("\nLe nombre minimum vaut %d",*pmin);
    return 0;
}
