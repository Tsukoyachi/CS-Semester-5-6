# 4 - Preuve en calcul de prédicat
---
Prouver que $\tau$ |= $\phi$ en utilisant la méthode de résolution de Robinson

Pour cela en calcul propositionnel on passe $\tau \wedge \neg \phi$ et **à rattraper**.

Ici à la place on passe d'abord notre formule sous forme **prénexe** puis en forme de **Skolem**.

## Forme prénexe

*"On place tous les quantificateurs en début de formule"*
Mais on ne peut pas le faire n'importe comment...

On retire les implications et les équivalences en remplaçant pas des ou et des et.
On renomme les variables présentes en double.
Enfin on peut replacer les quantificateurs au début.

Voici une liste de règles pour pouvoir passer une formule en forme prénexe :
![[Pasted image 20221108150557.png | center]]

![[Pasted image 20221108150629.png | center]]

## Forme Skolem

Une fois en forme prénexe on doit passer en forme Skolem.
Le but est de retirer tous les quantificateurs $\exists$ en les remplaçant par des $\forall$. 
Pour faire cela, on remplace toutes les variables quantifiées par des $\exists$ par des fonctions. *À comprendre car ça sonne bizarre à première vue...*

![[Pasted image 20221108150921.png | center]]
On remplace le x qui est quantifié par un $\exists$ par une constante. 

Mais on ne peut pas le faire pour le $\exists z$ car à sa gauche il y a un $\forall y$ cela signifie que le z est *choisit* en fonction de y, on le remplace donc par une fonction 1-aire d'argument y (on remplace $\exists z$ par $f(y)$).

Le $\exists v$ est remplacé en suivant le même principe que pour z mais à sa gauche il y a $\forall u$ mais il y a également $\forall y$ donc on le remplacera par une fonction 2-aire d'arguments y et u (on remplace $\exists v$ par $g(y,u)$).

Mais comme le dit la remarque **une forme de skolem n'est pas forcément équivalente à la formule initiale**.

### Mais alors pourquoi peut on utiliser une forme de Skolem ?

Théorème : toute formule sous forme prénexe $ψ$ peut être remplacée par une formule skolémisée $ψ^S$ telle que : 
• $ψ$ est satisfiable si et seulement si et $ψ^S$ est satisfiable 
• $ψ$ est contradictoire si et seulement si et $ψ^S$ est contradictoire.

**Récap' de Rallo** : En gros ça fonctionne pareil...

## Rappel

![[Pasted image 20221108151938.png | center]]

On va donc passer par une **Unification**. Mais comment ça marche ?

## Unification

Pour le prochain screen, on définit :
- constantes : a, b
- variable : x,y,z,u
- fonctions : flemme de les définir mais ça se reconnaît à l'oeil alors que variable et constante c'était ambïgue ici...

![[Pasted image 20221108152450.png | center]]

En gros : On peut remplacer une **variable par une constante**, on peut remplacer **une variable par une variable**, mais on **NE PEUT PAS** remplacer la **valeur d'une constante par une variable ou par une autre constante**.

### Deux atomes sont ils unifiables ?

![[Pasted image 20221108152637.png | center ]]

### Deux termes (fonctions appliquées à des termes) sont ils unifiables ?

![[Pasted image 20221108152714.png | center]]

### Plus grand unificateur

C'est une unificateur le plus général possible, tout autre unificateur peut être obtenu en ajoutant des substitutions.

## Exemples d'unifications

### Exemple 1 

![[Pasted image 20221108152849.png | center]]

