



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
	- se terminent par le carac