#include <stdio.h>
#include <string.h>

#define MAX_SIZE_NAME 21
#define MAX_SIZE_MAIL 41


void oteEspace(char * string)
{
    int i=0, j=0;
    for(i=0;i<=strlen(string);i++)
    {
        if(string[i]!=' ')
        {
             string[j]=string[i];
             j++;
        }
    }
}

void construitAdresseMail(char * nom, char * prenom, char * adresse)
{
    oteEspace(prenom);
    oteEspace(nom);

    if(strlen(nom)+strlen(prenom)>29)
    {
        prenom[28-strlen(nom)]='\0';
    }
    strcpy(adresse,prenom);
    strcat(adresse,".");
    strcat(adresse,nom);
    strcat(adresse,"@etu.utc.fr");
}
int main()
{
    char nom[MAX_SIZE_NAME];
    char prenom[MAX_SIZE_NAME];
    char mail[MAX_SIZE_MAIL];
    printf("\nRentrez le nom :\n");
    gets(nom);
    fflush(stdin);
    printf("\nRentrez le prenom :\n");
    gets(prenom);
    fflush(stdin);
    construitAdresseMail(nom,prenom,mail);
    printf("%s\n",mail);
    return 0;
}
