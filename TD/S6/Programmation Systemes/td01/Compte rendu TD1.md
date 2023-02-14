# Exercice 1 :
---

Dans le code source fourni, on a un fichier sort.h qui contient la définition d'une méthode de tri qui est implémenté dans plusieurs fichiers de façon différentes :
- bubble.c : implémentation tri à bulle
- insertion.c : Implémentation tri avec insertion
- merge.c : Implémentation tri avec merge

On a également un fichier timer.h qui contient la définition de deux méthodes liée au timer dont l'implémentation est faite dans timer.c.

Enfin dans le main.c on a quelques constantes, et des méthodes avec une utilisation du sort.

# Exercice 2 :
---

A l'issue de la commande make voici la sortie obtenue :
![[Pasted image 20230214094138.png]]

On veux donc voir les bibliothèque qu'utilise le programme tri_bubble-basicExe.exe, on va donc vérifier cela avec ldd dans le terminal  :
![[Pasted image 20230214094313.png]]

On a donc 3 librairies qui sont utilisées :
- linux-vdso.so.1
- libc.so.6
- ld-linux-x86-64.so.2

## Exercice 3 :
---

Dans la section Exercice 3 du MakeFile on ajoutera juste l'argument 
-static à la liste des arguments à la compilation pour le tri_%-staticExe.exe. On aura donc cette section dans le Makefile :
![[Pasted image 20230214101722.png]]

On va donc exécuter la commande make test pour vérifier si la sortie des deux programmes est identique ou non, voici la sortie obtenue :
![[Pasted image 20230214095653.png]]

On veut maintenant vérifier si le fichier généré dépend d'une bibliothèque qu'il utilise ou non, pour cela on va utiliser la commande ldd, cela nous donne le résultat suivant :
![[Pasted image 20230214095512.png]]

A l'aide de la commande ls -l on va vérifier la taille des deux fichiers, on obtient cette sortie :
![[Pasted image 20230214095944.png]]
On constate que la version static est beaucoup plus volumineuse puisqu'elle embarque elle même les librairies qu'elle utilise.

## Exercice 4 :
---

On va donc compléter le makeFile de sorte à ajouter les directives requises afin de compiler en utilisant une librairies faites avec nos .o, on va donc le faire comme ceci :
![[Pasted image 20230214101745.png]]

En faisant un make all on a donc ces lignes là en plus : 
![[Pasted image 20230214101813.png]]

Vérifions que la sortie généré par ce nouveau code correspond bien à ce que l'on a avec les deux précédents à l'aide de make test :
![[Pasted image 20230214101924.png]]

On ne constate aucun changements sur les résultats des tris.

On va donc maintenant comparer leurs tailles à l'aide de ls -l :
![[Pasted image 20230214102017.png]]

On constate un léger gain de taille par rapport à la version basicExe.
On va exécuter la commande size sur la version basicExe et la version staticLib pour vérifier d'où viens ce gain :
![[Pasted image 20230214102443.png]]

Une partie du gain se fait dans la catégorie text et on a pas de changements pour le data et le bss.