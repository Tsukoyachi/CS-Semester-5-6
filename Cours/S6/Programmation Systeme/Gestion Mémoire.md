# Gestion Mémoire
---
### Lessons date :
- 25-04-2023

### Teachers :
- Stéphane Lavirotte

### Tags :


---

## Introduction à la gestion mémoire

La mémoire est une ressource importe.
Elle est géré par le système d'exploitation afin d'offrir un espace d’adressage indépendant aux processus.

C'est une ressource hierarchisée :
- **Mémoire cache (dans le processeur)** qui est très rapide, présente en faible quantité et elle est gérée par le matériel.
- **Mémoire principale (RAM)** elle est rapide, présente en grande quantité et elle est gérée par le système d'exploitation.
- **Mémoire secondaire (disque dur)** elle est lente, présente en très grande quantité et elle est également gérée par le système d'exploitation

![[Pasted image 20230425080634.png | center]]

### Représentation des adresses mémoires

Il y a différentes manières de manipuler les adresses :
- Code source (pour le programmeur) avec des adresses symbolique, par exemple : `int compteur`
- Module objet (suite à la compilation) avec des adresses traduites, par exemple : `Le 50e mot depuis le début d'espace mémoire`
- Module exécutable (suite au chargement) avec des adresses absolues, par exemple : `Par exemple l'emplacement mémoire situé à l'adresse FFF7`

Donc le programmeur et les processus manipulent des **adresses logique** alors que le système et le matériel manipulent des **adresses physiques**.

### Mémoire Réelle

Contraintes de la mémoire réelle :
- Les adresses-machines ne référencent que des instructions ou données en mémoire physique.
- L'ensemble du processus en cours d'exécution doit donc être en mémoire physique.
- Les adresses doivent être contigües

Cela pose un problème pour la gestion de la multiprogrammation.

Il existe différents modèle de gestion de la mémoire.

#### Partitions fixes

![[Pasted image 20230425081310.png | center]]

Ce procédé fonctionnait bien à l'époque mais pose plusieurs inconvénient majeurs donc on oublie.

#### Partitions variables

![[Pasted image 20230425081446.png | center]]

- On ne sait pas d'emblée combien de mémoire un processus va prendre à cause du mécanisme d'allocation dynamique de C. Donc il faut laisser un peu de place entre les processus pour leur laisser la possibilité de grossir.
- Le mécanisme de création des processus se place dans le premier trou disponible, sauf que dans cet exemple, le processus 4 laisse de l'espace entre lui et le processus 3, en réalité ci l'on laisse ce phénomène s'étendre on va se retrouver avec un gruyère de mémoire, c'est donc au système d'exploitation de s'en occuper, mais tout déplacer est trop coûteux.
- Quand on va faire le swap in  de processus 2, on va le réinsérer ailleurs, mais comment fait on le déplacement mémoire du processus 2 ?

### Problème liés à la multiprogrammation

Protection, il faut être capable d'interdire à un processus l'accès en espace mémoire des autres processus et du système d'exploitation  avec :
- registres de protection : base + limite
- bits de protection des pages de la mémoire

Translation (Relocation), Un processus doit pouvoir être chargé à n'importe quelle adresse mémoire :
- Translation des adresses globales lors du chargement du programme en mémoire
- Utilisation des modes d’adressage relatif à un registre  (pile/instruction/registre de segment)

Allocation/Réallocation, un programme doit obtenir la zone mémoire dont il a besoin si la mémoire est disponible et modifier ses besoins pendant son exécution.

#### Problème de disponibilité de mémoire

La mémoire disponible peut être insuffisante à un moment donné, on a 3 mécanismes pour gérer ce manque de mémoire :
1. Interdire la création de nouveau processus (exemple Minix)
2. Placer certains processus en mémoire secondaire pour libérer de l'espace mémoire en attendant que la charge mémoire diminue -> **Les processus 'swapé' ne sont pas exécutables**
3. Placer des morceaux de la mémoire des processus en mémoire secondaire : mécanisme de **mémoire virtuelle**
    Cela nous donne des processus qui sont **partiellement exécutables**.

### Conclusion partielle : problématiques soulevées

Problématiques :
- Augmentation (plus de mémoire que disponible)
- Protection/Partage
- Translation (Relocation)
- Allocation / Réallocation (problème de fragmentation)

Plusieurs technique sont utilisées pour pallier aux problèmes de la multiprogrammation et au manque de mémoire.
- Mémoire virtuelle
	- Utilisation de modes d'adressages relatifs
	- Translation des adresses (réelles <-> virtuelles)
	- Pa