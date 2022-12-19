
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
