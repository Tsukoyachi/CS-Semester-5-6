# Introduction
---
### Lessons date :
- 17-02-2023

### Teachers :
- Florian Bridoux

### Tags :
- #Compilation 
- #Automate

---

# Pdf du cours
 *On a pas le PDF pour le moment, c'est la merde*

---

# Projet

Réaliser un compilateur

---

Les langages permettent aux Hommes de donner des instructions et d'échanger des informations entre eux avec leurs machines.
- Les langages utilisés quotidiennement entre êtres humains (français, anglais, japonais, etc...) sont dits **naturels**. Ils sont généralement ambigus et demandent toute la subtilité du cerveau humain pour être interprétés correctement.
- Les langages créés par l'homme pour communiquer avec la machine (Python, Java, C, etc...) sont dits **à compléter**

L'objectif du cours :
- Savoir formaliser des langages formels. D'abord des langages "simples" (dits **régulier**), puis des langages plus complexes.
- Au départ, un ordinateur ne comprend pas le python, le C++, etc... Pour communiquer avec l'ordinateur, il est nécessaire de transformer le code dit haut niveau en un langage machine. Cette tache est réalisée par ce que l'on appelle un **compilateur**.

## Définitions

- Alphabet : Souvent noté $\Sigma$ , ensemble fini non vite d'éléments appelés symboles (ou lettres).
Exemple :
- A = {0,1}: Alphabet binaire

- Longueur d'un mot : La longueur d'un mot u notée |u| est son nombre de symboles.
Exemple :
- u = a, |u| = 1
- v = abba, |v| = 4
- w = bbbb, |w| = 4

### Exercice :
Pout tout alphabet $\Sigma$ et pour toute longueur $l \in N$, on note $\Sigma^l$ l'ensemble des mots de longueur l sur l'alphabet $\Sigma$.

1. Pour $\Sigma = \set{a,b}$, que vaut $\Sigma³$ ?
 Ici on aurait comme combinaisons possibles : aaa aab aba baa abb bab bba bbb.
 Donc, avec notre alphabet on a : $|\Sigma³| = 8$.
 On remarque que ici on a 2\*2\*2 = 8 car on a 2 choix pour chaque lettre.
2. Soit $\Sigma$ un alphabet et l  un entier. Exprimer |$\Sigma^l$| en fonction de |$\Sigma$| et l. En se servant de la remarque précédente : |$\Sigma^l$|= $|\Sigma|*|\Sigma|*|\Sigma|*...=|\Sigma|^l$.

On notre $\Sigma*$ l'ensemble des mots sur l'alphabet $\Sigma$. On a donc :
$$\displaylines{
	\Sigma* = \cup_{l \in N}(\Sigma^l)
}$$
On note également $\Sigma+$ = $\Sigma$\{$\epsilon$} 



- Langage : **à rattraper**
- Un automate fini déterministe (AFD) : C'est un quintuplet ($\Sigma,Q,\delta,q_0,F$) où :
	- $\Sigma$ est un alphabet
	- 