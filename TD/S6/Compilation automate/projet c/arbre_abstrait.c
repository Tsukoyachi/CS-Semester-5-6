#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "arbre_abstrait.h"

/* Abbréviations: 
  * n -> noeud
  * l -> liste
*/


//affiche l'entier avec sa valeur après un certain nombres d'espaces et un retour à la ligne
void afficher(char* s,int indent){
	for(int i = 0; i < indent; i++){
	printf(" "); 
	}
	printf("%s\n",s);
}

//affiche l'entier avec sa valeur après un certain nombres d'espaces
void afficher_caractere(char c,int indent){
	for(int i = 0; i < indent; i++){
	printf(" "); 
	}
	printf("%c\n",c);
}

//affiche la chaine de caractère s après un certain nombres d'espaces
void afficher_entier(int valeur,int indent){
	for(int i = 0; i < indent; i++){
	printf(" "); 
	
	}
	printf("[Entier:%d]\n",valeur);
}

void afficher_variable(char *varname,int indent) {
	for(int i = 0; i < indent; i++){
	printf(" "); 
	
	}
	printf("[Variable : %s]\n",varname);
}

void afficher_lire(int indent){
	for(int i = 0; i < indent; i++){
	printf(" "); 
	
	}
	printf("<lire/>\n");
}

void afficher_fonction(fonction *fonction, int indent) {
	for(int i = 0; i < indent; i++){
		printf(" "); 
	}
	printf("<fonction %s : ",fonction->fonction_name);
	if(fonction->listeArgument == NULL || fonction->listeArgument->argument == NULL){
		printf(">\n");
		return;
	}
	l_argument *listeArgument = fonction->listeArgument;
	
	while(listeArgument->arguments != NULL){
		printf("%d ",listeArgument->argument->u.valeur);
		listeArgument = listeArgument->arguments;
	}
	printf("%d ",listeArgument->argument->u.valeur);
	printf(">\n");
}


void afficher_n_programme(n_programme* prog,int indent){
	afficher("<programme>",indent);
	afficher_n_l_instructions(prog->instructions,indent+1);
	afficher("</programme>",indent);
}




void afficher_n_l_instructions(n_l_instructions* instructions ,int indent){
	afficher("<liste_instuctions>",indent);
	
	do {
		if (instructions->instruction != NULL){
			afficher_n_instruction(instructions->instruction,indent+1);
		}
		instructions = instructions->instructions;
	} while(instructions != NULL );
	afficher("</liste_instructions>",indent);
}


void afficher_n_instruction(n_instruction* instruction ,int indent){
	if(instruction->type_instruction == i_ecrire){
		afficher("<ecrire>",indent);
		afficher_n_exp(instruction->u.exp,indent+1);
		afficher("</ecrire>",indent);
	}
}


void afficher_n_exp(n_exp* exp ,int indent){
	if (exp->type_exp == i_operation){
		afficher_n_operation(exp->u.operation,indent);
	} else if (exp->type_exp == i_entier){
		afficher_entier(exp->u.valeur,indent);
	} else if (exp->type_exp == i_lire) {
		afficher_lire(indent);
	} else if (exp->type_exp == i_variable) {
		afficher_variable(exp->u.var_name,indent);
	} else if (exp->type_exp == i_fonction) {
		afficher_fonction(exp->u.fct,indent);
	}
}


void afficher_n_operation(n_operation* operation ,int indent){
		afficher("<operation>",indent);
		afficher_caractere(operation->type_operation,indent+1);
		afficher_n_exp(operation->exp1,indent+1);
		afficher_n_exp(operation->exp2,indent+1);
		afficher("</operation>",indent);
}

n_programme* creer_n_programme(n_l_instructions* instructions){
  n_programme* n = malloc(sizeof(n_programme));
  n->instructions = instructions;
  return n;
}

n_l_instructions* creer_n_l_instructions(n_instruction* instruction ,n_l_instructions* instructions){
  n_l_instructions* n = malloc(sizeof(n_l_instructions));
  n->instruction = instruction;
  n->instructions = instructions;
  return n;
}

n_instruction* creer_n_ecrire(n_exp* exp){
  n_instruction* n = malloc(sizeof(n_instruction));
  n->type_instruction = i_ecrire;
  n->u.exp = exp;
  return n;
}

n_exp* creer_lire(){
	n_exp* n = malloc(sizeof(n_exp));
 	n->type_exp = i_lire;
 	return n;
}

n_exp* creer_variable(char *varname) {
	n_exp* n = malloc(sizeof(n_exp));
	n->type_exp = i_variable;
	n->u.var_name = varname;
	return n;
}

n_exp* creer_n_entier(int valeur){
  n_exp* n = malloc(sizeof(n_exp));
  n->type_exp = i_entier;
  n->u.valeur = valeur;
  return n;
}

n_exp* creer_n_operation(char type_operation,n_exp* exp1,n_exp* exp2){
  n_exp* n = malloc(sizeof(n_exp));
  n_operation* n_op = malloc(sizeof(n_operation));
  n->u.operation = n_op;
  n->type_exp = i_operation;
  n_op->type_operation = type_operation;
  n_op->exp1 = exp1;
  n_op->exp2 = exp2;
  return n;
}

n_exp* creer_fonction(char *fonction_name, l_argument* listeArgument) {
	n_exp* n = malloc(sizeof(n_exp));
	n->type_exp = i_fonction;
	
	fonction *function = malloc(sizeof(fonction));
	function->fonction_name = fonction_name;
	function->listeArgument = listeArgument;
	n->u.fct=function;
	return n;
}

l_argument* creer_n_l_argument(n_exp* argument, l_argument* listeArgument) {
	l_argument *n = malloc(sizeof(l_argument));

	n->argument = argument;
	n->arguments = listeArgument;

	return n;
}