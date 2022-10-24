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

#### Exemple
```C
void f2(int a, int b); /* forward declaration */

void f1(int a, int b){
	int x, y, z;
	x = f2(b,a); /* error detected */
	y = f3(b,a); /* auto declaration */
	z = f4(b,a): /* auto declaration */
}

void f2()
```
