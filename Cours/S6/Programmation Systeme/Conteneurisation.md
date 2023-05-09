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
