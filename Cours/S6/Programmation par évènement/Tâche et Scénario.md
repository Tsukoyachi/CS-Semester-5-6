# Tâche et Scénario
---
### Lessons date :
- 28-02-2023

### Teachers :
- Marco Winckler

### Tags :
#IHM #Tâche #Scénario

---

# Gouffre de l'Intéraction

Concept de **D. Norman**, il est composé de deux parties :
- **Gouffre d'Execution**
- **Gouffre d'Evaluation**

```ad-info
title: Gouffre d'exécution

Il représente l'effort requis pour un utiliseur afin d'exprimer une intention en terme de commandes ou d'instructions.

```

```ad-info
title: Gouffre d'évaluation

Il réfère à la façon dont les résultats sont donné par le système et s'ils ont du sens / sont compréhensible pour les utilisateurs et qu'ils soient lien avec leurs objectifs.

```

![[Gouffre Intéraction.png | center]]

# Analyse de Tâche

Une **tâche** c'est l'ensemble des actions qu'un utilisateur doit réaliser pour exécuter une action, on en dénote plusieurs types :
- Les tâches basiques sont celles que l'on ne découpe plus, le niveau de détail est choisit selon les cas.

Une **Analyse de tâche** quant à elle est une étude de quels personnes vont effectuer quelles tâches avec le système que l'on souhaite créer.

Le but de cette démarche étant de :
- Déterminer ce que les utilisateurs peuvent faire
- Les **outils** qu'ils vont utiliser pendant leur travail
- Les **informations nécessaire** pour accomplir la dite tâche.

Il faut couvrir un max voir tous les cas et même chose pour les utilisateurs.

Pour obtenir les informations nécessaire afin d'effectuer cette étude on doit donc passer par une phase de collecte d'informations, que ça soit en posant des questions au client, en faisant des sondages, etc....

## Un petit exemple

- To clean the house  
	- Take the vacuum cleaner  
	-  Plug it in  
	-  Use it in all the rooms  
	-  When the bag is full, empty it  
	-  Stop when finished  
	-  Store the vacuum cleaner  
- You must know  
	-  Where is the vacuum cleaner?  
	-  Where are the plugs?  
	-  How to remove the bag?  
	-  Where are the empty bags?  
	- Should I start by the entrance or by the end of the room? – strategy (related to context)  
	- Should I have vacuum cleaner at maximum speed? – strategy  
	- Evaluate if a room is clean or not – situational knowledge

## Modèle de tâche

On va définir des diagrammes permettant de détailler le déroulement d'une tâche. 

Par exemple, pour faire une tasse de thé :
![[Modèle de Tache exemple.png | center]]

Cet exemple n'est pas parfait, en effet entre 1.2 et 1.3 on ne demande pas d'allumer le gaz. Et au début on ne précise pas pour combien de personne on fait du thé.

Ce modèle de tâche permet de voir le processus du côté d'un utilisateur, il est important de ne pas mélanger cette vue et celle qu'un développeur aura pour la logique du code.

Pour cette logique on a ce que l'on appelle des **structures fonctionnelles**, c'est une vue un peu base de donnée, voici un exemple :
![[Pasted image 20230228143222.png | center]]

# Scénario

Contrairement au modèle de tâche qui va être la description d'une tâche dans un cas global (pour n'importe qui), un scénario lui va être une exécution d'un modèle de tâche dans un cas précis.

```ad-important
title: Opérateur LOTOS
Il s'agit d'un ensemble d'opérateurs à apprendre par coeur. Ils sont utiles pour décrire des scénarios je suppose.
- Enabling T1 >> T2 or T1 [ ]>> T2  
- Disabling T1 [> T2  
- Interruption T1 |> T2  
- Choice T1 [ ] T2  
- Iteration T1* or T1{n}  
- Concurrency T1 ||| T2 T1 |[]| T2  
- Ordre Independence T1 |=| T2  
- Optionality [T]
```
