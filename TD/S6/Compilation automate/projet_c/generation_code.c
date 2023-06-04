#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbre_abstrait.h"
#include "generation_code.h"

//pour afficher le code uniquement si l'option afficher_nasm vaut 1
#define printifm(format, ...) if(afficher_nasm){ printf(format, __VA_ARGS__); }

int afficher_nasm = 1;
int num_etiquette_courante = 0;

/* fonction locale, permet d'afficher un commentaire */
void nasm_comment(char *comment) {
  if(comment != NULL) {
    printifm("\t\t ; %s", comment);//le point virgule indique le début d'un commentaire en nasm. Les tabulations sont là pour faire jolie.
  }
  printifm("%s","\n");
}

void nouveau_nom_etiquette (char *etiq) {
  sprintf(etiq,"e%d",num_etiquette_courante++);

}

/*
Affiche une commande nasm sur une ligne
Par convention, les derniers opérandes sont nuls si l'opération a moins de 3 arguments.
*/
void nasm_commande(char *opcode, char *op1, char *op2, char *op3, char *comment) {
  printifm("\t%s", opcode);
  if(op1 != NULL) {
    printifm("\t%s", op1);
    if(op2 != NULL) {
      printifm(", %s", op2);
      if(op3 != NULL) {
        printifm(", %s", op3);
      }
    }
  }
  nasm_comment(comment);
}


void nasm_prog(n_programme *n) {
  
  printifm("%%include\t'%s'\n","io.asm");
  printifm("%s","\nsection\t.bss\n");
  printifm("%s", "sinput:\tresb\t255\t;reserve a 255 byte space in memory for the users input string\n");
  printifm("%s","\nsection\t.text\n");
  printifm("%s","global _start\n");
  printifm("%s","_start:\n");
  nasm_liste_instructions(n->instructions);
  //pour quitter le programme
  nasm_commande("mov", "eax", "1" , NULL, "1 est le code de SYS_EXIT");
  nasm_commande("int", "0x80", NULL, NULL, "exit");
}

void nasm_liste_instructions(n_l_instructions *n) {
	do {
		if (n->instruction != NULL){
			nasm_instruction(n->instruction);
		}
		n = n->instructions;
	} while(n != NULL );
}

void nasm_instruction(n_instruction* n){
	if(n->type_instruction == i_ecrire){
		nasm_exp(n->u.exp);
		nasm_commande("pop", "eax", NULL, NULL, NULL); //on dépile la valeur d'expression sur eax
		nasm_commande("call", "iprintLF", NULL, NULL, NULL); //on envoie la valeur d'eax sur la sortie standard
	}
}

int nasm_exp(n_exp* n){
	if (n->type_exp == i_operation){
		return nasm_operation(n->u.operation);
	} else if (n->type_exp == i_entier){
	      char buffer[10];
	      sprintf(buffer, "%d", n->u.valeur);
      	      nasm_commande("push", buffer, NULL, NULL, NULL) ;
        return 1;
	} else if (n->type_exp == i_lire){
    nasm_commande("mov", "eax","sinput",NULL,"met l'entrée dans le registre eax");
    nasm_commande("call","readline", NULL, NULL, "Lis l'input utilisateur");
    nasm_commande("call", "atoi", NULL, NULL, "Remplace la string par un nombre");
    nasm_commande("push", "eax", NULL, NULL, "Retourne le résultat de lire");
    return 1;
  } else if (n->type_exp == i_booleen) {
    nasm_commande("push",(n->u.valeur==1)?"1":"0",NULL,NULL,NULL);
    return 0;
  }
}

int nasm_operation(n_operation* n){
  int op1, op2;


  if(n->exp1 != NULL){
    op1 = nasm_exp(n->exp1);
  }
  if(n->exp2 != NULL){
    op2 = nasm_exp(n->exp2);
    nasm_commande("pop", "ebx", NULL, NULL, "depile la seconde operande dans ebx");
  }
  
  nasm_commande("pop", "eax", NULL, NULL, "depile la permière operande dans eax");

  if (strcmp(n->type_operation, "+") == 0){
    nasm_commande("add", "eax", "ebx", NULL, "effectue l'opération");
  }
  else if (strcmp(n->type_operation,"-") == 0){
    nasm_commande("sub","eax","ebx",NULL,"effectue l'opération"); 
  }
  else if(strcmp(n->type_operation, "*") == 0){
    nasm_commande("imul", "ebx", NULL, NULL, "effectue l'opération");
  }
  else if (strcmp(n->type_operation, "/") == 0) {
    nasm_commande("cdq", NULL, NULL, NULL, "initialise edx à 0 si eax est > 0 et à -1 sinon");
    nasm_commande("idiv", "ebx", NULL, NULL, "effectue l'opération");
  }
  else if (strcmp(n->type_operation,"%") == 0){
    nasm_commande("mov", "edx", "0", NULL, "prepare edx pour la division");
    nasm_commande("idiv", "ebx", NULL, NULL, "effectue l'opération");
    nasm_commande("mov", "eax", "edx", NULL, "prepare edx pour la division");
  }
  else if (strcmp(n->type_operation,"&&") == 0){
    if(op1 != 0 || op2 != 0){
      fprintf(stderr,"Operation booleenne avec des entiers\n");
      exit(1);
    }
    nasm_commande("and","eax","ebx", NULL, "effectue l'opération");
  }
  else if (strcmp(n->type_operation,"||") == 0) {
    if(op1 != 0 || op2 != 0){
      fprintf(stderr,"Operation booleenne avec des entiers\n");
      exit(1);
    }
    nasm_commande("or","eax","ebx", NULL, "effectue l'opération");
  }
  else if (strcmp(n->type_operation,"!") == 0) {
    if(op1 != 0){
      fprintf(stderr,"Operation booleenne avec des entiers\n");
      exit(1);
    }
    nasm_commande("xor","eax","1", NULL, "effectue l'opération");
  }
  else if (strcmp(n->type_operation,"==") == 0 ){
    if(op1 != 1 || op2 != 1){
      fprintf(stderr,"Operation entières avec des booleens");
      exit(1);
    }
    char etiquette_vrai[100];
    char etiquette_suite[100];

    nouveau_nom_etiquette(etiquette_vrai);
    nouveau_nom_etiquette(etiquette_suite);

    nasm_commande("cmp","eax","ebx",NULL,"Compare les opérandes");
    nasm_commande("je",etiquette_vrai,NULL,NULL,"Jump si égaux");
    nasm_commande("push","0",NULL,NULL,"Push Faux si différents");
    nasm_commande("jmp",etiquette_suite,NULL,NULL,"Va a la suite du code");

    printifm("%s :",etiquette_vrai);
    nasm_commande("push","1",NULL,NULL,"Push Vrai si égaux");

    printifm("%s :",etiquette_suite);
    return 0;
  }
  else if (strcmp(n->type_operation,"!=") == 0 ){
    if(op1 != 1 || op2 != 1){
      fprintf(stderr,"Operation entières avec des booleens");
      exit(1);
    }
    char etiquette_vrai[100];
    char etiquette_suite[100];

    nouveau_nom_etiquette(etiquette_vrai);
    nouveau_nom_etiquette(etiquette_suite);

    nasm_commande("cmp","eax","ebx",NULL,"Compare les opérandes");
    nasm_commande("je",etiquette_vrai,NULL,NULL,"Jump si égaux");
    nasm_commande("push","1",NULL,NULL,"Push Vrai si différents");
    nasm_commande("jmp",etiquette_suite,NULL,NULL,"Va a la suite du code");

    printifm("%s :",etiquette_vrai);
    nasm_commande("push","0",NULL,NULL,"Push Faux si égaux");

    printifm("%s :",etiquette_suite);
    return 0;
  }
  else if (strcmp(n->type_operation,">=") == 0 ){
    if(op1 != 1 || op2 != 1){
      fprintf(stderr,"Operation entières avec des booleens");
      exit(1);
    }
    char etiquette_vrai[100];
    char etiquette_suite[100];

    nouveau_nom_etiquette(etiquette_vrai);
    nouveau_nom_etiquette(etiquette_suite);

    nasm_commande("cmp","eax","ebx",NULL,"Compare les opérandes");
    nasm_commande("jge",etiquette_vrai,NULL,NULL,"Jump si supérieur ou égaul");
    nasm_commande("push","0",NULL,NULL,"Push Faux si incorrect");
    nasm_commande("jmp",etiquette_suite,NULL,NULL,"Va a la suite du code");

    printifm("%s :",etiquette_vrai);
    nasm_commande("push","1",NULL,NULL,"Push Vrai si supérieur ou égal");

    printifm("%s :",etiquette_suite);
    return 0;
  }
  else if (strcmp(n->type_operation,"<=") == 0 ){
    if(op1 != 1 || op2 != 1){
      fprintf(stderr,"Operation entières avec des booleens");
      exit(1);
    }
    char etiquette_vrai[100];
    char etiquette_suite[100];

    nouveau_nom_etiquette(etiquette_vrai);
    nouveau_nom_etiquette(etiquette_suite);

    nasm_commande("cmp","eax","ebx",NULL,"Compare les opérandes");
    nasm_commande("jg",etiquette_vrai,NULL,NULL,"Jump si supérieur");
    nasm_commande("push","1",NULL,NULL,"Push Vrai si inférieur ou égal");
    nasm_commande("jmp",etiquette_suite,NULL,NULL,"Va a la suite du code");

    printifm("%s :",etiquette_vrai);
    nasm_commande("push","0",NULL,NULL,"Push Vrai si supérieur");

    printifm("%s :",etiquette_suite);
    return 0;
  }
  else if (strcmp(n->type_operation,">") == 0 ){
    if(op1 != 1 || op2 != 1){
      fprintf(stderr,"Operation entières avec des booleens");
      exit(1);
    }
    char etiquette_vrai[100];
    char etiquette_suite[100];

    nouveau_nom_etiquette(etiquette_vrai);
    nouveau_nom_etiquette(etiquette_suite);

    nasm_commande("cmp","eax","ebx",NULL,"Compare les opérandes");
    nasm_commande("jg",etiquette_vrai,NULL,NULL,"Jump si supérieur");
    nasm_commande("push","0",NULL,NULL,"Push Faux si inférieur ou égal");
    nasm_commande("jmp",etiquette_suite,NULL,NULL,"Va a la suite du code");

    printifm("%s :",etiquette_vrai);
    nasm_commande("push","1",NULL,NULL,"Push Vrai si supérieur");

    printifm("%s :",etiquette_suite);
    return 0;
  }
  else if (strcmp(n->type_operation,"<") == 0 ){
    if(op1 != 1 || op2 != 1){
      fprintf(stderr,"Operation entières avec des booleens");
      exit(1);
    }
    char etiquette_vrai[100];
    char etiquette_suite[100];

    nouveau_nom_etiquette(etiquette_vrai);
    nouveau_nom_etiquette(etiquette_suite);

    nasm_commande("cmp","eax","ebx",NULL,"Compare les opérandes");
    nasm_commande("jge",etiquette_vrai,NULL,NULL,"Jump si supérieur ou égal");
    nasm_commande("push","1",NULL,NULL,"Push Vrai si inférieur");
    nasm_commande("jmp",etiquette_suite,NULL,NULL,"Va a la suite du code");

    printifm("%s :",etiquette_vrai);
    nasm_commande("push","0",NULL,NULL,"Push Faux si supérieur ou égal");

    printifm("%s :",etiquette_suite);
    return 0;
  }
  nasm_commande("push",  "eax" , NULL, NULL, "empile le résultat");
  return op1;
}
