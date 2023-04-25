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

