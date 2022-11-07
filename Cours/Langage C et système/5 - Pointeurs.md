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
struct {int x, y;} *ps; /* pointeur sur struct
```