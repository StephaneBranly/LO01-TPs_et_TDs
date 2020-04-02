#include <stdio.h>

int main(){
    int u0,u1,u2,i=2;

    printf("u0=");
    scanf("%d",&u0);

    printf("u1=");
    scanf("%d",&u1);

    while(i<19 && ((u2=u0+u1)<1000))
    {
        printf("u%d=%d\n",i,u2);
        u0=u1;
        u1=u2;
        i++;
    }
    return 0;
}
