# Ergonomie logiciel
---
### Lessons date :
- 2022-09-30 09:09

### Teachers :
- Marco Alba Winckler

### Tags :
#IHM, #Interface, #Homme, #Machine, #Harmonisation 

---

```ad-important
title: Conception de systèmes interactifs

**Concevoir et réaliser des systèmes.**
Il faut que ses systèmes soient :
- utiles (adéquation aux besoins, fournitures des bonnes fonctions)
- utilisables (adéquation aux capacités de l'utilisateur) :
	- confort, efficacité, sécurité, qualité du produit et de la tâche réalisée avec le système.
```

```ad-info
title: L'utilisabilité

Définition : **à rattraper**
```
```ad-important
title: Propriété d'une bonne IHM : **à compléter**
- Observabilité 
- Honnêteté
- Pro-Activité des retours d'information
- Conformité et stabilité du temps de réponse
```
```ad-important
title: Danger d'une mauvaise IHM :
- Rejet pur et simple par les utilisateurs
- Coût d'apprentissage (formation)
- Perte de productivité des utilisateurs
- Utilisation incomplète: manque à gagner
- Coût de maintenance
- Perte de crédibilité
```

**Exemples de mauvaise IHM :**
- libéllés non clairs ou ambigus (syntax error)
- Fonctionnalités inutiles
- Ecrans trop dense
(à compéter)

**Pré-requis :**
- Connaissance du fonctionnement humain :
	- Modèle du processeur humain :
		- trois sous-système
	- La théorie de l'action Norman
		- Comment se fait l'accomplissement d'une tâche
	- Modèle de Rasmussen
	
	- Rappels...

**Théorie de l'action de Don Norman**

![[Don Norman.png | center]]

**Terminologie des connaissances ergonomiques en IHM**

- Recommendation,
- Guidelines, règles ergonomiques (par exemple: dans une liste, organiser les éléments par ordre alphabétiques)
- Critère ergonomique, facteur d'utilisabilité
- Check-list, heuristiques d'utilisabilité
- Standart (ISO,...)
- **à compléter....**

**Les critères ergonomiques**

1 - Guidage
	- Incitation
	- Groupement/distinction entre items
	- Feed-back immédiat
	- Lisibilité

2 - Charge de Travail
	- Briéveté/Concision
	- Densité informationnelle

3 - Contrôle explicite
	- Actions explicite (Il faut que ce soit simple de voir quand on peut ou non réaliser une tâche, par exemple : un bouton peut être grisé)
	- Contrôle utilisateur (Pour faire une bonne IHM, l'utilisateur doit toujours avoir une issue de secours dans la limite physique des opérations (En informatique on peut toujours annuler une tâche en cours, mais quand elle a un impact sur le monde réel par exemple une impression en cours elle n'est pas annulable , pouvoir annuler une tâche en cours à n'importe quel moment)

4 - Adaptabilité
	- Flexibilité (Donner la possibilité d'avoir plusieurs moyen de réaliser une tâche)
	- Prise en compte de l'expérience utilisateur

5 - Gestion des erreurs (L'erreur est humaine, les utilisateurs sont sujets à plusieurs source d'erreur tel que le stress, il est donc possible de créer plusieurs barrière pour empêcher cela, par exemple un message de confirmation, mettre un fichier à la corbeille n'est pas un effacement définitif)

6 - Signification des codes et dénominations (Il faut que les codes fassent sens à l'utilisateur, les notations doivent être compréhensible pour le type d'utilisateur qui utilisera l'appli, par exemple mettre des formules chimiques compact dans une application destinée à des chimiste est acceptable, par contre si c'était d'autres personnes qui utiliseraient l'appli ça ne serait plus acceptable)

7 - Homogénéité/Cohérence

8 - Compatibilité

**Guidage**
Incitation
Trouver des exemples en image de Guidage et d'incitation
- par exemple, des flèches sur une carte pour la déplacer
- Mettre des formats de saisie dans les formulaires, par exemple chiffres only, nb de caractères limités, indiquer ses formats pendant le remplissage au lieu d'attendre la validation pour lui dire, ....
- mettre un bouton close (pour fermer le fichier) à côté d'un bouton exit (pour fermer l'appli) est un mauvais guidage
- Mettre des boutons OK et Annuler en dehors d'une fenêtre de setting pour ne pas créer d'ambiguité
- Pour un mot de passe au lieu de juste le cacher, remplacer les caractères par des * pour que l'utilisateur puisse tracker combien de caractères il a tapé.
- Lorsque l'on tape sur un clavier tel, les lettres sont affiché même si le doigt cache le clavier.

Temps de réponse acceptable
- 0.1 sec : L'utilisateur voit l'information comme un flou continu.
- entre 0.1 et 1 sec : L'utilisateur perçoit l'intéraction comme une pause dans une conversation, il faut une réponse visible du système.
- entre 1 et 10 sec : Temps d'attente max, il faut signaler que le système est en train de faire quelque chose et l'utilisateur doit attendre.
- > 10 sec : Un plus du signalement, il faut autoriser l'utilisateur à faire autre chose en attendant.

Lisibilité
- Les majuscules sont moins lisible, on préférera Cancel à CANCEL.
- Les écritures souligné sont moins faciles à lire également.

**Charge de travail**
Concision
- On préviligiera de l'auto-complétion à une syntaxe trop compliqué
Densité Informationnelle
- Eviter d'avoir trop d'information au même moment sans catégorisation (dans une navbar créer des sous menu par exemple : file avec open, open new,...)

**Contrôle Explicite**
Action Minimales :
- Mettre des valeurs par défaut dans un menu lorsqu'il n'y a pas d'enjeu de sécurité, par exemple pour régler une police on met une taille et un type de police par défaut.
- Toujours mettre un bouton pour valider ou refuser au lieu de bloquer l'utilisateur dans un choix qu'il ne veut pas.

**Adaptabilité**
Flexibilité
- à rattraper
Prise en compte de l'expérience de l'utilisateur
- Créer des raccourci clavier pour les utilisateurs experimentés.

**Gestion des erreurs**
- Missclick (erreur d'exécution) et Mistake (erreur d'intention)
- Faire des système d'annulation (el famoso Ctrl+Z) et redo (Ctrl + Y en général)
- Qualité des messages :
	- Message Technique (pour dev mais pas pour utilisateur)
	- Message User-Friendly
	- Certains messages peuvent être "Désagréable", avec de l'humour déplacé ou autre.
