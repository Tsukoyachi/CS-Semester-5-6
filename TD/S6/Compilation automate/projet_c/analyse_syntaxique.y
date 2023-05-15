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
    int booleen;
    char *name;
    n_programme* prog;
    n_l_instructions* l_inst;
    n_instruction* inst;
    n_exp* exp;
    l_argument* l_arg;
}

%define parse.lac full
//Symboles terminaux qui seront fournis par yylex(), ordre non important

%token MODULO
%token DIVISION
%token PLUS
%token TYPE_ENTIER
%token TYPE_BOOLEEN
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
%token SINON_SI
%token RETOURNER
%token ET
%token OU
%token NON
%token VIRGULE
%token <entier> BOOLEAN
%token <entier> ENTIER
%token ECRIRE
%token LIRE
%token <name> IDENTIFIANT
%token FIN 0

%type <prog> prog
%type <l_inst> listeInstructions
%type <inst> instruction
%type <inst> ecrire
%type <inst> declaration
%type <inst> conditionnelle
%type <inst> listeSinonSi
%type <exp> lire
%type <exp> expr
%type <exp> facteur
%type <exp> somme
%type <exp> produit
%type <exp> variable
%type <exp> fonction
%type <exp> logical
%type <l_arg> listeArgument
%type <exp> argument
%type <exp> booleen
%%

prog: listeInstructions {
arbre_abstrait =creer_n_programme($1);
} 

listeInstructions
    : instruction {
        $$ =creer_n_l_instructions($1 ,NULL);
    } 
    | instruction listeInstructions {
        $$ =creer_n_l_instructions($1 ,$2);
    } 

instruction
    : ecrire {
	    $$ =$1;
    }
    | declaration {
	    $$ =$1;
    }
    | conditionnelle {
		$$ =$1;
	}
    
ecrire
    : ECRIRE PARENTHESE_OUVRANTE expr PARENTHESE_FERMANTE POINT_VIRGULE {
	    $$ =creer_n_ecrire($3);
    }

conditionnelle
	: SI PARENTHESE_OUVRANTE booleen PARENTHESE_FERMANTE ACCOLADE_OUVRANTE listeInstructions ACCOLADE_FERMANTE {
		$$ =creer_n_conditionnelle($3, $6, NULL, NULL);
	}
	| SI PARENTHESE_OUVRANTE booleen PARENTHESE_FERMANTE ACCOLADE_OUVRANTE listeInstructions ACCOLADE_FERMANTE SINON ACCOLADE_OUVRANTE listeInstructions ACCOLADE_FERMANTE {
		$$ =creer_n_conditionnelle($3, $6, NULL, $10);
	}
	| SI PARENTHESE_OUVRANTE booleen PARENTHESE_FERMANTE ACCOLADE_OUVRANTE listeInstructions ACCOLADE_FERMANTE listeSinonSi {
		$$ =creer_n_conditionnelle($3, $6, $8, NULL);
	}
	| SI PARENTHESE_OUVRANTE booleen PARENTHESE_FERMANTE ACCOLADE_OUVRANTE listeInstructions ACCOLADE_FERMANTE listeSinonSi SINON ACCOLADE_OUVRANTE listeInstructions ACCOLADE_FERMANTE {
		$$ =creer_n_conditionnelle($3, $6, $8, $11);
    }

listeSinonSi
	: SINON_SI PARENTHESE_OUVRANTE booleen PARENTHESE_FERMANTE ACCOLADE_OUVRANTE listeInstructions ACCOLADE_FERMANTE {
		$$ =creer_n_conditionnelle($3, $6, NULL, NULL);
	}
	| SINON_SI PARENTHESE_OUVRANTE booleen PARENTHESE_FERMANTE ACCOLADE_OUVRANTE listeInstructions ACCOLADE_FERMANTE listeSinonSi {
		$$ =creer_n_conditionnelle($3, $6, $8, NULL);
	}

declaration
	: TYPE_ENTIER IDENTIFIANT POINT_VIRGULE  {
		$$ = creer_n_declaration(creer_variable_entier($2, NULL));
	}
	| TYPE_BOOLEEN IDENTIFIANT POINT_VIRGULE {
		$$ = creer_n_declaration(creer_variable_boolean($2, NULL));
	}
    | TYPE_BOOLEEN IDENTIFIANT AFFECTATION BOOLEAN POINT_VIRGULE {
		$$ = creer_n_declaration_affectation(creer_variable_boolean($2, $4));
	}
    | TYPE_ENTIER IDENTIFIANT AFFECTATION ENTIER POINT_VIRGULE {
		$$ = creer_n_declaration_affectation(creer_variable_entier($2, $4));
	}
    | IDENTIFIANT AFFECTATION ENTIER POINT_VIRGULE {
        $$ = creer_n_affectation(creer_variable_entier($1, $3));
    }
    | IDENTIFIANT AFFECTATION BOOLEAN POINT_VIRGULE {
        $$ = creer_n_affectation(creer_variable_boolean($1, $3));
    }

argument
    : expr {
        $$ = $1;
    }

expr
    : booleen {
        $$ = $1;
    }

booleen
    : somme {
        $$ = $1;
    }
    | BOOLEAN {
        $$ = creer_n_booleen($1);
    }
    | produit {
        $$ = $1;
    }
    | logical ET logical {
		$$ = creer_n_operation("&&", $1, $3);
	}
	| logical OU logical {
		$$ = creer_n_operation("||", $1, $3);
	}
    | logical {
		$$ = $1;
	}
    | facteur {
        $$ = $1;
    }
    | variable {
        $$ = $1;
    }
    | somme INFERIEUR somme {
        $$ = creer_n_operation("<",$1,$3);
    }
    | somme SUPERIEUR somme {
        $$ = creer_n_operation(">",$1,$3);
    }
    | somme EGAL somme {
        $$ = creer_n_operation("==",$1, $3);
    }
    | somme DIFFERENT somme {
        $$ = creer_n_operation("!=",$1, $3);
    }    
    | somme SUPERIEUR_OU_EGAL somme {
        $$ = creer_n_operation(">=",$1, $3);
    }
    | somme INFERIEUR_OU_EGAL somme {
        $$ = creer_n_operation("<=",$1, $3);
    }
    | NON booleen {
		$$ = creer_n_operation_non("!", $2);
	}

logical
    : booleen {
        $$ = $1;
    }
somme
    : produit {
        $$ = $1;
    }
    | somme PLUS produit {
        $$ =creer_n_operation("+", $1, $3);
    }
    | somme MOINS produit {
        $$ = creer_n_operation("-",$1, $3);
    }

produit
    : facteur {
        $$ = $1;
    }
    | produit FOIS facteur {
        $$ =creer_n_operation("*",$1,$3);
    }
    | produit DIVISION facteur {
        $$ =creer_n_operation("/",$1,$3);
    }
    | produit MODULO facteur {
        $$ =creer_n_operation("%",$1,$3);
    }
    | MOINS facteur {
        $$ = creer_n_operation("*",creer_n_entier(-1),$2);
    }

facteur
    : variable {
        $$ = $1;
    }
    | lire {
        $$ = $1;
    }
    | fonction {
        $$ = $1;
    }
    | ENTIER {
	    $$ = creer_n_entier($1);
    }
    | PARENTHESE_OUVRANTE expr PARENTHESE_FERMANTE {
	    $$ =$2 ;
    }

lire
    : LIRE PARENTHESE_OUVRANTE PARENTHESE_FERMANTE {
        $$ = creer_lire();
    }

variable
    : IDENTIFIANT {
        $$ = creer_variable($1);
    }

fonction
    : IDENTIFIANT PARENTHESE_OUVRANTE listeArgument PARENTHESE_FERMANTE {
        $$ = creer_fonction($1,$3);
    }

listeArgument
    : argument {
        $$ = creer_n_l_argument($1,NULL);
    }
    | argument VIRGULE listeArgument {
        $$ = creer_n_l_argument($1,$3);;
    }

%%

int yyerror(const char *s) {
    printf("yyerror : %s\n",s);
    return 0;
}

