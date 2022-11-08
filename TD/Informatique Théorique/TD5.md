![[TDpreuvespredicats.pdf]]

---
# Exercice 1 :

1. $\forall x (p(x) \Rightarrow \exists x$ $q(x))$
Etape 1 : forme prénexe
$$\displaylines{
	\forall x (\neg p(x) \lor \exists x, q(x)) \\
	\forall x \exists y(\neg p(x) \lor q(y)) \\
	
}$$ Etape 2 : forme Skolem
$$\displaylines{
	\forall x (\neg p(x) \lor q(f(x)))
}$$ Où y = f(x) avec f une fonction d'arité 1.

2. $\forall x \forall y ((\exists z, p(x,z) \land p(y,z)) \Rightarrow \exists u, q(x,y,u))$
Etape 1 : forme prénexe
$$\displaylines{
	\forall x\forall y (\neg(\exists z,p(x,z)\land p(y,z)) \lor (\exists u, q(x,y,u))) \\
	\forall x \forall y (\forall z,\neg p(x,z) \lor \neg p(y,z) \lor (\exists u, q(x,y,u))) \\
	\forall x \forall y \forall z \exists u (\neg p(x,z) \lor \neg p(y,z) \lor q(x,y,u))
}$$
Etape 2 : forme Skolem
$$\displaylines{
	\forall x \forall y \forall z (\neg p(x,z) \lor \neg p(y,z) \lor q(x,y,f(x,y,z)))
}$$
Où u = f(x,y,z) avec f une fonction d'arité 3.

3. $\exists x (p(x,a) \Rightarrow \neg (\forall y, q(x,y) \lor r(x)))$
Etape 1 : forme prénexe
$$\displaylines{
	\exists x (\neg p(x,a) \lor \neg(\forall y, q(x,y) \lor r(x))) \\
	\exists x (\neg p(x,a) \lor (\exists y, \neg q(x,y) \land \neg r(x))) \\
	\exists x \exists y (\neg p(x,a) \lor (\neg q(x,y) \land \neg r(x)))
}$$
Etape 2 : forme de Skolem
$$\displaylines{
	\neg p(c,a) \lor (\neg q(c,d) \land \neg r(c))
}$$
Où x = c et y = d avec c,d deux constantes.

# Exercice 2 :

1. $A = p(f(g(a,y)),z,y), B = p(f(z),x,f(b))$
- $z$ et $g(a,y)$ sont unifiables
- $x$ et $z$ sont unifiables
- $y$ et $f(b)$ sont unifiables
On a donc : $(z|x),(f(b)|y),(g(a,y)|z)$

Donc A et B sont unifiable avec comme plus grand unificateur : 
- $(g(a,y)|z)$

2. $A = p(f(g(x,y)),g(v,w),y),B = p(f(z),x,f(b))$
- z et g(x,y) sont unifiables
- x et g(v,w) sont unifiables
- y et f(b) sont unifiables
- On a donc : $(g(x,y)|z),(g(v,w)|x),(f(b)|y)$

Donc A et B sont unifiables avec comme plus grand unificateur :
$(g(v,w)|x)$.

3. $A = p(f(x),f(y),f(z)), B = p(g(x),g(y),g(z))$
- f(x) et g(x) ne sont pas unifiables car il ne s'agit pas de la même fonction.
Donc A et B ne sont pas unifiables.
