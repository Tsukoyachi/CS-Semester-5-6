# 3 - Enoncé
---
### Lessons date :
- 03/10/22

### Teachers :
- Stéphane Lavirotte

### Tags :
#C #système

---

## Enoncé

**à rattaper**

### Enoncé composé

**à rattraper**
- Permet de regrouper plusieurs énoncé
- Permet de restreindre la visibilité d'une variable
- Permet de dénoter le corps d'une fonction

### Enoncé if
```C
if (<Expression logique>)
	<action 1>
else
	<action 2>
```
- else facultatif
- L'expression logique peut être une expression entière car 0 est faux et le reste est vrai
**à rattraper**

### Enoncé switch
```C
switch (<Expression entière>) {
	case value1: <instr_list_1>
	case value2: <inst_list_2>
	...
	case valuen: <instr_list_n>
	default : <instr_list>
}
```
Quand on passe dans un case le compilateur C continue d'appliquer tout le contenu des cases suivant jusqu'à rencontrer un break.

Le cas default est facultatif.

### Enoncé while et do

```C
while (<Expression logique>)
	<énoncé>

do
	<énoncé>
while (<Expression logique>)
```

La première boucle while est un while classique qui ne s'exécute pas si l'expression logique est fausse.

La seconde boucle do while, s'exécute au moins une fois même l'expression logique est fausse.

### Enoncé for

**à rattraper mais c'est une boucle for classique**

### Enoncé break
- Utiliser dans une boucle ou dans un switch
- sort de la boucle ou du switch
**Dans le cas d'une boucle imbriqué dans une boucle le break ne sort que de la première boucle**

** rat


