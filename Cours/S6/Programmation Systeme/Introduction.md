![[01 Prod et Exe Prog.pdf]]

---

# Modèle de Von Neumann

## Concept de base

Distinction entre Programme et Processus :
- Un programme est l'ensemble des procédures, le résultats statique d'une compilation/édition de liens (binaire exécutable)
	- Ensemble de procédures
- Un processus est l'activité dynamique résultant de l'exécution d'un programme
	- Enchaînement (séquentiel ou concurrent d'activité)

Qu'est ce qu'un contexte ?

Il peut s'agir d'une information caractérisant l'état courant d'un processus qui est sauvegardé lors de la suspension du processus et rechargé lors de sa reprise.

Il peut également s'agir d'un contexte matériel comprenant donc :
- Mot d'état 
- Compteur ordinal 
- Registres de l'unité centrale

Enfin, on peut parler de contexte logiciel (ou système) :
- Segments de texte (instructions), de données, de pile… 
- Attributs : identification utilisateur, droits d'accès, priorité… 
- Ressources utilisées : fichiers ouverts...

## Evénements, interruptions et déroutements

Une **interruption** est un événement asynchrone inopiné qui entraîne une fin des entrées-sortie et qui est dû à une condition "anormale" d'un processus extérieur en temps réel.

Un **déroutement** (ou **exception**) est quant à lui un événement provoqué par l'exécution même du programme, correspondant à une situation "exceptionnelle".
- Par exemple : Une exception arithmétique, une violation de protection mémoire...

En général le traîtement de ses deux types d'événement est uniforme que la plupart des architectures.

Pour les événements d'interruption ou de déroutement, on a aussi les caractéristiques suivantes :
- Contexte logiciel (ou système) 
- Segments de texte (instructions), de données, de pile… 
- Attributs : identification utilisateur, droits d'accès, priorité… 
- Ressources utilisées : fichiers ouverts...

## Cycle élémentaire d'exécution d'une instruction

![[Pasted image 20230214081914.png]]

# Production et exécution de programmes

## Langage de Programmation (de Haut Niveau)

On a un modèle de calcul plus proche des applications avec des **types de données et des opérations** ainsi que des **mécanismes d'abstraction**.

On a une vérification et un renforcement de la sécurité de la programmation avec par exemple une **vérification statique**, une **vérification dynamique** ainsi qu'une **utilisation des données**.

Mais cela pose la nécessité d'un mécanisme de traduction (interprétation ?) ou d'interprétation en langage-machine (sortie compilation d'un compilateur ?).

### Modèle de calcul

On a plusieurs types de données avec les opérations associées avec :
- Une structuration des données de base de la machine sous-jacente
- Nouveaux types de données et opérations
	- définis par le langage : int, long, long long, complex...
	- définis par l'utilisateur à l'aide de struct, d'union (pour du C), ou encore à l'aide de class (POO)

Et on a des mécanismes d'abstraction avec :
- Une structuration du flot de contrôle des données :
	- Sous programmes, fonctions
	- Modules, classes....
- Séparation de la spécification/implémentation
	- On fera donc appel à une interface (.h en C) pour donner la spécification (implémentée dans un .c en C)

### Sécurité de Programmation

On a deux type de vérifications : **statique** et **dynamique**

La vérification statique à lieu avant toute exécution et lors du processus de traduction.
- Par exemple : 
	- Analyse de type (en C/C++, Java)
	- Contrôle d'accès (en C++, Java)

La vérification dynamique quant à elle à lieu lors de l'exécution.
- Par exemple
	- Dépassement de borne d'indice (Cf : IndexOutOfBoundException en Java)
	- Paramètres incorrects

### Compilation et Interprétation

Compilation :
- Le source du programme est traduit, une fois pour toutes (?) en langage-machine. Le résultat est un fichier binaire exécutable, ce fichier est chargé en mémoire pour chaque exécution

![[Pasted image 20230214083348.png]]

Interprétation :
- Le source du programme est traduit "à la volée", instruction par instruction lors de chaque exécution.

![[Pasted image 20230214083503.png]]

Ces deux modes possèdent chacun des avantages et des inconvénients :

- Compilation 
	- Avantages :
		- Possibilité de vérifications et d’optimisations statiques et globales 
		- Renforcement de la sécurité de programmation 
	- Inconvénients :
		- Programme figé 
		- Cycle de développement lourd 
- Interprétation 
	- Avantages :
		- Le programme peut évoluer (et même se faire évoluer luimême) 
		- Grande puissance d’expression 
		- Mise au point interactive 
	- Inconvénients :
		- Vérifications dynamiques seulement 
		- Détection d’erreurs à l’exécution et optimisation délicate

Comme les inconvénients de l'un sont les avantages de l'autres et vice versa, certains développeurs se sont dit "Et pourquoi pas mélanger les deux", cela à donner naissance à Java qui est un langage Compilé et Interpreté