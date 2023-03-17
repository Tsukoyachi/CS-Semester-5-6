# Processus VS Thread
---
### Lessons date :
- 14-03-2023

### Teachers :
- Stéphane Lavirotte

### Tags :
- #Processus
- #Thread
- #C
- #système 
---

### Rappel sur les Processus
- Entité dynamique :
	- Contexte d'exécution d'un programme séquentiel
	- Entité active opérant sur son environnement en exécutant un programme
- Etat courant de la "Machine virtuelle" exécutant le programme associé au processus
	- Inclut l'état \[d'une partie] de la machine physique
- Etat d'attribution du GPU

Mais pour quoi faire ?

La programmation d'un processus **ne tient pas compte de l'existance simultanée d'autres processus**, y compris s'il existe **plusieurs instances du même processus**.

Cela procure un **gain de vitesse**, en effet le processeur est l'élément le plus rapide d'un ordinateur, et la plupart des processus intéragissent avec d'autres composant tel que :
- La mémoire
- Unité de stockage
- réseau
- les utilisateurs
Donc lorsqu'un processus attend des données, un autre peut s'exécuter.

**Les principes de processus et de parallélisation sont anciens.**

#### Pourquoi fork() ?

Fork est une commande permettant de créer un processus fils partagant le même code que le processus père.

Dans la plupart des cas, **fork** est suivi de l'appel à **execxx()** (permettant de remplacer le code actuel par un autre code spécifié en paramètre avec des arguments).
Certains systèmes utilisent une combinaison des deux appels.

L'avantage de fork, c'est sa simplicité, il n'y a aucune information à passer.

Cependant on aimerait pouvoir gérer plusieurs aspect du procesuss fils :
- Descripteur de fichier, variables d’environnement, droits, ...
Mais fork() ne le permet pas car il n'utilise aucun paramètre.

En l'absence de fork(), la création de processus nécessite une multitude de paramètres.

#### Se passer de fork() ?

Win32 possède une interface de création de processus :
```c
BOOL WINAPI CreateProcess(
 __in_opt LPCTSTR lpApplicationName,  
 __inout_opt LPTSTR lpCommandLine,  
 __in_opt LPSECURITY_ATTRIBUTES lpProcessAttributes,  
 __in_opt LPSECURITY_ATTRIBUTES lpThreadAttributes,  
 __in BOOL bInheritHandles,  
 __in DWORD dwCreationFlags,  
 __in_opt LPVOID lpEnvironment,  
 __in_opt LPCTSTR lpCurrentDirectory,  
 __in LPSTARTUPINFO lpStartupInfo,  
 __out LPPROCESS_INFORMATION lpProcessInformation
)
```

L'interface est lourde, ça fait réfléchir à deux fois avant de créer un processus via cette interface.

#### Limitation des Processus

Un processus regroupe les ressources (données, fichier) et l'exécution.

Les processus sont une abstraction pour grouper des ressources.

Les processus induisent une certaine lourdeur avec un changement de contexte qui est lourd donc coûteux à créer et à détruire, c'est également pas super efficace (changement de contexte lent), et un contexte mémoire important.

Il y a également pas (peu) de partage de mémoire :
- pas intégré dans les langages de programmation
- Offerts par services OS complexes, pas souples (IPC)
Un processus pourrait tiper parti d'une architecture multiprocesseurs/multi-coeurs.


### Threads
Un thread est une abstraction de l'exécution.

Cette notion combine les avantages suivants :
- Exécution parallèle
- Partage de code et données applicatifs communs

Facile à mettre en oeuvre :
- Programmable
- Contrôlable
- Configurable

Efficace et passe à l'échelle

Les Threads permettent donc d'intégrer dans la programmation des applications les bénéfices de la programmation parallèle tout en conservant une partie de la légéreté de la programmation classique (en particulier vis-à-vis de la mémoire).

Un Thread est un **contexte d'exécution ordonnable** qui comprends un compteur ordinal, des registres et une pile.

Plusieurs Threads partagent le même espace mémoire, **il n'y a pas de protections entre les threads d'un même processus**.

Les programmes simples comportent un seul thread ce qui n'engendre pas de surcoût.

![[Pasted image 20230314082547.png | center]]


### Données Processus vs Threads

Données par Processus :
- Espace d'adressage
- Variables globales
- Fichiers ouverts
- Processus fils
- Alarmes en attente
- Signaux et gestionnaires de signaux
- Informations de comptabilité

Données par Thread :
- Compteur d'instruction
- Registres
- Pile
- Etat

### Intérêts des Threads

Dans une application, plusieurs activités s’exécutent en  
parallèle  
- Les threads sont un bon modèle de programmation  
- Comme les processus  

Les threads partagent le même espace mémoire  
- Plus efficace que les mécanismes fournis par les OS (IPC)  
- Indispensable pour certaines applications  

Les threads ont peu d’information propre  
- Très faciles à créer/détruire  
-  En général, 100 fois plus rapide à créer qu’un processus  

Permettent de recouvrir le calcul et les I/Os  
-  Si les threads ne font que du calcul, peu d’intérêt  

Très pratique sur les systèmes multi processeurs/cœurs

### Problèmes soulevés par les Threads

Que se passe-t-il lorsqu’un processus possédant plusieurs threads fait l’appel système fork() ?  

Problème:  
-  Les threads sont ils recréés ?  
	-  non : blocages  
	-  oui : problème de lourdeur. Et que faire des attentes éventuelles ?  (clavier, réseau,...)  

Au vu des données partagées, les risques d’erreurs sont nombreux:  
- double allocation de mémoire  
- fermeture accidentelle de fichier

Ces problèmes peuvent être résolus, mais demande une conception soignée, et des arbitrages

### Mise en oeuvre des Threads

#### User Space vs Kernel Space

![[Pasted image 20230314083326.png | center]]

Voici une illustration du User Space / Kernel Space :

![[Pasted image 20230314083416.png | center]]


#### Implémentation des Threads en User Space
Il est possible de créer une bibliothèque en espace utilisateur pour les threads.

Principes :  
-  Un seul processus  
-  Un seul thread noyau  
-  Les fonctions de création de thread sont des appels de bibliothèque  

Chaque processus a une table de threads :  
- Contient les informations pour les threads du processus  
- Mise à jour quand changement d’état  

Si un thread va faire une opération potentiellement bloquante  
-  Il appelle une méthode spéciale  
-  Cette méthode vérifie si le thread doit être mis en attente  
-  Si oui, modification de la table, recherche d’un autre thread,  chargement du PC et registres...

##### Avantages et Inconvénients des Threads en User Space
Avantages :
- Changement de thread ("thread switching") très rapide
	- Pas de passage en kernel space

Inconvénients :
- N'utilise pas les multiprocesseurs
- Les appels système bloquant bloquent tous les threads, par exemple lire une touche d'un clavier peut être bloquant ou pas. 
  La solution est de wrapper les appels système pour les rendre non bloquants.
  - Il est possible d'utiliser ses propres fonctions pour les accès réseau, en général c'est impossible pour accéder au disque.
- Un défault de page bloque tous les threads.
- Eventualité d’inter-blocages, les threads doivent collaborer  
	- thread_yield  

En pratique beaucoup de travail/contraintes pour gérer le blocage et l’ordonnancement alors que c’est l’intérêt des threads.

#### Implémentation des Threads en Kernel Space
Le noyau gère les threads, il a une table des threads dans le système.

La création et la destruction sont effectués par le noyau à travers des appels système :
-  Plus coûteux qu’en user space  
-  Utilisation de pools de threads  

Quand un thread bloque, le noyau peut choisir un autre thread du même processus ou pas.

##### Avantages et Inconvénients des Threads en Kernel Space
Avantages  
-  Les appels systèmes bloquants ne bloquent que le thread  
concerné  

Inconvénients  
-  Toutes les opérations sur les thread sont résolues par des appels système  
-  10 à 30 fois plus lent  
-  Doit être universel → le coût des options moins usuelles est payé par tous les utilisateurs  
-  Plus gourmand en mémoire

#### Autres approches
Entrelacement  
-  Le principe est de permettre les deux modes de fonctionnement :  
	-  Exécuter n threads utilisateurs sur p threads noyau  
-  Le programmeur est maître de ses priorités  
-  Le noyau ignore l’importance de chaque thread noyau  

Threads spontanés  
-  Il s’agit d’associer un événement à la création d’un thread  
-  Cette approche est légère car les threads ainsi créés ont une durée de vie limitée (exemple traiter un message arrivant sur le réseau)

#### Thread POSIX
La norme POSIX définit l’API pthreads (POSIX 1.c)  
```c
#include <pthread.h> 
``` 

Création  
```c
int pthread_create(pthread_t *thread,  
					const pthread_attr_t *attr,  
					void *(*start_routine) (void *),  
					void *arg);  
```

Destruction  
```c
void pthread_exit(void *retval);  
```

Attente d’un autre thread  
```c
int pthread_join(pthread_t thread, void **retval);  
```

pthread_attr_init : p ermet de créer et initialiser la  
structure de type pthread_attr_t  

L’appel pthread_yield permet à un thread de rendre la  
main

#### Pthread sous Linux
L’API pthread sous Linux est implémentée en espace noyau.  

Historiquement (avant le noyau 2.6)  
-  LinuxThreads était l’implémentation  
-  Elle n’était pas conforme avec POSIX  

Depuis le noyau 2.6  
-  NPTL (Native Posix Thread Library) offre un implémentation plus performante  
- Conforme à POSIX  
- Avec NTPL, tous les threads d’un même processus ont le même  identifiant

### Conclusion
Sur le plan de l’utilisation la programmation multithread est bien plus complexe que l’approche mono-thread.  

Réentrance  
-  Cette notion caractérise le fait de pouvoir être utilisé simultanément par plusieurs tâches  
-  Une fonction réentrante permet d’être appelée dans un programme multithread et de toujours fournir un résultat consistant  

Dans ce type de programmation :  
-  soit mécanismes de synchronisation  
-  soit fonctions réentrantes
