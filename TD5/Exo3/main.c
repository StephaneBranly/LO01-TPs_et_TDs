#include <stdio.h>

int main(){
    char current_char, last_char=' ';
    int compteur = 0;

    while((current_char=getchar())!='.')
    {
        if(last_char==current_char)
            printf("\n%c double en position %d et %d",current_char,compteur,compteur+1);
        compteur++;
        last_char=current_char;
    }

    printf("\nle mot contient %d lettre(s)",compteur);
    return 0;
}
