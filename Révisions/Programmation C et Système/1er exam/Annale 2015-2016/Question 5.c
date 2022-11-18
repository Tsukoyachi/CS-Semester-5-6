/*******************************************************************************
Question 5 : On appelle nombre de Harshad un nombre divisible par la somme de ses 
chiffres. Par exemple : 12 est divisble par 3 (= 1+2).
Ecrivez la fonction harshad qui vérifie si l'entier passé en paramètre est un 
nombre de harshad ou pas.
*******************************************************************************/
#include <stdio.h>


int harshad(int n)
{   
    if(n == 0)
    {
        return 0;
    }
    if(n < 0)
    {
        n = -n;
    }
    int tmp = 0;
    for(int k = n; k>=1;k/=10)
    {
        tmp += k%10;
    }
    return (n%tmp) == 0;
}

int main ()
{
    printf("Le nombre 0 est un nombre de Harshard ? %d\n",harshad(0));
    printf("Le nombre 12 est un nombre de Harshard ? %d\n",harshad(12));
    printf("Le nombre -12 est un nombre de Harshard ? %d\n",harshad(12));
    printf("Le nombre 99 est un nombre de Harshard ? %d\n",harshad(99));
    printf("Le nombre -99 est un nombre de Harshard ? %d\n",harshad(-99));
    return 0;
}