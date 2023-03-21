## Exercice 1 :
---

A l'aide du fichier fd_simple.c on va essayer de déduire des propriétés sur les descripteurs de fichiers.

Dans la boucle lorsque l'on ouvre un seul fichier on voit qu'il porte le numéro 3. Lorsque l'on passe 2 fichiers en paramètre, le second fichier porte le numéro 4.

En décommentant le premier commentaire on se rend compte que 0 correspond au descripteur de fichier de stdin, 1 à celui de stdout, et 2 à celui de stderr.

On retire le commentaire du close dans le for et lorsque l'on ferme un fichier, son descripteur de fichier est réutilisable, par exemple ici les deux fichiers on désormais le descripteur de fichier 3.

## Exercice 2 :
---
	