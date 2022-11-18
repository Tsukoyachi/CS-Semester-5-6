/*******************************************************************************
Question 5 : Écrire une fonction int palindrome(char *s) qui vérifie si le string
s est un palindrome ou non. Attention on ne compte pas les espace, par exemple :
"karine alla en irak" est un palindrome.
*******************************************************************************/

#include <stdio.h>
#include <string.h>

int palindrome(char *s)
{   
    int j = strlen(s)-1;
    for(int i = 0; i<=j;i++,j--)
    {
        while(*(s+i) == ' ')
        {
            i++;
        }
        while(*(s+j) == ' ')
        {
            j--;
        }
        if(*(s+i) != *(s+j))
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    printf("Le mot 'hello' est un palindrome ? %d\n",palindrome("hello"));
    printf("Le mot 'non' est un palindrome ? %d\n",palindrome("non"));
    printf("Le mot 'karine alla en irak' est un palindrome ? %d\n",palindrome("karine alla en irak"));

    return 0;
}
