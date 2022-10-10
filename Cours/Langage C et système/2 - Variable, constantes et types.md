



## Identificateurs
Ils permettent de construire des noms de variables, de constantes ou de types.

### Syntaxe
- Séquence de lettre ou de chiffre (avec une lettre comme premier caractère)
- Le caractère '\_' est considéré comme une lettre
- La casse est importante (le language distingue minuscule et majuscule)

Les mots clés du language C tel que for, while, int , double, auto, register, ... ne sont pas utilisables comme nom de variable.

## Types Simples
- caractères, char
- entier court, short int ou short
- entier, int
- entier long, long int ou long
- entier long long, long long int

### Chaque type d'entier peut être signé (peut être négatif nul ou positif) ou nom:
\[unsigned | signed] char
\[unsigned | signed] \[long] int
**Par défaut ses types là sont signé.**

### Types entiers
- constantes caractères
- constantes entières
	- 10 (base décimale), **0**10 (base octale), **0x**10 (base hexadécimale)
- Nombre réels (float ou double)
- Le type void
	- Aucun objet ne peut être de ce type
	- Pointeur sans type
	- Utilisé pour dire qu'une fonction ne retourne rien (procédure)
- Type booléen \_Bool (apport C99)
	- Souvent utilisé avec le fichier <stdbool.h>
		- bool est équivalent à \_Bool
		- 0 = false
		- 1 = true
- **à compléter**

## Déclaration de variable
```C
/* déclaration simple*/
int x;
int a, b, c ;

/* rattraper le commentaire */
unsigned int v1 = 0xabcd;
unsigned long int v2, v3 = 1234UL; //seul v3 est initialisé ?
float v4 = 123.45,
      v5 = 0.0;

/* rattraper le commentaire */
const int size = 100;
const double Pi = 3.14159
```

La tailles des types simples ne sont pas définies par la norme C. Toutefois :
- sizeof (char) == 1 par définition
- sizeof (short) occupe au moins 16 bits
- sizeof (char) <= sizeof(short) <= sizeof(int) <= sizeof(long) <= sizeof(long long)

**insérer tableau tailles bits variable selon os du slide**

## Type tableau
- Une seule dimension (mais on peut faire des tableaux de tableaux)
- indice entier
- Borne inférieur à l'indice 0
- Initialiation possible avec des agrégats
- Exemple
```C
int t[10];
	=> t[0] t[1] ... t[9]
short int t[3] [10];
	=> t[0][0] t[0][1] ... t[0][9]
	   t[1][0] t[1][1] ... t[1][9]
	   t[2][0] t[2][1] ... t[2][9]
```

On peut déclarer et intialiser un tableau
```C
int t[4] = {1,2,3,4}; /* [1, 2, 3, 4]*/
int t[4] = {1,2}; /* [1, 2, 0, 0]*/
```
La dimension peut être calculé par le compilateur
```C
int t[] = {1,2,3,4}; /*dimension = 4*/
short int t[][3] = {
					{0,1,2},
					{3,4}
					{5}
				   }; // => 0 1 2
					  //    3 4 0
					  //    5 0 0
```

**Voir exemple : tableau sur slide et à rattraper**

## Chaînes de Caractères
- Principales caractéristiques
	- tableaux de caractères
	- se terminent par le caractère nul (caractère '\\0')
	- n'est pas un type C à proprement parlé
	- possibilité d'avoir des chaînes littérales avec des guillemets
- Exemples :
```C
char string1[100], string2[10];

"I'm a string"
"Another string with embedded \"quotes\""
"and another one with a \"\\\" !!!"
//Ici le '\0' est ajouté automatiquement
```

- Notes
	- Le caractère nul n'apparait pas dans une chaîne littérale (automatiquement mis pas le compilateur)
	- Pas d'opérateur prédéfini sur les chaînes (concaténation, sous-chaîne,...)
	- Nombreuse fonctions dans la bibliothèque standard
	- **Un WARNING à rattraper**
	- Un exemple à rattrapper aussi

```C
int strlen(char s[]){
	int i = 0;
	while (s[i] != '\0') i += 1;
	return i
}

void strcat(char s1[], char s2[]) /*le strcat standard n'est pas void*/ **exemple à rattraper**
```

### Types énumérés
- Ils permettent de nommer des constantes
```C
enum traffic_lights {gree, orange, red} light1, light2;
enum traffic_lights light3, light4 = green;
**manque une ligne à l'exemple ainsi que l'exemple suivant**
```
- Les valeurs par défaut peuvent être définis par l'utilisateur
```C
enum start_address {mono = 0xb000, color = 0xb800};
enum escapes {bell = '\a', backspace = '\b', tab = '\t',
			  newline = '\n', vtab ='\v', return = '\r'}
```

- Pas de contrôle sur les valeurs utilisées
```C
light1 = 20; /* 20 est correct */
```

**à compléter**

## Structures
Une structure C:
	- objet composite constitué d'éléments qui peuvent être de types différents
	- peut être manipulée comme un tout
```C
struct {/* structure anonyme*/
	short int day, month;
	int year;
} date1, date2;
```
**Parties sur les structures à rattraper/compléter**

## Unions
Semblables aux structures où un seul champ n'est valide à un instant donné
Utile pour :
	- Partager de la mémoire entre des objets qui sont accéder exclusivement
	- interpréter la représentation interne d'un objet come s'il était d'un autre type

```C
struct {
	int a;
	char b;
	double c;
}
```

**Insérer schéma place perdu slide union 1/3**

```C
union {
	int a;
	char b;
	double c;
}
```
**Insérer schéma place utilisé union slide union 2/3**

Mais on ne peut que stocker/utiliser qu'**un** seul élément à la fois, et la taille utilisé pour stocker l'objet est celle du champ le plus volumineux en mémoire parmi les champs de l'union.

**ajouter et comprendre exemple slide Union 3/3**

## Champs de Bits
- Les champs de bits peuvent être utilisés pour des accès bas niveau.
- C'est utile :
	- quand la mémoire est contrainte
	- pour l'accès aux périphériques au niveau le plus bas
**exemple à rattraper**
```C

```

## Complexe
Apport de C99
On peut avoir des \_Complex float ou des \_Complex double
**à compléter...**

## Définition de types (typedef)
Possibilité de donner un nom à un type
	- Permet de simplifier l'écriture
	- utilisation du mot clé typedef
	- similitude avec une déclaration de variable
```C
typedef int Integer; /* N'a aucun intérêt*/
typedef int Table[100]; /* Table est un tableau de 100 entiers*/
typedef struct {
	int x;
	int y;
} Position; /* Position est un type qui contient deux entier x et y*/

Position a = {1.2,0.0};
```
**Compléter l'exemple**