# Architecture
---

## Séance 1 : Intro

Circuit logique :
- Un transistor possède trois pattes, la source, le drain, et une entrée.

![[Pasted image 20221202084309.png | center]]
Le principe est simple, le courant d'entrée pilote un interrupteur, qui est fermé lorsque Ve > 0,6V et ouvert sinon.

Lorsque l'interrupteur est fermé, La source est connecté à la masse et donc Vs = 0V.

On a donc un comportement inverseur via ce transistor.

- Grâce à cela, on peut faire une porte et en mettant nos deux entrée A et B en série à la place de Ve.

![[Pasted image 20221202084551.png |center]]

- De même en les mettant en parallèle cela nous donne un OU.
![[Pasted image 20221202084629.png |center]]

