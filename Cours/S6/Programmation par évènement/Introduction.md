
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

![[Pasted image 20230214141431.png | center]]

## Ergonomie (Usability)

L'un des critères à prendre en compte lors de la conception d'une **bonne**
IHM.

Pour cela on a le schéma de Nielsen qui résume bien :

![[Pasted image 20230214141751.png | center]]


L'ergonomie c'est :
- Est ce que le système est simple à prendre en main
	- Que ce passe t'il si j'appuie sur ce bouton ?
	- Pourquoi je suis là ?
	- Ah oui... ça marche comme ça...
	- Gauche pour revenir en arrière et Droite pour continuer ? Ou est ce que c'est à l'envers.
- Peu importe ce que je fais le système ne doit pas planter
	- Qu'est ce qu'il se passe actuellement sur ce système
	- Pourquoi rien ne se passe ? Est ce que le système à planter ?
	- Pourquoi je ne pas pas faire ça comme ça ? Je pensais vraiment que le système le suporterait...

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