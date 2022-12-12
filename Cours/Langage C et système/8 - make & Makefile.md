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
/* caractère tabulation (pas 4 espaces) requis avant les commandes */
```

Principe dans le cas de la compilation :
- **à rattraper**

Makefile
```C
# Makefile du programme précédent
main: main.o hello.o
	gcc -o main main.o hello.o
main.o: main.c hello.h
	gcc -c main.c
hello.o: hello.c hello.h
	gcc -c hello.c
```
Usage
```C
$ make
gcc -c main.c
gcc -c hello.c
gcc -o main main.o hello.o
$ gedit main.c
...
$ make
gcc -c main.c
gcc -o main main.o hello.o
```

**La partie intéressante c'est que make a été créé pour C mais peut avoir un usage pour d'autre chose puisque c'est un éditeur de macro.**

Macros
- make permet de définir des macros
	- défi
