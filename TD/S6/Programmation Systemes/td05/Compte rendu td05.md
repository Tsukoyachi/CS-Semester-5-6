## Exercice 1 :
---

A l'aide du fichier fd_simple.c on va essayer de déduire des propriétés sur les descripteurs de fichiers.

Dans la boucle lorsque l'on ouvre un seul fichier on voit qu'il porte le numéro 3. Lorsque l'on passe 2 fichiers en paramètre, le second fichier porte le numéro 4.

En décommentant le premier commentaire on se rend compte que 0 correspond au descripteur de fichier de stdin, 1 à celui de stdout, et 2 à celui de stderr.

On retire le commentaire du close dans le for et lorsque l'on ferme un fichier, son descripteur de fichier est réutilisable, par exemple ici les deux fichiers on désormais le descripteur de fichier 3.

## Exercice 2 :
---

Dans le main, j'appelle juste une méthode pour tous les chemins que je passe en argument au lancement de ce programme.

Cette méthode s'appelle list, list est une méthode qui a deux usages, le premier est d'appeler une méthode appelée print_fileinfo sur le chemin de fichier en paramètre si c'est un fichier et s'il s'agit d'un répertoire, la méthode sera appelée sur lui et sur tous ses fichiers et sous-répertoires.

La méthode print_fileinfo se contente pour l'instant d'afficher le nom du fichier.

## Exercice 3 :
---

Si l'on passe en paramètre deux nom de fichier, alors le programme va copier le contenu du premier dans le deuxième.
Pour cela on ouvre le fichier 1 avec O_RONLY pour avoir les droit d'écriture.
Et on va ouvrir le fichier 2 avec :
- O_TRUNC : pour écraser le contenu d'un fichier existant 
- O_CREAT : pour créer le fichier s'il n'existe pas
- O_WRONLY : pour avoir les droits d'écriture

Si le premier fichier est un dossier alors on va faire une copie des autres fichiers passé en paramètre dans le dossier en question, pour cela on va juste concaténer le nom du dossier avec un / et le nom du fichier pour créer un chemin vers le nouveau fichier à créer. En suite on a plus qu'a appeler la première méthode avec le fichier dont on veut copier le contenu et le chemin que l'on vient de créer, le fichier sera créer grâce à O_CREAT indiqué précédemment.

## Exercice 4 :
---

Le but de fd_herit est double :
- Expliquer que les descripteurs de fichiers sont partagés entre un processus père et ses processus fils, pour cela j'ouvre un fichier avec le père que je lis avec le fils. Cela fonctionne à merveille.
- Vérifier qu'un père et ses fils partagent les dossier ouvert avec opendir, pour cela je fait un readdir et un rewinddir avec le père pour stocker le nom du premier fichier lu, et avec le fils je fais un readdir et je compare avec le résultat obtenu par le père. Sans surprise on obtient la même chose donc un père et son fils partagent bel et bien les dossiers ouvert avec opendir.

## Exercice 5 :
---

Ici on reprend le code de lsrec et on formatte print_fileinfo pour lui ajouter les informatiosn adéquates à l'aide de la structure de données stat que l'on obtient à l'aide de la fonction stat appliquée à un nom de fichier.

Il ne reste plus qu'à les ajouter.

On peut également utiliser strftime pour formatter la date comme il se doit.