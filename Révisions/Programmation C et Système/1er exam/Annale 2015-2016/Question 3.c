/*******************************************************************************
Question 3 : Écrire fonction void rot13(char *s) qui applique un algo de 
chiffrement de texte de type César avec un décalage de 13.
Or un l'alphabet contient 26 lettres donc pour les 13 premieres à avance de 13 
dans la table ASCII et pour les 13 derniers on recule de 13.
*******************************************************************************/
#include <stdio.h>


void rot13(char *s)
{
    char *tmp_pointeur = s;
    char tmp;
    for(int i = 0; tmp = *(s+i); i++)
    {
        if((tmp >= 'a' && tmp <= 'n') || (tmp >= 'A' && tmp <= 'N'))
        {
           *(s+i) += 13; 
        }
        else if((tmp >= 'm' && tmp <= 'z') || (tmp >= 'M' && tmp <= 'Z'))
        {
           *(s+i) -= 13; 
        }
        s++;
    }
    s = tmp_pointeur;
}

int main ()
{
  char s[] = "Hello world !123";
  printf("Ma chaine : %s\n",s);
  rot13(&s);
  printf("Ma chaine cryptée : %s\n",s);
  rot13(&s);
  printf("Ma chaine decryptée : %s\n",s);
}