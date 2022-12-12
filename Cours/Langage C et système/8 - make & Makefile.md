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

Macros (**exemple à compléter**)
- make permet de définir des macros
	- définition avec macro=valeur
	- valeur peut être lue avec $(macro)
```C
OBJ = main.o hello.o
CC = gcc
CFLAGS = -DDEBUG -g -Wall -std=c99
main: $(OBJ)
	$(CC) -o main $(OBJ)
print:
	lpr main.c hello.c
```

Macros : type d'affectation
- Il existe plusieurs manières de dfinir une macro
**à compléter**

Cibles fictives (**exemple à compléter**)
- Les cibles d'un Makefile
	- fichier (la plupart du temps)
	- nom fitif (on dénote une action dans ce cas)
```C
à compléter
```

Macros spéciales (**exemple à compléter**)
- $@ nom de la cible
- $< nom de la première dépendances
- $^ liste des dépendances
- $? liste des dépendances plus récentes que la cible (utilise la date de dernière modification)
- $* nom du fichier sans suffixe
```C
#Makefile (nouvelle version)
....
main.o: main.c hello.h
	
```
Règle implicites (**à compléter**)
- make connait un certain nombre de règle implicites
	- nom du compilateur C rangé dans CC
	- option de compilations rangées dans CFLAGS
	- passage de .c ->.o
```C
$(CC) $(CFLAGS) -c fichier.c
```
		- **à compléter**

Définition de règles implicites
**à compléter**

GNU makes goodies (**à compléter**)
- La commande make de GNU permet de définir autrement les règles implicites
```C
%.c.gz: %.c
	gzip -9 $<
%.c: %.c.gz
	gunzip -9 $<
```
Autres commandes GNU utiles (voir la doc (**à compléter**))

## Le Makefile complet
**à rattraper car plutôt utile !**

