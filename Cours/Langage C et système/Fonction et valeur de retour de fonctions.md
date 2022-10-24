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
- void (pas de type => p)