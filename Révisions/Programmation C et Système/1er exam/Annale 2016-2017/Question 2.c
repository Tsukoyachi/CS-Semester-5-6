/*******************************************************************************
Question 2 : Écrire une méthode void imprimer(char *s, ...) qui prendra en entrée
à chaque indice impaire un string, à chaque indice pair un int, et qui se finira 
par un string qui vaut NULL, donc qui aura un nombre impair d'argument.
La méthode devra alors afficher tous les arguments.
exemple : imprimer("Valeur de x=",3,NULL) -> Valeur de x=3
*******************************************************************************/

#include <stdio.h>
#include <stdarg.h>

void imprimer(char *s, ...)
{
    va_list ap;
    char *str = s;
    for(va_start(ap,s); str; str = va_arg(ap,char *))
    {
        printf("%s%d",str,va_arg(ap,int));
    }
    
    va_end(ap);
}

int main()
{
    imprimer("Valeur de x=",3,", valeur de y=",4,", donc valeur de x+y=",7,NULL);

    return 0;
}