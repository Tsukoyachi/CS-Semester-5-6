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
	- Une fonction static n'e