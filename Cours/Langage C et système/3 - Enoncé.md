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

**rattraper l'exemple**

### Enoncé continue
- utilisé dans les boucle pour sauter une étape
- "retourne au test"

**rattraper l'exemple**

### Enoncé return
- Sort de la fonction courante
	- permet de donner le résultat de la fonction
	- pas de valeur dans le cas d'une fonction void
```C
int min(int a,int b){
	if (a < b) return a; else return b;
}

int search(int item, int t[], int t_size){
	int i;
	for(i = 0; i < t_size; i++)
		if(t[i] == item) return i;
	return -1; /* si on est ici l'item est absent*/
}
```

## Expression vs Enoncé
- Une expression fournit une valeur
- Un énoncé change un état (effectue une action).
- En C, n'importe quelle expression peut être transformée en énoncé en lui ajoutant un ";"
```C
x = 1; 123 ; y = 2
/* Ici le 123 ne sert à rien donc le compilateur l'oublie volontairement*/


```
