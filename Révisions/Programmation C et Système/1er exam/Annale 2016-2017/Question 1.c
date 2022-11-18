/*******************************************************************************
Question 1 : Écrire une méthode int mystrspn(const char *s, const char *accept)
qui retourne la taille de la plus grande chaîne de caractère en début de s
réalisable à l'aide des caractères de accept.
Exemple : mystrspn("these","the") -> 3 car il y a un s après.
*******************************************************************************/

#include <stdio.h>
#include <string.h>

int isin(const char c, const char *str)
{
    for(int i = 0;i< strlen(str);i++)
    {
        if(c == *(str+i)){
            return 1;
        }
    }
    return 0;
}

int mystrspn(const char s[], const char accept[])
{
    int compteur = 0; char c;
    while(isin(c = *s++,accept))
    {
        compteur++;
    }
    return compteur;
}

int main()
{
    char str[] = "essai";
    printf("%d\n",mystrspn(str,"es"));
    printf("%d\n",mystrspn(str,"se"));
    printf("%d\n",mystrspn(str,"asze"));
    printf("%d\n",mystrspn(str,"xyz"));

    return 0;
}