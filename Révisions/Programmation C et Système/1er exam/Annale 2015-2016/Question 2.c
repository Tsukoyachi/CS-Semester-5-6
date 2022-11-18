/*******************************************************************************
Question 2 : Verificateur d'accolades ouvrantes et fermantes dans un code,
renvoie 0 si faux, 1 sinon.
Précisions :
- Pas d'accolades dans les commentaires du code à analyser.
- Si l'on a 3 accolades fermantes suivi de 3 accolades ouvrantes ça ne fonctionne pas.
*******************************************************************************/
#include <stdio.h>


int accolades(void)
{
    int compteur = 0; char c;
    while((c= getchar()) != EOF)
    {
        if(c == '}')
        {
            compteur--;
        }
        if(compteur<0)
        {
            return 0;
        }
        if(c == '{')
        {
            compteur++;
        }
    }
    if(compteur == 0)
    {
        return 1;
    }
    return 0;
}

int main ()
{
  printf("La fonction a retourné %d",accolades());
  return 0;
}