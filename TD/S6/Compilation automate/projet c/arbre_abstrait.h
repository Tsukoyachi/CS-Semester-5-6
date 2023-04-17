#ifndef __ARBRE_ABSTRAIT__
#define __ARBRE_ABSTRAIT__

/* Abbréviations: 
  * n -> noeud
  * l -> liste
  * exp -> expression (arithmétique)
*/


typedef struct n_programme n_programme; /* Noeud du type programme */
typedef struct n_l_instructions n_l_instructions; /* Noeud du type liste d'instructions */
typedef struct n_instruction n_instruction; /* Noeud du type liste instruction */
typedef struct n_ecrire n_ecrire; /* Noeud du type instruction ecrire */
typedef struct n_exp n_exp; /* Noeud du type expression (arithmétique) */
typedef struct n_operation n_operation; /* Noeud du type operation (arithmétique) */
typedef struct l_argument l_argument;
typedef struct fonction fonction;

struct n_programme{   // pour le moment un programme est juste une liste d'instructions. Il faudra ajouter une liste de définitions de fonctions.
	n_l_instructions* instructions;	
};

struct n_l_instructions{
	n_instruction* instruction;
	n_l_instructions* instructions;
};

struct n_instruction{
  enum { i_ecrire } type_instruction; // pour le moment une instruction peut-être uniquement de type écrire. Il faudra ajouter affectation, exécution de fonction, si,sinon, etc...
  union{ 
    n_exp* exp; // pour ecrire(exp);
  }u;
};

struct n_exp{
  enum { i_operation,i_entier, i_lire,i_variable,i_fonction } type_exp; // pour le moment une expression  peut-être une opération ou un entier
  union{ 
    n_operation* operation;
    int valeur;
    char* var_name;
    fonction* fct;
  }u;
};

struct fonction {
  char * fonction_name;
  l_argument* listeArgument;
};

struct n_operation{
  char type_operation;
  n_exp* exp1;
  n_exp* exp2;
};

struct l_argument {
  n_exp* argument;
  l_argument* arguments;
};

void afficher_n_programme(n_programme* prog,int indent);
void afficher_n_l_instructions(n_l_instructions* instructions ,int indent);
void afficher_n_instruction(n_instruction* instruction ,int indent);
void afficher_n_ecrire(n_ecrire* ecrire,int indent);
void afficher_n_exp(n_exp* exp ,int indent);
void afficher_n_operation(n_operation* operation ,int indent);
void afficher_lire(int indent);
void afficher_variable(char *varname,int indent);
void afficher_fonction(fonction *fonction, int indent);

n_programme* creer_n_programme(n_l_instructions* instructions);
n_l_instructions* creer_n_l_instructions(n_instruction* instruction ,n_l_instructions* instructions);
n_instruction* creer_n_ecrire(n_exp* exp);
n_exp* creer_n_entier(int valeur);
n_exp* creer_n_operation(char type_operation, n_exp* exp1, n_exp* exp2);
n_exp* creer_lire();
n_exp* creer_variable(char *var_name);
n_exp* creer_fonction(char *fonction_name,l_argument* listeArgument);
l_argument* creer_n_l_argument(n_exp* argument, l_argument* listeArgument);
#endif
