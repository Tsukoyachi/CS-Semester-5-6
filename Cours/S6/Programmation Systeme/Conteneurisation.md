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
![[Pasted image 20230509081124.png | center]]

Un hyperviseur est une plate-forme de virtualisation qui permet à plusieurs systèmes d’exploitation de fonctionner en parallèle dans une seule machine physique.

### Machine virtuelle vs Conteneurisation

Machine Virtuelle :
![[Pasted image 20230509081950.png | center]]

On va pouvoir simuler une machine physique, de les exécuter sous forme de VM qui elles même auront un OS. Mais ne pourrait on pas se passer de ce deuxième OS ?

Conteneurisation :
![[Pasted image 20230509082052.png | center]]

Légèreté et isolation pour l'exécution de processus.

On constatera que le conteneur offre déjà un gain en terme de taille, une vm c'est plusieurs giga octets alors que pour un conteneur on parlera en mega octets.

Fait directement appel à l'OS (noyau) de sa machine hôte pour réaliser ses appels système et exécuter ses applications.

Isolation des applications, de leurs dépendances (ex: bibliothèques) et de leur environnement d’exécution.

Evite d’avoir à gérer la cohérence globale de toutes les dépendances sur un même système (gain de temps/productivité).

On aura aussi quelque chose qui marchera sur toute machine possédant un noyau Linux.
Pour windows, cela fonctionne grâce à WSL (windows subsystem linux).
Pour Mac on y reviendra plus tard.

### Histoire de la technologie des conteneurs

![[Pasted image 20230509083031.png | center]]

### Besoins pour mettre en oeuvre l'isolation des conteneurs

- On doit isoler le système de fichier
Pour cela on va utiliser `chroot` afin de changer de racine de répertoire.

- Namespace
Pour donner une vue sur une ressource globale partagée (entre tous les processus)

- Cgroups
Création de groupes de processus et gestion des droits.

- Seccomp
Sécurité autour des appels systèmes.

Ses fonctionnalités sont founies par le noyau (via des appels systèmes) :
- Syscall : API des fonctionnalités mises à disposition par le noyau
- Actuellement (6.3) : [plus d'infos ici](https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/tree/arch/x86/entry/syscalls?h=v6.3)
- Bascule entre le « User Space » et le « Kernel Space »
- Cf slide 14 et 15 du cours « Processus et Threads »

#### chroot

![[Pasted image 20230509083627.png | center]]

On va utiliser chroot pour changer de racine de système de fichier :
- Ce mécanisme permet de sécuriser un serveur web par exemple en masquant le reste de l'arborescence de fichier à de potentiels attaquant
- Le plus vieux mécanisme (1979)
- N’avoir accès qu’à une partie du système de fichiers (FS) pour un processus

#### Container Namespace

*What you can see*
Un conteneur namespace va envelopper une ressource système globale dans une abstraction qui donne aux conteneurs d'un namespace l'impression d'avoir leur propre instance isolées de la ressource globale.

![[Pasted image 20230509084210.png | center]]

Le but va être de masquer des infos du système au conteneur, on ne va récupérer que certaines informations.

#### Cgroups

*What you can use*
Limiter les ressources utilisées par un conteneur (groupe de processus).
Contrôle fin de l'allocation, de la priorisation, du refus et de la gestion des ressources du système.

![[Pasted image 20230509084310.png | center]]

Ce mécanisme va empêcher un processus de demander trop de ressources, si jamais celui-ci viole cette limite il se fait tuer ainsi que tout son conteneur.

##### Cgroups controllers
On possède toute une API au niveau du noyau Linux pour ça :
![[Pasted image 20230509084504.png | center]]

#### Seccomp
Filtre devant tous les syscall  
-  Bloque à l’entrée de l’appel système  
-  Réalise à base de BPF (Berkeley Packet Filters)  
Utilisé à partir de libseccomp  
-  Autoriser uniquement les appels systèmes que l’on souhaite  
Permet de rendre moins vulnérable le système.

Ce mécanisme va empêcher d'effectuer certains appels système lorsque l'on en a pas le droit.

#### Sécurité
- Les Cgroups vont limiter l'accès aux ressources.
- Les Namespaces : virtualise l'accès aux ressources.
- Seccomp : limite les accès aux appels systèmes
- Politique de contrôle d'accès obligatoire (MAC: Mandatory Access Control, i.e. type AppArmor)
- Conteneurs sans racine

### Interface utilisateur

Ces différentes fonctionnalités (chroot, namespace, cgroups, seccomp, ...) sont offertes par le noyau et accessible par /sys depuis l'espace utilisateur.

Besoin d'interface utilisateur pour faciliter la manipulation des conteneurs.
Il existe différentes interfaces :
- LXC : API bas niveau
- LXD : API haut niveau
- Podman: moteur de conteneur sans daemon
- CRI-O: optimisé pour Kubernetes
- containerd: std indus simple et robuste
- Docker: utilise runC (initialement LXC)

#### Open Container Initiative (OCI)

[OCI](https://opencontainers.org/): Projet de la Linux Foundation

Afin que personne ne puisse avoir le monopole des conteneurs, on a des normes qui existe pour la virtualisation par isolation au niveau des systèmes d'exploitation.

Deux spécifications (toujours en évolution):  
- Runtime-spec: spécification de l’exécution  
	- [RunC](https://github.com/opencontainers/runc) (utilisé par Docker): Go: 80%, Shell: 15%, C: 5%  
		- CLI pour la création et l'exécution de conteneurs sur Linux conformément à la spécification OCI  
	- [RailCar](https://github.com/oracle/railcar) : Rust: 99%, Shell: 1%  
		-  Implémentation Rust de la spécification OCI runtime  
-  [Image-spec](https://github.com/opencontainers/image-spec): spécification du format de sauvegarde  

Plus de 13 implémentations différentes des conteneurs en 2016

## Docker

![[Pasted image 20230509085844.png | center]]

C'est une plateforme de conteneurisation qui permet de créer/déployer/exécuter des applications.

Il se base sur plusieurs éléments :
- Moteur Docker : Permet de créer/gérer les conteneurs et utilise le noyau Linux pour isoler les ressources.
- Images Docker : Système de fichiers, contient le code, les bibliothèques, les fichiers de configuration, les dépendances
- Conteneurs Docker : instance en cours d’exécution d’une image, créer à partir d'une image. Léger et démarrage rapide (plus rapide qu’une VM)
- Registres Docker : dépôt où stocker les images Docker. Il peut être public ou privé.
- API: manipulation des images, conteneurs, ...

### Images vs Conteneurs
Dockerfile (patron/modèle):  
-  Instructions pour construire une image  
Image (classe):  
-  Système de fichiers constitué d’un ensemble de strates (layers)  
Conteneur (instance):  
-  Une instance en cours d’exécution d’une image
![[Pasted image 20230509090245.png | center]]

### Images et registres
![[Pasted image 20230509090316.png | center]]

### Docker CLI
![[Pasted image 20230509090340.png | center]]

### Définition de Docker

Docker est une plateforme qui permet d'empaqueter nos applications dans des exécutables déployables appelés conteneurs, avec toutes les bibliothèques et dépendances nécessaires au système d'exploitation

![[Pasted image 20230509090431.png | center]]

### Mise en place de Docker sur d'autres OS que Linux

La conteneurisation repose sur des mécanismes proposés par le noyau  
- Aujourd’hui, seul le noyau Linux propose ces mécanismes  
- Mais pas le noyau Windows NT ou le noyau Mac OS...  
Comment cela peut fonctionner sous d’autres OS que Linux ?...  
- Docker Desktop sous Windows ou Mac

#### Illustration de Docker sous Windows

![[Pasted image 20230509090616.png | center]]

### Dockerfile

C'est un fichier décrivant les étapes de construction d'une image docker constitué des éléments suivants : 
- `# Comment`
- `INSTRUCTION arguments`
[Document de référence](https://docs.docker.com/engine/reference/builder/)

Une image se créer **forcément** à partir d'une image existante, donc un dockerfile commencera forcément par une instruction `FROM` :
- `FROM <Image de base>`
- Initialisation de la construction (obligatoire/première instruction)
- quelques images de base récupérable avec un docker pull (je crois) : `scratch, alpine, busybox, debian, ubuntu` (**Ici on n'emporte pas un OS complet quand on fait FROM ubuntu par exemple**)

Commande docker pour construire l'image :
- `docker build [<options>] <path> | <url> | -`
- Exemples :
	- `docker build . | docker build - < Dockerfile`
	- `docker build -t [<repository>/]<name>[:<tag>] .`

Voici une liste de quelques instructions utiles :

`FROM [option] <name>[:<tags>] [AS <name>]`
- Initialise la construction à partir d'une image de base

`ENV <key>=<value>`
- Définit des variables d'environnement pour le container

`ARG <var>[=<value>]`
- Définit des variables pour la construction (peut être modifié lors du build)

`WORKDIR <path>`
- Equivalent à cd (avec création si nécessaire
- Commandes successives relatives à ce répertoire

`RUN <cmd args> | RUN ["cmd« , "arg1", "arg2"]`
- Exécute une commande dans un Shell Unix

`ADD ou COPY [options] <src> <dest>`
- Ajoute des fichiers locaux à l’host dans l’image

Point d’entrée / commande
- Définir la commande à lancer au démarrage du conteneur
- CMD et/ou ENTRYPOINT
[Comprendre l'interaction entre CMD et ENTRYPOINT](https://docs.docker.com/engine/reference/builder/#understand-how-cmd-and-entrypoint-interact)

CMD et ENTRYPOINT  
-  `CMD ["cmd", "arg1", "arg2"]  `
Spécifie la commande à lancer au démarrage du container  

-  `CMD ["arg1", "arg2"]  `
Spécifie les options à ENTRYPOINT  

- `ENTRYPOINT ["cmd"]  `
Spécifie la commande principale à lancer au démarrage du container

`LABEL <key>=<value> ...`
- Ajoute des métadonnées à l’image

`USER <user>[:<group>]`
- Définit l’utilisateur courant (change de root)

`EXPOSE port[/protocol]`
- Port sur lequel le container sera à l’écoute des connexions

`VOLUME ["path"]`
- Créer un point de montage

`STOPSIGNAL <signal>`
- Définit le signal qui sera envoyé au conteneur pour le quitter

`HEALTHCHECK [options] CMD <command> | NONE`
- Vérifie l'état du conteneur en exécutant une commande à l'intérieur du conteneur

### Docker Image

#### Image == Layer
Chaque layer est une image avec un tag autogénéré.

Chaque layer stocke les modifications par rapport à l'image sur laquel il est basé

Chaque instruction dans un Dockerfile résulte en un layer  
(sauf pour les constructions en multi-étapes)  

Les layers sont utilisés pour éviter les informations redondantes  

Les layers permettent de faire une construction incrémentale (comme pour un Makefile, on ne reconstruit que ce qui est nécessaire)

Une terminologie un peu confuse  
- Quand on parle d’image, on parle généralement d’un ensemble de layers avec un tag attribué par un humain

#### Deep dive into image
![[Pasted image 20230509092707.png | center]]

