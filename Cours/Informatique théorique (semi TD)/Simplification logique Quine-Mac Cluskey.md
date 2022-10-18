
### Implantation d'une fonction booléenne
1. Table de karnauh
	1. Utile quand peu de variable (4 ou 5 max
2. Quine-Mac Cluskey
	1. Lister tous les mintermes de f dans une table
	2. Comparer les termes d'un groupe avec le groupe adjacent pour essayer de les combiner
	3. Répéter la procédure dans la nouvelle colonne jusqu'à ce qu'il n'y ai plus aucun simplification possibles
	4. Les **impliquants premiers** correspondent aux mintermes non rayés
	5. Sélectionner les **impliquants premiers essentiels**
	6. Choisir les impliquants restant formant un ensemble minimal

### Exemple Quine-Max Cluskey

![[Pasted image 20221018134608.png |center]] 
À chaque lignes où l'on a un 1 à droite on prends la conversion en décimale du nombre binaire écrit à gauche, ex : 0010 = 2.

On les regroupes dans une table, en faisant un étage par nombre de 1 en binaire à gauche pour obtenir :
![[Pasted image 20221018134715.png |center]]

**Insérer démonstration dessinée à la main**

**À l'étape 5 on mets des # à la place de la crois si c'est la seule croix de la colonne**
**Les # à l'étapes 5 sont les impliquants premiers essentiels.**