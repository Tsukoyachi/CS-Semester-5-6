# Conteneurisation
---
### Lessons date :
- 09-05-2023

### Teachers :


### Tags :


---

## Virtualisation

La virtualisation c'est le fait d'exécuter plusieurs systèmes d'exploitation et/ou applications isolés sur un même hôte physique.

On peut le faire via une **machine virtuelle**, le but sera alors d'isoler un système d'expoitation sur une machine en émulant son matériel (stockage, carte graphique, réseau, ...) par exemple avec VirtualBox. Ajout d'un OS complet, exemple Linux.

Pour ne pas avoir à ajouter d'OS supplémentaire on va faire de la **conteneurisation**, le but sera alors d'isoler un/plusieurs processus sur une machine hôte. 

Le conteneur collabore avec le noyau de la machine pour ne pas avoir à l'embarquer dans celui-ci. On pourra donc utiliser des fonctionnalités du noyau pour limiter le champ d'exécution du/des processus donnés.

Exemple avec Docker, LXC, Podman, runC, containerd, ...

### Virtualisation et Hyperviseur

Hyperviseur : Moniteur de la machine virtuelle
![[Pasted image 20230509081124.png]]

Un hyperviseur est une plate-forme de virtualisation qui permet à plusieurs systèmes d’exploitation de fonctionner en parallèle dans une seule machine physique.

### Machine virtuelle vs Conteneurisation

Machine Virtuelle :
![[Pasted image 20230509081950.png]]

On va pouvoir simuler une machine physique, de les exécuter sous forme de VM qui elles même auront un OS. Mais ne pourrait on pas se passer de ce deuxième OS ?

Conteneurisation :
![[Pasted image 20230509082052.png]]

Légèreté et isolation pour l'exécution de processus.

On constatera que le conteneur offre déjà un gain en terme de taille, une vm c'est plusieurs giga octets alors que pour un conteneur on parlera en mega octets.

Fait directement appel à l'OS (noyau) de sa machine hôte pour réaliser ses appels système et exécuter ses applications.

Isolation des applications, de leurs dépendances (ex: bibliothèques) et de leur environnement d’exécution.

Evite d’avoir à gérer la cohérence globale de toutes les dépendances sur un même système (gain de temps/productivité).

On aura aussi quelque chose qui marchera sur toute machine possédant un noyau Linux.
Pour windows, cela fonctionne grâce à WSL (windows subsystem linux).
Pour Mac on y reviendra plus tard.

### Histoire de la technologie des cont