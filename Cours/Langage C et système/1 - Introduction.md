# Introduction
---
### Lessons date :
- 03/10/22

### Teachers :
- Stéphane Lavirotte

### Tags :
#C #système

---

# Les paradigmes de Programmation

Définition paradygme : Le **paradigme de programmation** est la façon (parmi d'autres) d'approcher la programmation informatique et de formuler les solutions aux problèmes et leur formalisation dans un langage de programmation approprié.

Les langages va utiliser plusieurs concept et paradygme.

Il y a beaucoup plus de paradigmes que de concept.

Un paradygme est un ensemble de concept.

Avec n concepts on peut faire 2^n paradygmes.

Il y a plusieurs concept majeurs tel que : 
(à rattraper)

### Familles de programmation
Programmation impérative :
	- Programmation Structurée :
		- Eviter la programmation spaghetti (ex : goto)
	- Programmation procédurale : C, Ada, Pascal, ...
	- Programmation Orientée Objet : C++, Java; C#, ...

Programmation Déclarative :
	- Programmation Fonctionnelle
	- Programmation Logique
	- Programmation par contraintes

![[Pasted image 20221003082025.png | center | 705]]

## Langage C : Programmation Procédurale

### Pourquoi apprendre le C :
- A la base de nombreux langages (syntaxiquement)
	- C++, C#, Java, PHP, Javascript
- A la base, le langage pour coder Unix
	- Noyau, compilateur, outils système, bibliothèques, ...
- Linux Torvalds: "Nothing better than C" (2012)
	- "Si vous pensez comme un ordinateur, écrire en C a du sens"
- Un des langages les plus efficaces
	- Efficacité au niveau CPU
	- Consommation mémoire
- Un des langages les plus utilisés encore de nos jours
- Des centaines de millions de lignes écrites en C
	- Noyau linux : ~30 millions de lignes de code; 98.5% en C
	- Compilateur gcc : ~10 millions de lignes de code; 47.7% en C

### Un peu d'histoire :
- Racines
	- Algol 60
	- BCPL (1967)
	- B (auteur : K. Thomson ~ 1970)
- Auteur
	- Denis Ritchie (Bell Labs 1972)
	- Première spécification du langage dans le livre de Kernigham et Ritchie en 1978 (version K&R)
- Plusieurs versions de C disponibles :
	- Traditionnel : celui qui est décrit dans la version originale de K&R 1978 - Version Obsolète
	- ANSI C et ISO C : sur-ensembles de K&R C (1983 -> 1990)
	- Version la plus courante
		- C99 (1999) - La version que nous utiliserons dans ce cours
		- C11 (08/12/2011) - La dernière incarnation du langage (peu efficace)

### Buts du langage
- Langage de programmation
	- "facile" à apprendre
	- facile à implémenter
- Langage de programmation pour implémenter des systèmes d'exploitation :
	- conçu à l'origine pour programmer le noyau d'Unix v6
	- proche de la sémantique du processeur
	- simple et efficace
	- accès facile aux mécanismes de bas niveau
	- pointeurs (typés, mais non contrôlés)
	- contrôles de types permissifs (outil lint)
	- pas de contrôle de type à l'exécution
- Permettre l'écriture de programmes portables
	- PCC (Portable C Compiler)
	- Utilisation d'une bibliothèque standard
	- les Entrées, Sorties ne sont pas dans le langage
	- Pas de chaînes de caractères à proprement parler (mais de nombreuse fonctions pour les manipuler)
	- pas de concurrence dans le langage (mais accessible au travers l'utilisation de fonctions de la bibliothèque)
- Founrir un ensemble d'outil système bien féfini autour du langage
	- compilation séparée (on parle du système, ce qui permet d'éviter la définition d)
