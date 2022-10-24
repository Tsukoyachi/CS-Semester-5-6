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