%{
#include <stdlib.h>
#include <stdio.h>
#include "arbre_abstrait.h"
#include "analyse_lexicale.h"


//n_programme* yyparse();
int yylex();
int yyerror(const char *s);
n_programme* arbre_abstrait;
%}

%union {
    int entier;
    n_programme* prog;
    n_l_instructions* l_inst;
    n_instruction* inst;
    n_exp* exp;
}


%define parse.error detailed
%define parse.lac full
//Symboles terminaux qui seront fournis par yylex(), ordre non important

%token MODULO
%token DIVISION
%token PLUS
%token MOINS
%token FOIS
%token INFERIEUR_OU_EGAL
%token SUPERIEUR_OU_EGAL
%token EGAL
%token DIFFERENT
%token AFFECTATION
%token INFERIEUR
%token SUPERIEUR
%token PARENTHESE_OUVRANTE
%token PARENTHESE_FERMANTE
%token ACCOLADE_OUVRANTE
%token ACCOLADE_FERMANTE
%token POINT_VIRGULE
%token TANT_QUE
%token SI
%token SINON
%token RETOURNER
%token ET
%token OU
%token NON
%token VIRGULE
%token <entier> BOOLEAN
%token <entier> ENTIER
%token ECRIRE
%token LIRE
%token IDENTIFIANT
%token FIN 0

%type <prog> prog
%type <l_inst> listeInstructions
%type <inst> instruction
%type <inst> ecrire
%type <exp> lire
%type <exp> expr
%type <exp> facteur
%type <exp> produit
%%

prog: listeInstructions {
arbre_abstrait =creer_n_programme($1);
} 

listeInstructions: instruction {
$$ =creer_n_l_instructions($1 ,NULL);
} 

listeInstructions: instruction listeInstructions {
$$ =creer_n_l_instructions($1 ,$2);
} 

instruction: ecrire {
	$$ =$1;
}


ecrire: ECRIRE PARENTHESE_OUVRANTE expr PARENTHESE_FERMANTE POINT_VIRGULE {
	
	$$ =creer_n_ecrire($3);
}
expr: expr PLUS produit{
	$$ =creer_n_operation('+', $1, $3);
}

expr: expr FOIS facteur{
	$$ =creer_n_operation('*', $1 , $3);
}

produit : produit FOIS facteur {
    $$ =creer_n_operation('*',$1,$3);
}

produit : produit DIVISION facteur {
    $$ =creer_n_operation('/',$1,$3);
}

produit : produit MODULO facteur {
    $$ =creer_n_operation('%',$1,$3);
}

expr: PARENTHESE_OUVRANTE expr PARENTHESE_FERMANTE {
	$$ =$2 ;
}

expr: produit {
    $$= $1;
}

produit : facteur {
    $$ = $1;
}

facteur : lire {
    $$ = $1;
}

facteur: ENTIER {
	$$ = creer_n_entier($1);
}

lire: LIRE PARENTHESE_OUVRANTE PARENTHESE_FERMANTE {
    $$ = creer_lire();
}


%%

int yyerror(const char *s) {
    printf("yyerror : %s\n",s);
    return 0;
}

