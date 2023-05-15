#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arbre_abstrait.h"
#include "symboles.h"
#include "analyse_lexicale.h"
#include "generation_code.h"




/* 
* Variable globale qui va indiquer à l'analyseur lexical quel fichier source lire.
* Cette variable est défini dans analyse_lexicale.c (qui est le resultat de la compilation avec flex de analyse_lexicale.l)
*/
extern FILE *yyin;
extern n_programme* arbre_abstrait;
extern int afficher_nasm;

/*
* Fonction qui affiche les options de compilation
* Sera complété au fur et à mesure du projet.
*/
void affiche_message_aide(char *nom_prog)
{
  fprintf(stderr, "usage: %s OPT fichier_source\n", nom_prog);
  fprintf(stderr, "\t-l affiche l'analyse lexicale\n");
  fprintf(stderr, "\t-a affiche l'arbre arbstrait\n");
  fprintf(stderr, "\t-n affiche le code nasm\n");
  fprintf(stderr, "\t-h affiche ce message\n");


}

int main(int argc, char **argv) {
  int affiche_lex = 0;
  int affiche_arbre_abstrait = 0;
  
  if(argc <= 2 || argc > 3){
    affiche_message_aide(argv[0]);
    exit(1);
  }

    if(!strcmp(argv[1], "-l")) {
       affiche_lex = 1;
    }
    else if(!strcmp(argv[1], "-h")){
       affiche_message_aide(argv[0]);
       exit(1);
    }
    else if(!strcmp(argv[1], "-a")) {
       affiche_arbre_abstrait = 1;
    }
    else if(!strcmp(argv[1], "-n")) {
    	afficher_nasm = 1;
    }
    else {
    	affiche_message_aide(argv[0]);
   	exit(1);
    }
    
	yyin = fopen(argv[2], "r");
	if(yyin == NULL){
	fprintf(stderr, "impossible d'ouvrir le fichier %s\n", argv[2]);
	exit(1);
	}
    
  
  if(affiche_lex == 1) {
    afficher_analyse_lexicale();
    exit( 0 );
  }
  
  yyparse();
  
  if(affiche_arbre_abstrait == 1) {
    afficher_n_programme(arbre_abstrait,0);
    exit( 0 );
  } 
  
  nasm_prog(arbre_abstrait);

  return 0;
} 

