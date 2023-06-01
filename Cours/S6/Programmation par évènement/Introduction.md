
![[SI3-Programation par événement - intro - cours 1.pdf]]

---
# Introduction

*Insérer une intro*

---

# Démarche UCD

UCD = User-Centered Design

Ce qui nous intéresse est de faire une démarche centrée utilisateur.

Une démarche centrée utilisateur :
- Identifier les problèmes que les utilisateurs pourraient avoir aux quotidien
- Analyser des solutions
- Maquetter des solutions
- Les tester auprès d'utilisateurs
- Puis déployer la solution

Savoir coder ne suffit pas, il faut que ce que l'on implémente corresponde aux besoins utilisateur.

Il faut donc être capable de justifier les décisions prises.

Pour cela on conçois et on fait une maquette qui nous permettra d'avoir des feedbacks, et via plusieurs itérations on fixera les critères que devra respecter notre produit.


![[Pasted image 20230214141431.png | center]]

## Ergonomie (Usability)

Il s'agit de l'un des critères à prendre en compte lors de la conception d'une **bonne** IHM.

Pour cela on a le schéma de Nielsen qui résume bien :

![[Pasted image 20230214141751.png | center]]

L'ergonomie se résume en quelques point principaux :
1. **La simplicité d'utilisation**, une personne peut trouver une interface intuitive alors qu'une autre personne ne comprendra pas. Le but à atteindre est que peut importe l'action souhaité par l'utilisateur, il soit capable rapidement de voir le chemin à suivre pour exécuter celle-ci.
2. **La transparance du système**, si un logique est en cours d'exécution, l'utilisateur doit être au courant. Il ne doit pas douter sur le fait qu'une action soit en cours ou non. Si l'on charge un fichier, avoir une animation de chargement rassure l'utilisateur puisqu'il sait que sa demande est en cours de traîtement.
3. **Les retours d'informations**, le système doit avertir l'utilisateur afin de l'empêcher d'exécuter des informations interdites. Imaginons que celui-ci remplisse un formulaire mais qu'il rentre une informations incorrectes. Une bonne IHM le préviendra 

**A ne pas confonde avec l'expérience utilisateur (UX)**.

## Dimension d'expérience utilisateurs

Quel type d'expérience la personne va vivre ?

Plusieurs dimensions qui vont décrire plus finement ce que va vivre l'utilisateur :
- Visuel/Esthétique : Est ce que c'est beau ou pas ?
- Emotionnelle : Est ce que je vais m'énerver ou être dégoûté ou être content en voyant l'interface.
- Stimulation : 
-  Identification :
- Sens et Valeur :
- "*Relatedness*" :

Un exemple avec contexte :
• "I am passing by at this park every Sunday and this bench has not been repaired for weeks (**Identification**). It is time now to report that, so it will get fixed. It is not really a problem or unsafe, but the bench is simply not usable in the current state (**Meaning and Value**). It seems important now to make sure that the appropriate person is informed about that bench (**Social relatedness**), I think I should use the application to report the incident, because I want to be a good citizen (**Identification**). 
• “If the photo is good (**Aesthetic experience**), they (the local administration) will see the problem…” 
• “If I make a picture you are afraid (**Emotion**) that there will be a kind of retaliation?” 
• “Besides going to report your idea, the application could ask (**Stimulation**) if there are other ideas close to your home.”

**A ne pas confonde avec l'Ergonomie (Usability).**

## Accessibilité

### Vision :
![[Pasted image 20230214142945.png | center]]

### Audition :
- Sourd
- Malentendant
- Environnement bruyant
- Environnement silencieux (bibliothèque)

### Handicaps physique :
- Handicaps moteurs
- Pas de souris
- Un clavier adapté
- Trouble de la parole

### Handicaps cognitif et neurologique :
- Dislexie
- ADHD
- ...

### Technologie :
- Navigateur trop vieux ou trop récent
- Autre OS
- faible bande passante
- ...

**Mais toutes les solutions prises pour ses handicaps nous servent (ex : porte automatiques)**

**On a pas besoin d'être un soldat pour être handicapé, tenir un sac de course nous bloque une main par exemple.**

---
# Personnas

Puisque chaque individu est différent et qu'il est compliqué de satisfaire tout le monde lors de développement d'une IHM, on va se concentrer sur des groups d'utilisateurs (users groups).

On devrait directement prévenir le designer lorsque l'on fait ce genre de choix et les besoins que cela va impliquer.

On peut se reporter à la démographie pour savoir sur qui ce concentrer.

## Groupe d'utilisateurs

Le premier prérequis pour faire une IHM est de savoir à qui elle sera destinée.
Un groupe d'utilisateur va décrire les caractéristiques des utilisateurs ciblés.
Pour cela il nous faut certaines informations :
![[Pasted image 20230214144353.png | center]]
			- Potentielles variations physiques / handicaps
			- Potentielles variations cognitives / perception.
			- Personnalité
			- ...

Ses informations sont alors regroupés au sein d'un **Personnas**.

## Construire un Persona simple :

![[Pasted image 20230214144852.png | center]]


