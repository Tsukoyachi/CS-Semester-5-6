# Architecture
---

## Séance 1 : Intro

Circuit logique :
- Un transistor possède trois pattes, la source, le drain, et une entrée.

![[Pasted image 20221202084309.png | center]]
Le principe est simple, le courant d'entrée pilote un interrupteur, qui est fermé lorsque Ve > 0,6V et ouvert sinon.

Lorsque l'interrupteur est fermé, La source est connecté à la masse et donc Vs = 0V.

On a donc un comportement inverseur via ce transistor.

- Grâce à cela, on peut faire une porte non et en mettant nos deux entrée A et B en série à la place de Ve. (On obtient donc une porte ET en remettant un transistor en série après le Vs).

![[Pasted image 20221202084708.png | center]]

- De même en les mettant en parallèle cela nous donne un non ou. (et donc en ajoutant un transistor en série avec Vs on obtient une porte ou).
![[Pasted image 20221202084758.png | center]]

**à rattraper**

### Fonctions booléennes

Lorsque que l'on possède n variables, on peut faire une table de vérité avec $2^n$ lignes.

![[Pasted image 20221202085033.png |center]]

![[Pasted image 20221202085056.png |center]]


![[Pasted image 20221202085114.png | center]]

### Vecteur de tests
![[Pasted image 20221202085147.png | center]]

#### Exemple de circuit - le décodeur 7 segments

- Il permet d'afficher l'ensemble des chiffres hexadécimaux de 0 à F



