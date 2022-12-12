# 7 - Structuration des programmes
---

La forme K&R et la forme C ansi peuvent être toutes les deux présentes au sein d'un même programme.
Sauf que lorsque le prototype d'une fonction n'est pas déclaré, K&R l'auto déclare !

## Modularité en C
- La modularité en C est basée sur les fichiers
- Variable globales dans un fichier
	- static : 
		- durée de vie = celle du programme
		- visibilité = son fichier uniquement
	- extern :
		- L'allocation de la variable n'est pas faite par ce fichier.
		- Il faut qu'un autre fichier déclare cette variable.
- Fonction d'un fichier :
	- Une fonction static n'est visible que dans le fichier qui définit cette fonction (équivalent de private en java)
	- Un prototype de fonction peut être déclaré extern :
		- La fonction est définie ailleurs
		- Le mot clé extern peut être omis.

### Quelques exemples :

Qui fonctionne :
```C
/* Fichier file1.c */
static int a;
int b;
extern int c;
void main(void) {...}
double f1(char *s){
	static int a, b;
	..... f2(); .... /* f2 est auto déclarée */
}

/* Fichier file2.c */
static int a,b;
int c;

extern double f1(); /* prototype K&R */

void f2(void) {...}

static int f3(...) { /* f3 utilisable que dans file2.c*/
	f1("Test");      /* utilisation conforme au prototype*/
}
```

Qui ne fonctionne pas (**et même pas d'erreur compilation**) :

```C
/* Fichier file1.c */
static int a;
int b;
extern char c; /* déclaré comme int dans fichier 2 !!! */
void main(void) {...}
double f1(char *s){
	static int a, b;
	..... f2(100); .... /* utilisation résultat + paramètre !!! */
}

/* Fichier file2.c */
int a,b; /* définition multiple de b */
int c;

extern double f1(); /* prototype K&R */

void f2(void) {...}

static int f3(...) { /* f3 utilisable que dans file2.c*/
	f1("Test");      /* utilisation non conforme */
}
```

## Préprocesseur : Utiliser des .h

**Regarder exemple du cours**

