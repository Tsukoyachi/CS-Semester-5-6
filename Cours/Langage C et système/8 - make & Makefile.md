# 8 - make & Makefile
---
Dans le cas de travail sur plusieurs .c simultanément pour ensuite avoir un unique exécutable pour éviter d'effectuer plein de gcc à chaque modification.

Pour cela on a deux commandes "make" et "Makefile"

- make (commande)
	- Construit automatiquement des fichiers
	- Exécute des commandes uniquement si elles sont nécessaires
	- Arriver à un résultat en ne faisant que les étapes nécessaires
		- compilation/installation de logiciel (exécutable ou bibliothèque)
		- Génération/installation de documentation/pages html
		- ...
- Makefile (fichier)
	- Explicites les dépendances sous forme de règles

```C
cible [cible ...] : dépendances
	commande 1
	commande 2
	...
/* tabulation (pas 4 espace*/
```