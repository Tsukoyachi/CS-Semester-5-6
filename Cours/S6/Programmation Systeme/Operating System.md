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

