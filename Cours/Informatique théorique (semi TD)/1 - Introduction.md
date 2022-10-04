# Introduction
---
### Lessons date :
- 04/10/22

### Teachers :
- M Rallo

### Tags :
#Théorique 

---

## Logique propositionnelles :
### Syntaxe
- Les symboles utilisés pour écrire les formules propositionnelles :
	- Deux constantes Vrai et Faux (ou 0 et 1 ou top et bottom)
	- Un ensemble de symboles appelé propositions : P,Q,R,...
	- **à compléter**
- Vocabulaire :
	- On part d'une base B et on va fabriquer un constructeur $\Omega$.
	- C'est aussi l'unions pour tous les entiers i des $E_{i}$ où $E_{0}=B$ et $E_{i+1}=\Omega(E_{i})$
- Objet syntaxique : formule propositionnelle :
	- Une formule propositionnelles est définies inductivement par :
		- Une base : toute **proposition** est une formule (un truc vrai ou faux)
		- Constructeur :
			- Si $\Phi$ et $\Psi$ sont **à compléter**

## Logique du 1er ordre
### Syntaxe
- Symboles :
	- variables : x,y,z,...
	- Deux symboles pour vrai et faux
	- Un ensembles de symboles appelés **fonctions**
		- arité (nombre d'arguments d'une fonction) quelconque : f,g,h,...
		- Les fonctions 0-aires (arité 0) sont des constantes : a,b,c,...
	- Un ensemble de symboles appelés **prédicats**
		- arité quelconque : p,q,r,...
		- 0-aires sont des propositions : P,Q,R,...
	- Pour écrire la liste des arguments d'une fonction ou d'un prédicat, on utilise aussi **(** et **)** et **,**
	- Les connecteurs logiques :
		- **à compléter via le slide parce que je ne sais pas les noter en latex**, $\Rightarrow, **idem que le précédent**
	- Des quantificateurs 
- L'objet syntaxique terme
	- Les termes sont des objets auquels on applique des prédicats, ils sont définis inductivement par :
		- Base : toute variable est un terme
		- Constructeurs : si t1, t2,..., tn, sont des termes et f un symbole de fonction d'arité n alors f(t1,t2,...,tn) est un terme
- L'objet syntaxique atome
	- 