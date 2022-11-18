/*******************************************************************************
Question 1  Écrire la fonction void shuffle(char str) qui mélange les caractères
de la chaîne str par tirage au sort à l'aide de la fonction rand().
*******************************************************************************/
#include stdio.h
#include string.h
#include stdlib.h


void shuffle (char s)
{
  char tmp;
  int tmp_index;
  int size = strlen (s);
  for (int i = 0; i  size; i++)
    {
      tmp = (s + i);
      tmp_index = rand () % size;
      (s + i) = (s + tmp_index);
      (s + tmp_index) = tmp;
    }
}

int main ()
{
  char s[] = Hello world;
  shuffle (s);
  printf (%s, s);
  return 0;
}
