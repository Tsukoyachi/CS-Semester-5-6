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
	2. Raccordement des lignes physiquement séparés mais qui sont connecté en terme de code.
	3. 