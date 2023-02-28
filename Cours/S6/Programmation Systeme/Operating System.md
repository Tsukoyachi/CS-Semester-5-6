# Operating System
---
### Lessons date :
- 28-02-2023

### Teachers :
- Stéphane Lavirotte

### Tags :


---

## Point de vue

Le système d'exploitation a plusieurs utilités :
- Il va gérer les ressources matérielles
- Il va gérer les besoins logiciels
- Et il va fournir les services communs aux programmes.

Mais en réalité nos utilisateurs intéragissent avec des applications qui agissent directement sur le matériel.

## Hiérarchie de Machines et de langages (avec des interfaces)

Le but est pour le système d'exploitation de combler l'écart entre une machine physique et un langage de programmation.

Et pour cela on a des choses qui se passent à tous les niveaux.

![[Couche os.png | center]]


### La réalité est un peu plus complexe

La vue précédente est simplifié, en réalité c'est un peu plus hétérogène que ça.

Le nombre de couche va être plus ou moins important et peu même ne pas en avoir via une exécution directe sur la micromachine même si c'est peu commun.

La séparation entre les couches elle même n'est pas forcément aussi nête.

Et une machine peut être partagée entre plusieurs entité :
- plusieurs utilisateurs
- plusieurs programme (écrit avec divers langages de programmation)

Son rôle est donc de :
- Transformateur d’interface (cacher la complexité)
- Fournir des services de base (IHM, stockage persistant, accès  
réseau, gestion du temps, ...)
- Être le gérant des ressources

Gestion des ressources (partagées) :
- Ressources physique :
	- Processeur(s), mémoire, disques, périphériques...
- Programmes, processus
- Information :
	- Désignation, localisation
	- Partage et échange entre usagers
- Protection, sécurité, confidentialité

Donc l'attribution des ressources et la prévention/résolution des conflits.

Ils ont des fonctions diverse telles que :
- Statistiques, facturation...
- Gestion du temps, analyse de performances...

Le tout en fournissant une interface commode.

### Classification des Systèmes d’Exploitation par  type d’applications

![[Classification OS par type d'application.png | center]]

## Chronologie simplifiée des premiers sytèmes

Il y a longtemps eu une tension entre deux objectifs contradictoires :
- Améliorer le confort utilisateur "ergonomie" (interface commode)
- Exploiter efficacement les ressources physique des machines "économie" (gestion des ressources)

Histoire :
![[Historique système d'exploitation.png | center]]

Pour le programmeur, on a eu une nette évolution :

- Entre 1945 et 1955, un programmeur "codait" en branchant des fils dans des grandes cartes à trou :
![[Ordinateur 1945 - 1955.png | center]]

- Entre 1955 et 1962 on avait un pupitre pour programmer :
![[Ordinateur 1955 - 1962.png | center]]

- Entre 1960 et 1980 :
![[Ordinateur 1960-1980.png | center]]

- A partir de 1980 :
![[Ordinateur à partir de 1980.png | center]]


## Frise chronologique des système d'exploitation windows

![[Brève histoire OS.png | center]]

### Frise chronoligue système unix 
![[Frise Chronologique Unix.png | center]]

### Frise chronologique Windows
![[Frise Chronologique Windows.png | center]]

### Frise chronologique Apple
![[Frise chronologique Apple.png | center]]

## Caractéristique système d'exploitation

Un système d'exploitation est un ensemble de programmes qui dirige l'utilisation des capacités de la machine. Cela a plusieurs objectifs.

On doit pouvoir faire une abstraction du matériel, pour ne pas avoir à gérer par exemple le type de support mémoire sur lequel je vais écrire.

Il doit également pouvoir gérer le temps (temps partagé, temps réel), parce qu'on va peut être vouloir qu'une opération ait un temps de latence faible.

Gérer la distribution (entre les processeurs, les mémoires, les  
périphériques) pour augmenter l’efficacité et abstraire.

En termes de fonctionnalités ça donne ça :
- Servir les requêtes des processus
	- Appels systèmes: Read, Write, Open, ...
- Traiter les exceptions matérielles dues aux processus
	- Déroutements: Division par 0, Débordement de pile, ...
- Gérer les interruptions matérielles
	- Interruptions: clavier / souris, réseau, ...
- Fournir un ensemble de services spécifiques
	- Assurer des tâches d’entretien du système (swap, caches, pages, ...)

### Elements d'un système d'exploitation

On va donc dénoter 3 éléments dans un système d'exploitation :
- Les programmes utilitaires :
	- Ensemble de programmes outils permettant de manipuler le système à base de commandes "basiques", par exemple `shell, cp, rm, mount`
- La/Les librairies :
	- Bibliothèque(s) standardisées de fonctionnalités pour les  programmes utilisateurs, avec par exemple `La librairie C (libc), la librarie mathématiques (libm)`
- Le Noyau
	- Programme qui est le premier à s’exécuter après le chargeur
	- Fournit les abstractions pour la gestion des processus de la  Smémoire, des systèmes de fichiers, ...

### Architecture d'un système d'exploitation

![[Architecture détaillée OS.png | center]]


Si on simplifie ça donne ça :
![[Architecture simplifiée OS.png | center]]

Donc le système d'exploitation est là pour bien partager les ressources.

Par exemple, envoyer l'appui d'une touche à la bonne application ou alors s'assurer que les processus n'ont pas accès à la mémoire des autres.

Dans la gestion des ressources ont a :
- Le partage des ressource de calcul avec la gestion des processus
- Le partage de la mémoire entre les différents processus avec la gestion mémoire
- Le partage des dispositifs (clavier, souris, écran, ...) avec la gestion des entrées/sorties.

## En résumé, un système d'exploitation

Il a trois grandes fonctionnalités :
- Gérer la mémoire
- Gérer les entrées-sorties
- Gérer les processus

On attend donc de lui :
- Fiabilité, robustesse
- Prédictibilité, déterminisme
- Ergonomie, facilité d'utilisation
- Efficacité, performances
- Généralité, universalité
- Flexibilité, adaptabilité, extensibilité
- Transparance

On a jamais douter de la fiabilité d'un système d'exploitation...

Enfin si windows avec ses blue screen, mais en réalité les blue screen ne sont pas dû qu'au système d'exploitation, il communique directement avec le matériel, si le matériel est défaillant, le système d'exploitation le sera aussi.

## Cacher la complexité sous une "jolie interface"
- Et c’est vraiment la formule utilisée dans les livres et  
surtout le livre de référence:
- Tanenbaum. Modern Operating Systems (4th ed, 2014). page 5

![[Modern Operating System quote.png | center]]

###