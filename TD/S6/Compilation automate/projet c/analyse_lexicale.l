/*
 * Analyseur lexical du compilateur L en FLEX
 */
 
%{
#include "arbre_abstrait.h"
#include "symboles.h"
%}
%option yylineno
%option nounput
%option noinput


entier               ([1-9][0-9]*|0)
chiffre              [0-9]
lettre               [a-zA-Z]
alphanum             ({lettre}|{chiffre})
espace               [ \t\r\n]

%%
"#".*                { /* Ignorer commentaires */  }
{espace}+            { /* Ignorer espaces */       }
"+"                  { return PLUS;                }
"*"                  { return FOIS;                }
"("                  { return PARENTHESE_OUVRANTE; }
")"                  { return PARENTHESE_FERMANTE; }
"ecrire"             { return ECRIRE;              }
";"                  { return POINT_VIRGULE;       }
{entier}             { yylval.entier=atoi(yytext); return ENTIER;}
{lettre}{alphanum}*  { return IDENTIFIANT;         }
<<EOF>>              { return FIN; }  /* Fin de fichier */
.                    {                                /* Erreur, autre caractètre quelconque */
                       fprintf( stderr, "Ligne %d: caractère invalide: %s\n", yylineno,yytext ); \
                       exit(-1); 
                     } 
%%
int yywrap(){
  return 1;
}

/*******************************************************************************
 * Fonction auxiliaire qui donne le nom des différents tokens
 ******************************************************************************/

int token_fermes[] = {PLUS,FOIS,PARENTHESE_OUVRANTE,PARENTHESE_FERMANTE,ECRIRE,POINT_VIRGULE};
char *str_token[] = {"+","*""(",")",";","ECRIRE"};

int nbMotsClefs = 5;

void nom_token( int token, char *nom, char *valeur ) {   

  for(int i = 0; i < nbMotsClefs;i++){
  	if(token == token_fermes[i]){
  	  strcpy( nom, "symbole" );
  	  strcpy( valeur, str_token[i]);
  	  return;
  	}
  }
  
  if( token == ENTIER ) {
    strcpy( nom, "entier" );
    strcpy( valeur, yytext );
  }
  else if( token == IDENTIFIANT ) {
    strcpy( nom, "identifiant" );  
    strcpy( valeur, yytext );      
  }
}

/*******************************************************************************
 * Fonction auxiliaire appelée par le compilateur en mode -l pour tester l'analyse
 * lexicale. Le fichier source doit être indiqué dans la variable globale yyin.
 * Cette fonction imprime le résultat de l'analyse lexicale sur la sortie standard.
 ******************************************************************************/
void afficher_analyse_lexicale() {
  int uniteCourante;
  char nom[100];
  char valeur[100]; 
    uniteCourante = yylex();  
  while (uniteCourante != FIN) {
    nom_token( uniteCourante, nom, valeur );
    printf("%s\t%s\t%s\n", yytext, nom, valeur);
    uniteCourante = yylex(); 
  } 
}
