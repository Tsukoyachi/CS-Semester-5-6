## Exercice 1 :
---

A l'aide du fichier fd_simple.c on va essayer de déduire des propriétés sur les descripteurs de fichiers.

Dans la boucle lorsque l'on ouvre un seul fichier on voit qu'il porte le numéro 3. Lorsque l'on passe 2 fichiers en paramètre, le second fichier porte le numéro 4.

En décommentant le premier commentaire on se rend compte que 0 correspond au descripteur de fichier de stdin, 1 à celui de stdout, et 2 à celui de stderr.

On retire le commentaire du close dans le for et lorsque l'on ferme un fichier, son descripteur de fichier est réutilisable, par exemple ici les deux fichiers on désormais le descripteur de fichier 3.

## Exercice 2 :
---

In the main, I just call a method for all of the filepath I pass in argument to this program launch.

This method is named list, list is a method that have two usage, the first one is to call a method called print_fileinfo on the filepath in parameter if it's a file or if it's a directory, the method will be called on it and on all it's file and sub-directory.

The method print_fileinfo 