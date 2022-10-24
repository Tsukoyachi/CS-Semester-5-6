# Fonctions
## Fonctions K&R
### Syntaxe
```
type_de_retour nom_methode(paramètres (sans leurs types))
	déclaration_types_variable;
{
	contenu de la fonction
}
```
### Un exemple
```C
int(a,b)
int a,b;
{
	return if(a>=b) ? a : b;
}
```
### A bannir car...
**à rattraper**

## Fonctions ANSI
### Syntaxe
```C
type_de_retour nom_methode(liste typée de paramètres) {
	corps de la fonction
}
```
### Exemple
```C
int max(int a, int b){
	return if(a>=b) ? a : b;
}
```
### Type du résultat
- void (pas de type => procédure)
- n'importe quel type scalaie (entier, réel, pointeur, enum)
- structure et union
- Attention : **pas de tableau**

### Type des paramètres
- n'importe quel type scalaire
- structure et union
- tableau
	- paramètre formel et paramètre effectif doivent être compatibles (cf pointeur)
	- la taille peut être **à rattraper...**

## Appel de fonction K&R vs ANSI 
**exemple à compléter**
```C
void f(a,b) /* Version K&R */
	int a; double b;
{
	...
}

void g(int a, doubke b) { /* Version ANSI*/
	...
}

f();
f(1,2,3,4);
f("false", "even more")


```

## Résultat de fonction
- valeur de la fonction donné par l'énoncé return
- Type du résultat : donné à l'entrée de la fonction
- Conversion éventuelle de return vers le type de la fonction
- **à compléter**

## Passage de paramètre
- Passage par valeur uniquement
- Pour les tableaux, on passe un pointeur sur le début du tableau (par valeur)
```C
void f(int x) {
	x = x + 1;
	printf("In function f: %d\n",x);
}
void main(void) {
int a = 1;
f(a);
printf("After call to f: %d\n",a);
}
==> In function f: 2
	After call to f: a;
```
**à compléter**

## Déclaration de fonction
- Déclarer une fonction = donner son type avec un header ou prototype
- C'est utile pour utiliser une fonction "avant" sa définition
- C'est également utile est définie dans un autre fichier

### Définition K&R
```C
double cos(); /* paramètres absents (inutiles) */
```
### Définition ANSI
```C
double cos(double x); /* en-tête complet */
```
### Si utilisation de la fonction sans prototype
- Auto-déclaration de la fonction par le compilateur
- Résultat de type entier
- **à compléter**

Même en ANSI C, la rétro compatibilité avec le C de K&R peut être source d'erreurs
#### Exemple
```C
void f2(int a, int b); /* forward declaration */

void f1(int a, int b){
	int x, y, z;
	x = f2(b,a); /* error detected */
	y = f3(b,a); /* auto declaration */
	z = f4(b,a): /* auto declaration */
}

void f2(float a, float b) /* Error detected */
{ ... }

int f3(void) /* conform to auto-declaration */
{ ... }

double f4(int a, int b) /* error detected, even in K&R */
{ ... }
```

### Fonctions à arité variable
arité = nombre de paramètre

- C'est une extension ANSI
- La liste de paramètres variables est dénotée par '...' après le dernier paramètre fixe
```C
#include <stdarg.h>
void ma_fonction(type1 arg1, type2 arg2, ...) {
}
```
- Il doit y avoir au moins 1 paramètre fixe
- Le fichier <stdarg.h> définit les macros suivantes :
```C
void va_start(va_list ap, last_fixed_parameter)
type va_arg(va_list ap, type)
void va_end(va_list ap)
```

#### Exemple
```C
#include <stdarg.h>

int max(int first,...) { /* Liste terminée par un nombre < 0 */
	va_list ap;
	int M = 0;
	va_start(ap,first);
	while (first > 0) {
		if(first > 0) M = first;
		first = va_arg(ap,int);
	}
	va_end(ap);
	return M
}

void main(void) {
	int x = max(12,18,17,20,1,34,5,-1);
	...
}
```

# Variables
- On ne considère ici que les programmes mono-fichier
- Variable globale :
	- Définition : en dehors d'un bloc
	- Durée de vie : tout le programme
	- Visibilité : depuis son point de définition jusqu'à la fin de fichier
		- Avec possibilité de masquage dans un bloc
- Variable locale :
	- Définition : dans un bloc
	- Durée de vie: **à compléter**
	- **à compléter**

```C
int counter = 0;

int f(void) {
	counter +=1; /* Incrementing global variable */
	x += 1; /* Error : x unknown */
}

int x; /* now, x is known */

int g(void) {
	int counter = 0; /* mask global variable */
	counter += 1; /* incrementing the local variable */
	x += 1;
}
```

- Variable statique:
	- Définition dans un bloc (doit être préfixée par static)
	- Durée de vie : tout le programme (comme une globale)
	-  Visibilité : restreinte au bloc de définition (comme une locale)
```C
void f1(void) {
	static int counter = 0;
	printf("f1 was called %d times \n", ++counter);
}

void f2(void) {
	static int counter = 0;
	printf("f2 was called %d times \n", ++counter);
}

void main(void){
	f1();f2();f1();
}

==> f1 was called 1 times
	f2 was called 1 times
	f1 was called 2 times
```

# Entrée/Sortie avec format
- printf
```C
int printf(const char *format, ...);
```
	- Le format spécifie le nombre, le type et les contraintes sur la représentation textuelle des expressions passées dans la liste variable
	- Exemple
**Diapo à rattraper**

- sprintf et sscanf
	- Identifiques à printf et scanf mais l'E/S se fait dans une chaîne au lieu d'un fichier
- snprintf

**diapo à rattraper**

-  vprintf et vscanf
**diapo à rattraper également**

# Le type FILE
- Le type FILE est définie dans <stdio.h>
- Un objet de type FILE est un flux
	- supporte avec séquentiel et direct
	- accès par caractère
	- E/S bufferisées
- Ouverture d'un fichier :
```C
FILE *fopen(const char *name, const char *mode);
/* Le mode peut être "r", "w", "a", ... */
```
- Fermeture d'un fichier
```C
```