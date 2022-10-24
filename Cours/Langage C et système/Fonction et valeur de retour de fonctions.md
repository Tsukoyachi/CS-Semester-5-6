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
printf("After ca")
}
```