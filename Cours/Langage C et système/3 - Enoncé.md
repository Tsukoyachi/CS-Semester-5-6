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

x = getchar(); getchar(); y = getchar();
/* Idem pour le résultat du second getchar() est oublié également*/
```
**Rattraper fin exemple**

### Affectation
- Utilise le signe"="
- est à la fois un énoncé et une expression
	- a un effet de bord (valeur de l'opérande gauche est changé)
	- a un résultat (l'opérande gauche après affectation)
	- a un type (type de l'opérande gauche)
	- peut être utilisé de façon multiple
```C
x = y = z = t[i] = 0
```
- peut être composé avec un opérateur ° (avec ° qui peut être +,-,\*,/)
```C
x °= y <=> x = x°y
```

- Opérateur préfixe et postfixe
```C
i++ <=> i += 1 <=> i = i+1
i-- <=> i -= 1 <=> i = i-1
```
Note : l'évaluation de i n'est faite qu'une fois

Exemple
```C
i = 3; j = 3;
printf("i = %d j = %d", i++,++j) /* 3 and 4 */
printf("i = %d j = %d", i,j) /* 4 and 4 */
```
**à rattraper**

## Opérateur sur les types
- Taille d'un type : sizeof
```C
sizeof(type)
sizeof(variable)
```
Exemple
```C
sizeof(x)
sizeof(**à compléter**)
sizeof(a) / sizeof(a[0]) /* donne le nombre d'élément dans a */
```

- Conversion explicite: cast
```C
(type) expr /* type = type dans lequel expr est convertie */
```
Exemple 
```C
(int) 2.0 /* force l'expression à être un int */
3 / (float) 4 /* = 0.75 alors que 3/4 = 0 */
```

## Conversion de type impilicites
- Les conversions de types ont lieux quand les opérandes sont de types différents
- Les règles sont assez complexe
- En gros, convertir vers le type le plus grand
**à rattraper**

- Dans une affectation
	- Les bits supplémentaires sont perdus quand une expression mélange char, short, int et long
	- Conversion de la partie droite de l'affectation dans le type de la partie gauche
```C
the_char = 0xabcdef; /* the_char = 0xef */
the_int = 2.3; /* the_int = 2 */
the_float = 2; /* the_float = 2.0 */
```
- Passage de paramètre :
	- Règles identiques à celles de l'affectation
- Les conversion '**value preserving**' sont toujours légales (mais la précision peut ne pas être préservée)
- Les conversions non '**value preserving**' provoquent un warning

## Opérateur de condition
- C'est un opérateur ternaire
- Comme un if-then-else mais qui a une valeur
- Syntaxe :
```C
condition ? expr1 : expr 2
```
Exemple :
```C
int min(int a, int b) {
	return (a < b) ? a : b;
}
```
 **à compléter**
### Opérateur virgule
Syntaxe :
```C
expr1, expr2
```
- Le résultat de l'évaluation de expr2
- expr1 est évalué mais sont résultat est perdu

**à rattraper...**

### Priorité des opérateurs
**\[insérer image tableau de priorité des opérateurs]**
"En C, quand on a un doute on ajoute des parenthèses." (M. Lavirotte 17/10/2022)

## Exemple: strcat
Vieille version
```C
void strcat(char s1[], char s2[]) {
	int i=0, j=0;
	while(s1[i] != '\0') i+=1;
	while(s2[j] != '\0') {
		s1[i] = s2[j]
		i+=1, j +=1;
	}
	/* Don't forget to set the final null char */
	s1[i] = '\0';
}
```
Nouvelle version
```C
void strcat(char s1[], char s2[]){
	int i=0, j=0;
	while(s1[i]) i+=1;
	while(s2[j]) s1[i++] = s2[j++];
	/* Don't forget to set the final null char */
	s[i] = '\0';
}
```
Version améliorée
```C
void strcat(char s1[], char s2[]){
 int i=0, j=0;
 while(s1[i]) i+=1;
 while(s1[i++] = s2[j++]) /* Nothing */
}
```