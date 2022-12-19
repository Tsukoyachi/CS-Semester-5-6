
### Variables en C
- Classification simple :
	- globale : déclarée en dehors de tout bloc d'instruction
	- locale : déclarée à l'intérieur d'un bloc d'instruction
- Définition :
	- Visbilité (portée) : zone dans laquelle une variable est accessible
	- Durée de vie : 
	- Emplacement :
	- Valeur initiale :
Les variables locales et globales ont des emplacement de stockage différents.

### Classes de stockage
- Elle détermine la durée de vie 


#### La classe de stockage *static*
Utilisé dans deux contextes :
- Variable globale ou fonction :
	- Durée de vie : toute la durée d'exécution du programme
	- Visibilité : limitée au fichier ou la déclaration à eu lieu
	- Intérêt : Eviter de polluer l'espace des noms
- Variable locale à un bloc :
	- Durée de vie : La valeur de la variable est persistante entre les différents appel de la fonction
	- Visibilitée : à partir de sa déclaration (déclaration (et initialisation) unique au cours du programme)
	- Intérêt :

#### La classe de stockage *extern*
Déclarer une variable sans la définir
- Durée de vie : Toute la durée du programme
- Visibilité : Globale à plusieurs fichiers
- Intérêt : Dans le cas de la compilation multi-fichiers
	- Définit une variable ou une fonction dans un fihier (.h)
	- Permet l'utilisation dans d'autres fichiers
- **à compléter**

#### Classe de stockage *register*
Indiquer au compilateur de préférer stocker la variable dans un registre du processeur
	- Durée de vie : Celle du bloc où la variable est définie
	- Visibilité : Locale au bloc
	- Intérêt : Gagner en performance par rapport au stockage de la variable dans un espace mémoire moins rapide (RAM)
		- Utile dans un contexte de logiciel embarqué
	- Limitation :
		- Le nombre de registre est limité et variable en fonction du processeur (ex : 4 registres pour le stockage sur x86)
	- Utilisation déconseillée sauf cas particulier (le compilateur optimise ce cas souvent mieux que le programmeur)
```C
register short i;
for (i = 0; i < 100; i++) {
...
}
```
#### Classe de stockage auto
Permet de définir des variables locales non-statiques dans une fonction
	- Durée de vie : Celle du bloc où la variable est définie
	- Visibilité : Locale au bloc
	- Intérêt : Aucun car comportement par défaut de C
**à compléter**

#### Synthèse :
Pour les mots clés **auto** et **register** par défaut la valeur initiale est **non définie**.
Pour les mots clés **extern** et **static** par défaut la valeur initiale est à **zéro**.

### Qualificateurs de type
C définit 3 qualificateurs influant sur une variable
- const : La valeur ne change pas
- restrict : optimisation pour la gestion des pointeurs
- volatile : variable pouvant être modifiée par une source externe au programme lui-même
Une variable (ou paramètre de fonction) peut avoir les 3 qualificateurs en même temps.

#### Qualificateur *const*
Attention : Ne déclare pas une **vraie** variable.
- Indique au compilateur que la valeur est non modifiable
- Impératif d'assigner une valeur à la déclaration
- Toute tentative ultérieur de modification entraîne une erreur du compilateur.
```C
const int i = 0;
i = 1; /* erreur */
```
Utilisation avec des pointeurs 
- Indique que la valeur pointée ne peut être modifiée
```C
void fonction (const char * ptr) {
	ptr[0] = 0; /* erreur */
	ptr++; /* ok */
}
```
Attention aux subtilités (placement du const)
- Indique que la valeur elle même du pointeur est constante
```C
char * const ptr = "Hello !";
**à rattraper**
```