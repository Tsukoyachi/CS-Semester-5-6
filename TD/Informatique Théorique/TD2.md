# TD2
---
![[TD2_2021.pdf]]

### I/Vrai ou Faux
1. a. Vrai car p(a,b) est vrai, f(a) = 1 donc p(f(a),b) est faux donc la négation est vrai, et vrai ^ vrai = vrai
	
	b. Vrai car on peut prendre y = 0.

	c. Vrai on peut prendre y =3 et x = 4 par exemple

	d. Vrai car on peut prendre y successeur de x et ça fonctionne

	e. Faux car peu importe le x, x < x est faux.

	f. Faux car si on prend x=y ça fonctionne pas.

	g. Faux, car aucun entier positif est inférieur à 0, et aucun entier naturel ne possède un successeur strictement inférieur à b.

2. a. Faux, car p(a,b) est vrai mais not p(f(a),b) est faux donc vrai ^ faux = faux.

	b. Vrai car on peut prendre y = a qui nous donnerai p(a,b) qui est vrai.

	c. Vrai si on prend y = a et x = b par exemple.

	d. Vrai car quelque soit x on peut prendre y = f(x)

	e. Faux car quelque soit x, length(x) < length(x) est faux.

	f. Faux car si on prend x = y.

	g. Vrai car si on prends y = a par exemple, p(f(y),b) est vrai et faux $\vee$ vrai = vrai.

### II/Interprétation
1. $\Phi_{1}[(\exists x$ $p(x))\wedge(\exists x$ $q(x))]\Leftrightarrow [\exists x (p(x)\wedge q(x))]$
Cas où ce n'est pas universellement valide:
- Domaine : Entiers naturels
- p(x) : x est pair
- q(x) : x est impair

Cas où la formule est vraie :
- Domaine : Entiers naturels
- p(x) : x est pair
- q(x) : x est multiple de 4

2. $\Phi_{1}[(\exists x$ $p(x))\vee(\exists x$ $q(x))]\Leftrightarrow [\exists x (p(x)\vee q(x))]$
Cas où la formule est vraie :
- Domaine : Entiers naturels
- p(x) : x est pair
- q(x) : x est impair

On n'a pas de cas où ce n'est pas universellement valide.

### III/Interprétation et véracité
1. Si on prend y égal à l'élément neutre pour l'addition alors c'est vrai.
2. Si c'est vrai pour tout c alors c'est vrai pour un x particulier, c'est donc universellement vrai.
3. C'est faux sauf dans le cas où x = 0.
4. C'est universellement vrai.