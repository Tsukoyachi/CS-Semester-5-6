/*******************************************************************************
Question 3 : Écrire une version du programme cat (appelée lower) qui
convertit en minuscule tous les caractère du fichier standard d'entrée sur le 
fichier standard de sortie.

ex : 
$ cat < fichier 
Un fichier avec du TEXTE
$ lower < fichier
un fichier avec du texte
*******************************************************************************/

#include <stdio.h>

void lower()
{
    char c;
    int decalage = 'A' - 'a';
    while((c = getchar()) != EOF)
    {
        if(c >= 'A' && c <= 'Z')
        {
            c-=decalage;
        }
        printf("%c",c);
    }
}

int main()
{
    lower();

    return 0;
}
