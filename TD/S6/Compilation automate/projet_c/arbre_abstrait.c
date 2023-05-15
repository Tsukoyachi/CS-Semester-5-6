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
void afficher_caractere(char* c,int indent){
	for(int i = 0; i < indent; i++){
	printf(" "); 
	}
	printf("%s\n",c);
}

//affiche la chaine de caractère s après un certain nombres d'espaces
void afficher_entier(int valeur,int indent, char* name){
	for(int i = 0; i < indent; i++){
	printf(" "); 
	
	}
	printf("[Entier:%d]\n",valeur);
}

void afficher_booleen(int valeur,int indent, char* name){
	for(int i = 0; i < indent; i++){
	printf(" "); 
	
	}
	printf("[Booleen:%s]\n",(valeur == 1)? "Vrai" : "Faux");
}

void afficher_variable(variable* va,int indent) {
	for(int i = 0; i < indent; i++){
	printf(" "); 
	
	}
	printf("[Variable %s]\n", va->nom);
}

void afficher_variable_declaration(variable* va,int indent) {
	for(int i = 0; i < indent; i++){
	printf(" "); 
	
	}
	printf("[Variable %s : %s]\n", va->nom, va->type == t_entier ? "Entier" : "Booleen");
}

void afficher_variable_declaration_affectation(variable* va,int indent) {
	for(int i = 0; i < indent; i++){
	printf(" "); 
	
	}
	printf("[Variable %s : %s = %d]\n", va->nom, va->type == t_entier ? "Entier" : "Booleen", va->value);
}

void afficher_variable_affecation(variable* va,int indent) {
	for(int i = 0; i < indent; i++){
	printf(" "); 
	
	}
	printf("[%s : %s = %d]\n", va->nom, va->type == t_entier ? "Entier" : "Booleen", va->value);
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
	else if(instruction->type_instruction == i_declaration){
		afficher("<declaration>",indent);
		afficher_variable_declaration(instruction->u.exp->u.va,indent+1);
		afficher("</declaration>",indent);
	}
	else if(instruction->type_instruction == i_affectation){
		afficher("<affectation>",indent);
		afficher_variable_affecation(instruction->u.exp->u.va,indent+1);
		afficher("</affecation>",indent);
	}
	else if(instruction->type_instruction == i_declaration_affectation){
		afficher("<declaration>",indent);
		afficher("<affecation>",indent + 1);
		afficher_variable_declaration_affectation(instruction->u.exp->u.va, indent + 2);
		afficher("</affecation>",indent + 1);
		afficher("</declaration>",indent);
	}
	else if(instruction->type_instruction == i_conditionnelle){
		afficher("<conditionnelle>",indent);
        afficher("<si>",indent+1);
        afficher_n_exp(instruction->u.exp->u.conditionnelle->condition,indent+1);
        afficher("</si>",indent+1);
        afficher("<alors>",indent+1);
        afficher_n_l_instructions(instruction->u.exp->u.conditionnelle->instructions_si,indent+1);
        afficher("</alors>",indent+1);
        if (instruction->u.exp->u.conditionnelle->liste_sinon_si != NULL){
            afficher("<sinon_si>",indent+1);
            afficher_n_instruction(instruction->u.exp->u.conditionnelle->liste_sinon_si,indent+1);
            afficher("</sinon_si>",indent+1);
        }
        if (instruction->u.exp->u.conditionnelle->liste_sinon){
            afficher("<sinon>",indent+1);
            afficher_n_l_instructions(instruction->u.exp->u.conditionnelle->liste_sinon,indent+1);
            afficher("</sinon>",indent+1);
        }
        afficher("</conditionnelle>",indent);
	}
}


void afficher_n_exp(n_exp* exp ,int indent){
	if (exp->type_exp == i_operation){
		afficher_n_operation(exp->u.operation,indent);
	} else if (exp->type_exp == i_entier){
		afficher_entier(exp->u.valeur,indent, exp->u.var_name);
	} else if (exp->type_exp == i_booleen) { 
		afficher_booleen(exp->u.valeur,indent, exp->u.var_name);
	} else if (exp->type_exp == i_lire) {
		afficher_lire(indent);
	} else if (exp->type_exp == i_variable) {
		afficher_variable(exp->u.va,indent);
	} else if (exp->type_exp == i_fonction) {
		afficher_fonction(exp->u.fct,indent);
	}
}


void afficher_n_operation(n_operation* operation ,int indent){
		afficher("<operation>",indent);
		afficher_caractere(operation->type_operation,indent+1);
		afficher_n_exp(operation->exp1,indent+1);
		if(operation->exp2 != NULL)
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

n_instruction* creer_n_declaration(n_exp* exp) {
    n_instruction *n = malloc(sizeof(n_instruction));
    n->type_instruction = i_declaration;
    n->u.exp= exp;
    return n;
}

n_instruction* creer_n_affectation(n_exp* exp) {
	n_instruction *n = malloc(sizeof(n_instruction));
    n->type_instruction = i_affectation;
    n->u.exp= exp;
    return n;
}
n_instruction* creer_n_declaration_affectation(n_exp* exp) {
	n_instruction *n = malloc(sizeof(n_instruction));
    n->type_instruction = i_declaration_affectation;
    n->u.exp= exp;
    return n;
}

n_instruction* creer_n_conditionnelle(n_exp* condition, n_l_instructions* instructions_si, n_instruction* liste_sinon_si, n_l_instructions* liste_sinon) {	
	n_instruction *n = malloc(sizeof(n_instruction));
	n->type_instruction = i_conditionnelle;
	n->u.exp = malloc(sizeof(n_exp));

	n->u.exp->u.conditionnelle = malloc(sizeof(n_conditionnelle));
	n->u.exp->u.conditionnelle->condition = condition;
	n->u.exp->u.conditionnelle->instructions_si = instructions_si;
	n->u.exp->u.conditionnelle->liste_sinon_si = liste_sinon_si;
	n->u.exp->u.conditionnelle->liste_sinon = liste_sinon;
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
	n->u.va = malloc(sizeof(variable));
	n->u.va->nom = varname;
	return n;
}

n_exp* creer_variable_boolean(char *varname, int value) {
	n_exp* n = malloc(sizeof(n_exp));
	n->type_exp = i_variable;
	n->u.va = malloc(sizeof(variable));
	n->u.va->nom = varname;
	n->u.va->type = t_booleen;
	n->u.va->value = value;

	return n;
}

n_exp* creer_variable_entier(char *varname, int value) {
	n_exp* n = malloc(sizeof(n_exp));
	n->type_exp = i_variable;
	n->u.va = malloc(sizeof(variable));
	n->u.va->nom = varname;
	n->u.va->type = t_entier;
	n->u.va->value = value;

	return n;
}

n_exp* creer_n_entier(int valeur){
  n_exp* n = malloc(sizeof(n_exp));
  n->type_exp = i_entier;
  n->u.valeur = valeur;
  return n;
}

n_exp* creer_n_booleen(int valeur) {
	n_exp *n = malloc(sizeof(n_exp));
	n->type_exp = i_booleen;
	n->u.valeur = valeur;
	return n;
}

n_exp* creer_n_operation_non(char* type_operation, n_exp *exp) {
  n_exp* n = malloc(sizeof(n_exp));
  n_operation* n_op = malloc(sizeof(n_operation));
  n->u.operation = n_op;
  n->type_exp = i_operation;
  n_op->type_operation = type_operation;
  n_op->exp1 = exp;
  return n;
}

n_exp* creer_n_operation(char* type_operation,n_exp* exp1,n_exp* exp2){
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