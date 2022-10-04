# Introduction
---
### Lessons date :
- 04/10/22

### Teachers :
- M Rallo

### Tags :
#Théorique 

---
![[LogiqueDu1eOrdre_SyntaxeV4.1.pdf]]

## Logique propositionnelles :
### Syntaxe
- Les symboles utilisés pour écrire les formules propositionnelles :
	- Deux constantes Vrai et Faux (ou 0 et 1 ou top et bottom)
	- Un ensemble de symboles appelé propositions : P,Q,R,...
	- Les connecteurs logiques :
		- $\neg (non),\wedge (et),\vee (ou),\Rightarrow (implication),\Leftrightarrow (équivalent)$  
- Définition d'ensemble :
	- On part d'une base B et on va fabriquer un constructeur $\Omega$. Le but étant d'être capable de retrouver tous les éléments de l'ensemble à partir du premier élément et du constructeur.
- Objet syntaxique : formule propositionnelle :
	- Une formule propositionnelles est définies inductivement par :
		- Une base : toute **proposition** est une formule (un truc vrai ou faux).
		- Constructeur :
			- Si $\Phi$ et $\Psi$ sont des formules alors...
			- $(\Phi\wedge\Psi),(\Phi\vee\Psi),(\Phi\Rightarrow\Psi),(\Phi\Leftrightarrow\Psi),(\neg\Phi)$ sont également des formules.

## Logique du 1er ordre
### Syntaxe
- Symboles :
	- variables : x,y,z,...
	- Deux symboles pour vrai et faux
	- Un ensembles de symboles appelés **fonctions** (une fonction peut renvoyer tout sauf vrai ou faux)
		- arité (nombre d'arguments d'une fonction) quelconque : f,g,h,...
		- Les fonctions 0-aires (arité 0) sont des constantes : a,b,c,...
	- Un ensemble de symboles appelés **prédicats** (une fonction qui renvoie vrai ou faux)
		- arité quelconque : p,q,r,...
		- 0-aires sont des **propositions** : P,Q,R,...
	- Pour écrire la liste des arguments d'une fonction ou d'un prédicat, on utilise aussi **(** et **)** et **,**
	- Les connecteurs logiques :
		- $\neg (non),\wedge (et),\vee (ou),\Rightarrow (implication),\Leftrightarrow (équivalent)$  
	- Des **quantificateurs** : $\forall(universel), \exists(existentiel)$
	- Les **parenthèses** pour structurer les formules : ()
- L'objet syntaxique **terme**
	- Les termes sont des objets auquels on applique des fonctions, ils sont définis inductivement par :
		- Base : toute variable est un terme
		- Constructeurs : si t1, t2,..., tn, sont des termes et f un symbole de fonction d'arité n alors f(t1,t2,...,tn) est un terme
		- Exemples : $f(x,g(x,y))$ ou $sin(x)$ 
		- Remarque : toute constante est un terme.
		- Remarque 2 : Les termes ne comportent que des variables et des fonctions.
- L'objet syntaxique atome
	- Les formules logique du 1er ordre de base (au sens usuel et au sens des définitions inductives) sont les prédicat appliqué à des termes. **La même chose que les termes mais avec des prédicats**
	- Base : Tout atome est une formule
	- Constructeurs :
		- Si $\Phi$ et $\Psi$ sont des atomes alors...
			- $(\Phi\wedge\Psi),(\Phi\vee\Psi),(\Phi\Rightarrow\Psi),(\Phi\Leftrightarrow\Psi),(\neg\Phi)$ sont également des atomes.
- L'objet syntaxique formule logique du 1er ordre 
- Les parenthèses 
	- Dans la définition précédente, les formules sont complètement parenthésées, ce qui est très vite indigeste ...
	- On peut/va se passer partiellement du parenthésage :
		- Règle d'**associativité** du ou ($\vee$) et du et ($\neg$)
		- **Règle des priorité** (par ordre décroissant) :
			- négation et quantificateur
			- puis et
			- puis ou
			- puis implique
			- puis équivalence
	- Puis on alterne entre () et [] pour améliorer la visibilité.

## Exemples
Avec les symboles suivants :
	- fonctions : f et g d'arité 1 et a d'arité 0
	- prédicats : p,q et r d'arité 2 et Q d'arité 0
exemple de :
	- termes : a, f(a), f(g(a)), f(x), x, f(f(f(x)))
	- atomes : p(x,y), p(x,f(x)), q(a,g(f(x))), Q
	- formules : 
		- \[ p(x,a) $\vee$ p(x,f(x)) ] $\neg$ Q
		- $\exists x$ \[ p(x,f(x))  q(a,g(f(x))) ]

## Exercice 
