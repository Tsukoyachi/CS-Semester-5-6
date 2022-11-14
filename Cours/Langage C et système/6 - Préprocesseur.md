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

L'éditeur de lien va ajouter le contenu des éventuels bibliothèques utilisateur ainsi que les éventuels bibliothèque standart, pour ensuite générer l'exécutable.

