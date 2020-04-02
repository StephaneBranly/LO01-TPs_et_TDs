#include <stdio.h>

int main()
{
    int depart_h, depart_m, depart_s;
    int duree_h, duree_m, duree_s;
    int arrivee_h, arrivee_m, arrivee_s;

    printf("Donnez l'horaire de depart (hh mm ss) \n");
    scanf("%d %d %d",&depart_h,&depart_m,&depart_s);

    printf("Donnez la duree du trajet (hh mm ss) \n");
    scanf("%d %d %d",&duree_h,&duree_m,&duree_s);

    arrivee_h = depart_h + duree_h;
    arrivee_m = depart_m + duree_m;
    arrivee_s = depart_s + duree_s;

    if(arrivee_s > 59)
    {
        arrivee_s %= 60;
        arrivee_m++;
    }
    if(arrivee_m > 59)
    {
        arrivee_m %= 60;
        arrivee_h++;
    }
    if(arrivee_h > 23)
    {
        arrivee_h %= 24;
    }

    printf("\n\nLe marathonien est arrive à %dh %dm %ds\n",arrivee_h,arrivee_m,arrivee_s);
    return 0;
}
