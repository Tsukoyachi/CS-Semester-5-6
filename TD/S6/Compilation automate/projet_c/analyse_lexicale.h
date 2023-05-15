#ifndef __LIRE_UNITE__
#define __LIRE_UNITE__

#include "stdio.h"

int yylex(void);
void nom_token( int token, char *nom, char *valeur );
void afficher_analyse_lexicale();

#endif
