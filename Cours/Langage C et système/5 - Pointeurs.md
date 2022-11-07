# 5 - Pointeurs
---
![[05 Pointeurs.pdf]]

## Définition

C'est un élément qui contient l'adresse d'un objet C d'un type donné.

Donc un pointeur est typé, un pointeur contenant l'adresse d'un entier sera de type pointeur vers entier.

Permet de désigner une zone de mémoire alloué dynamiquement.

## Utilité

Ils permettent :
- de passer des objets par référence
- de rendre l'écriture de code plus compact
- de rendre l'écriture de code plus efficace
Mais ils rendent également le code moins lisible :-(

## Exemple
```C
int *p1, *p2; /* pointeurs sur entiers */
int *p1, p2; /* Attention: un pointeur, un int */
struct {int x, y;} *ps; /* pointeur sur structure */
void *r; /* pointeur sur void: adresse brute */
int *s[10]; /*tableau de 10 pointeurs sur int */
int (*s)[10] /* pointeur sur tableau de 10 int */
```
Un pointeur peut désigner n'importe quelle variable (statique, dynamique, constante). Il peut aussi dénoter l'adresse d'une fonction :

```C
int (*pfunc) (void); /* pointeur sur une fonction sans paramètre qui renvoie un entier */
int (*T[5]) (void) /* tableau de 5 pointeurs de ce type, PAS COMPRIS */
```

## Opérations sur les pointeurs
Deux opérations possible sur les pointeurs :
- \*p permet l'indirection (déréférence) (on accèse à l'élément dans la case mémoire associé à l'adresse p)
- &v renvoie l'adresse de la variable v (référence)

Exemple :
![[Pasted image 20221107081607.png | center ]]

Ici faire x = ... est équivalent à faire \*p = ...

### Cas particulier sur les pointeurs sur structure
```C
struct {
	int a, b;
} x, *p = &x;
```
- x est une structure
- \*p désigne cette structure
- l'accès au champ a de x : x.a
- l'accès au même champ avec p : (\*p).a

Notation spéciale :
- Pour simplifier (\*p).a
