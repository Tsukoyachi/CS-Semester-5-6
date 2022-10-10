



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

int x;
int a, b, c ;

unsigned int v1 = 0xabcd;
unsigned long int v2, v3 = 1234UL; //seul v3 est initialisé ?
float v4 = 123.45,
      v5 = 0.0;


```
