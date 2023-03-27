/*
 * Analyseur lexical du compilateur L en FLEX
 */
 
%{
#include "arbre_abstrait.h"
#include "symboles.h"
#include <string.h>
%}
%option yylineno
%option nounput
%option noinput


entier               ([1-9][0-9]*|0)
chiffre              [0-9]
lettre               [a-zA-Z]
booleen              ((Vrai)|(Faux))
alphanum             ({lettre}|{chiffre})
espace               [ \t\r\n]

%%
"#".*                { /* Ignorer commentaires */  }
{espace}+            { /* Ignorer espaces */       }
"%"                  { return MODULO;              }
"/"                  { return DIVISION;            }
"+"                  { return PLUS;                }
"-"                  { return MOINS;               }
"*"                  { return FOIS;                }
"<="                 { return INFERIEUR_OU_EGAL;   }
">="                 { return SUPERIEUR_OU_EGAL;   }
"=="                 { return EGAL;                }
"!="                 { return DIFFERENT;           }
"="                  { return AFFECTATION;         }
"<"                  { return INFERIEUR;           }
">"                  { return SUPERIEUR;           }
"("                  { return PARENTHESE_OUVRANTE; }
")"                  { return PARENTHESE_FERMANTE; }
"{"                  { return ACCOLADE_OUVRANTE;   }
"}"                  { return ACCOLADE_FERMANTE;   }
"ecrire"             { return ECRIRE;              }
"lire"               { return LIRE;                }
";"                  { return POINT_VIRGULE;       }
"tantQue"            { return TANT_QUE;            }
"si"                 { return SI;                  }
"sinon"              { return SINON;               }
"retourner"          { return RETOURNER;           }
"et"                 { return ET;                  }
"ou"                 { return OU;                  }
"non"                { return NON;                 }
","                  { return VIRGULE;             }
{entier}             { yylval.entier=atoi(yytext); return ENTIER;}
{booleen}            { 
  if(strcmp(yytext,"Vrai") == 0){
    yylval.entier = 1;
  }
  else {
    yylval.entier = 0;
  }
   return BOOLEAN;
}
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

int token_fermes[] = {MODULO,DIVISION,PLUS,MOINS,FOIS,INFERIEUR_OU_EGAL,SUPERIEUR_OU_EGAL,EGAL,DIFFERENT,AFFECTATION,INFERIEUR,SUPERIEUR,PARENTHESE_OUVRANTE,PARENTHESE_FERMANTE,ACCOLADE_OUVRANTE,ACCOLADE_FERMANTE,POINT_VIRGULE,TANT_QUE,SI,SINON,RETOURNER,ET,OU,NON,VIRGULE};
char *str_token[] = {"%","/","+","-","*","<=", ">=","==","!=","=","<",">","(",")","{","}",";","TantQue","SI","SINON","RETOURNER","ET","OU","NON",","};

int nbMotsClefs = 25;

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
    return;
  }
  if(token == BOOLEAN) {
    strcpy(nom,"booleen");
    strcpy(valeur,yytext);
  }
  if( token == IDENTIFIANT ) {
    strcpy( nom, "identifiant" );  
    strcpy( valeur, yytext );   
    return;   
  }
  if (token == ECRIRE) {
    strcpy(nom,"ecrire");
    strcpy(valeur,"ecrire");
    return;
  }
  if (token == LIRE) {
    strcpy(nom,"lire");
    strcpy(valeur,"lire");
    return;
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
