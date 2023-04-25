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
	- Pagination
	- Segmentation
- Echange sur mémoire secondaire (va et viant 'swap')

## Mémoire Virtuelle

Les adresses machines couvrent un espace plus grand que la mémoire physique, chaque processus peut même disposer de son propre espace d'adressage.

Le matériel et le système d'exploitation assurent automatiquement la montée en mémoire physique des informations utiles à l'exécution courante.
- La mémoire physique sert de cache à la mémoire virtuelle
- On doit disposer d'un mécanisme de traduction entre l'adresse virtuelle et l'adresse physique

### Traduction des adresses
Exécution à chaque accès mémoire, la coopération du matériel est donc indispensable.

MMU (Memory Management Unit) assure la traduction en adresse physique, c'est peu coûteux (coûteux et compliqué si c'est fait au niveau logiciel), et c'est transparant pour les programmes.

Si l'information adressée par l'instruction courante n'est pas en mémoire physique :
- l'instruction courante est suspendue, de même que le processus qui la contient ; un déroutement est déclenché
- le système d'exploitation prend la main et fait monter  l'information en mémoire physique
- lorsque le processus est ordonnancé à nouveau, l'instruction  suspendue est reprise à l'accès mémoire

**Voici une illustration de la traduction d'adresses**
![[Pasted image 20230425083745.png | center]]

### Segmentation et Pagination

**Segmentation**
La segmentation c'est le fait de séparer la mémoire en segment de **types** différents et de tailles variables, par exemple : `Ce segment va contenir le code de mon programme, ce segment va contenir les données de mon processus.`

La segmentation on la voit aussi quand on dépasse une zone mémoire alloué avec un pointeur, la fameuse `Segmentation fault`.

**Pagination**
La pagination est le fait de séparer la mémoire en bloc de taille fixe que l'on va appeler page. 
Le découpage est aveugle donc contrairement à la segmentation il n'y a pas de sens fonctionnel. 
Cela facilite les mécanismes de traduction car on peut faire référence directement au n-ème mot d'une page .
Et cela facilite les mécanismes d'allocation car on peut laisser `quelques pages blanche`.

**Systèmes hybride**
- Pagination segmentée, dans une page on crée plusieurs segments
- Segmentation paginée (modèle Linux), dans un segment on crée n pages.

#### Segmentation
Vue cohérente avec celle de l’utilisateur, l'exemple le plus connu est l'Intel 8086 et ses quatre registres :
- `CS`, pour `Code Segment` : pointe vers le segment contenant le  programme courant
- `DS`, pour `Data Segment` : pointe vers le segment contenant les  données du programme en cours d'exécution
- `ES`, pour `Extra Segment` : pointe vers le segment dont l'utilisation  est laissée au programmeur
- `SS`, pour `Stack Segment` : pointe vers le segment contenant la pile

Association de la protection avec le segment, en associant des *permissions* suivant le segment (lecture seule, écriture seule, ...).
Cela permet d'éviter les accès illégaux (Segmentation Fault)

Partage de segments entre processus quand deux processus pointent sur la même entrée de la table.

![[Pasted image 20230425085135.png | center]]

Un exemple concret avec la commande `cat /proc/pid/maps` :
![[Pasted image 20230425085221.png | center]]

#### Pagination
La pagination permet d’avoir en mémoire un processus donc les adresses sont non contigües.

Pour réaliser cela, on partage l’espace d’adressage du processus et la mémoire physique en :
- Cadres de page (frames): mémoire physique découpée en zones de taille fixe, taille en puissance de 2 => entre 512 bytes et 8192 bytes.
- La mémoire logique est également subdivisée en blocs de la  même taille appelés pages 
	- Taille pages = Taille cadres
	- Adresse logique = numéro de page + déplacement dans le page
- Table des pages: liaison entre numéro de page et cadre de page (une table par processus). On conserve l’emplacement des pages dans une tables de transcodage.
	- Table de pages: traduit l’adresse logique en adresse physique.

![[Pasted image 20230425085752.png | center]]

##### Remplacement de Page
Quelle page remplacer lorsqu'une nouvelle page doit monter en mémoire physique ?

Principe d'optimalité (Peter Denning)
- Remplacer la page qui ne sera pas utilisée dans le temps le plus  long, sauf qu'on a pas de boule de cristal donc on ne le sait pas.

On a donc quelques algorithmes de remplacement de page :
- FIFO : First In First Out -> Problème de l'anomalie FIFO
- LRU : Least Recently Used -> Difficile à implémenter
- NRU : Not Recently Used -> Le plus courant (souvent confondu avec LRU)
- NFU : Not Frequently Used -> Incrémente un compteur à chaque utilisation
- Aging : Variante de NFU

Gestion par processus ("Working Set")
- Prédiction des pages utiles de chaque processus

##### Pagination: Conséquence sur la Programmation
Pagination: abstraction invisible au programmeur mais a des conséquences sur la gestion de la mémoire.

Exemple :
Imaginons qu'une page ait une taille de 128\*sizeof(int) et qu'un tableau soit stocké ligne par ligne.
![[Pasted image 20230425090550.png | center]]

Les deux codes suivants ne sont pas équivalents en termes de gestion mémoire (le premier peut nécessiter des swaps) :

1er code :
```c
int tab[128][128];
for(int j=0;j<128;j++){
	for(int i=0;i<128;i++){
		tab[i][j] = 0 ;
	}
}
/* parcours les pages */
```

2e code :