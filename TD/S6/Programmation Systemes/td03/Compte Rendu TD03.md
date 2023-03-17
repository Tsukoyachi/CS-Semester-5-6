
## Ex 1 :
---

Après le code suivant de multiple fork on obtient bien les 100 lignes correspondant au 10 print de chacun des 10 fork.

## Ex 2 :
---

La commande ps aux renvoie les informations des processus relatif à un programme, on voit dans la liste les 10 processus fils du programme père. Les pids des processus fils se suivent tous car ils sont lancé quasiment tous en même temps.

## Ex 3 :
---

Pour créer un zombie il suffit que le processus fils finisse avant le processus père, pour cela il suffit juste de ne pas mettre de wait pour le père et de retarder son exécution avec par exemple un sleep.

Avec ps aux le fils a alors un statut Z.

## Ex 4 :
---

Dans le cas où c'est le père qui se fini avant le fils, on parle de processus orphelin car le processus père est tué avant. Pour le provoquer il suffit juste de mettre un sleep dan sle case 0 (du fils) et de ne pas mettre de wait pour le père.

Avec ps aux, on voit que le pid du processus père du fils à changer, en l'occurence chez moi il est passé à 1.

## Ex 5 :
---

Après quelques test effectivement :
- Un flush dans le processus père est dans le processus fils donnera le même résultat car le buffer est partagé.
- Dans le cas du exec on exécute un nouveau code donc on perd l'ancien buffer et on n'exécute pas le code qui le suit.

## Ex 6 :
---

Pour cet exercice on effectue à la suite 2 switch fork avec un execlp pour le fils et un wait pour le père.

## Ex 7 :
---

Pour cet exercice on reprends le code de l'exercice précédent, sauf que pour le cd c'est une commande built in du shell, a priori elle ne possède pas de fichier correspondant dans /bin.

A la place, pour le cd on utilise chdir() qui prends en paramètre la destination, on peut donc soit l'appeler avec un string contenu le chemin relatif ou absolu, soit lui passer l'environnement ~ avec getenv("HOME") ce qui nous donnerai pour cd : chdir(getenv("HOME")).

## Ex 8 :
---

Dans cet exercice, le travail est plus complexe :
- scanf ne lis pas ce qui suit un espace donc à la place on utilise fgets ou gets.
- fgets (qui a été mon choix pour cet exo) nécessite une taille de buffer on utilise un define avec un ifndef pour lui mettre par défaut une taille de 2048 (modifiable à l'exécution avec -t).
- fgets mets par défaut le \\n en fin de ligne, pour remédier à celà, j'utilise strchr pour remplacer le \\n par un \\0.
- Pour l'exécution d'une commande j'ai fait une méthode qui va d'abord dupliquer la ligne de commande pour vérifier s'il s'agit de cd (seule commande built in que je prends en charge) et vérifier si elle est appelée avec un paramètre. Sinon un appel à système est effectué pour exécuter la ligne de commande complète.
- On met alors le tout dans une boucle d'exécution dans un main qui affichera un prompt avec "$ " que l'on flush à divers endroit pour que l'utilisateur sache quand est-ce qu'il peut écrire.
- Enfin on peut sortir de mon programme en validant une ligne vide.

## Ex 9 : 
---

Pour cet exercice la seule modification à faire sur le code de l'exo précédent est de remplacer l'appel à system par un switch afin de fork pour que le processus fils exécute ceci :
```c
execl("/bin/sh", "sh", "-c", command, (char *) NULL);
```
Le processus père quant à lui effectuera un wait pour que la boucle d'exécution ne reprenne pas avant que la commande n'est fini de s'exécuter.