# 6 - Préprocesseur
---
## Fonctions de base
- Le préprocesseur est un programme appelé avant la compilation du fichier source.
- Les directives de préprocessing de C sont sur les lignes commençant par \#.
- Principales fonctions :
	- inclusion de texte (#include)
	- substitution textuelles (#define)
		- définition de constantes
		- définition de macro
	- **à compléter** #Todo

## Chaîne de compilation

Le préprocesseur cpp va remplacer tous les # par le texte correspondant à la directive.

La compilateur cc va checker le code.

L'éditeur de lien va ajouter le contenu des éventuels bibliothèques utilisateur ainsi que les éventuels bibliothèque standart, pour ensuite générer l'exécutable.

Quand on fait gcc les 3 étapes sont faites mais on peut les appeler indépendemment.

## Phase de compilation C
- Il y a 8 étapes de compilation, le préprocesseur va faire les 4 premières.
	1. Remplcement de trigraphes (plus dans les programmes, peu utilisé)
	2. Raccordement des lignes physiquement séparés mais qui sont connectés par des séquences de saut de lignes.
	3. Tokenisation **à compléter** #Todo 


## Inclusion
### Inclusion de fichier source

- Deux formes :
\#include \<fichier> Bibliothèque standard
\#include "fichier" Bibliothèque perso
**à compléter**

## Substitution
### Définition de constante
Syntaxe :
```C
#define identificateur chaîne
```
Exemple :
```C
#define FALSE 0
#define TRUE 1
#define EOF (-1)

#define SIZE 1024
#define SIZE2 (2*1024)
int buf[SIZE], big_buf[SIZE2];

#define IF if (
#define THEN ) {
#define ELSE ;} else {
#define ENDIF ;}
...
IF a < b THEN x = y + z; z = w ELSE a = 2 * b ENDIF
/* équivalent à */
if (a < b) { x = y + z; z = w;} else {a = 2 * b;}
```
### Définition de macro
Syntaxe :
```C
#define idenficateur(x1,x2, ..)
```
