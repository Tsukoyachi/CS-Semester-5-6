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
	\forall x \forall y ((\forall z,\neg ))
}$$