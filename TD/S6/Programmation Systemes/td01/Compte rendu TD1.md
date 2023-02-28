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
![[Pasted image 20230214094138.png | center]]

On veux donc voir les bibliothèque qu'utilise le programme tri_bubble-basicExe.exe, on va donc vérifier cela avec ldd dans le terminal  :
![[Pasted image 20230214094313.png | center]]

On a donc 3 librairies qui sont utilisées :
- linux-vdso.so.1
- libc.so.6
- ld-linux-x86-64.so.2

# Exercice 3 :
---

Dans la section Exercice 3 du MakeFile on ajoutera juste l'argument 
-static à la liste des arguments à la compilation pour le tri_%-staticExe.exe. On aura donc cette section dans le Makefile :
![[Pasted image 20230214101722.png | center]]

On va donc exécuter la commande make test pour vérifier si la sortie des deux programmes est identique ou non, voici la sortie obtenue :
![[Pasted image 20230214095653.png | center]]

On veut maintenant vérifier si le fichier généré dépend d'une bibliothèque qu'il utilise ou non, pour cela on va utiliser la commande ldd, cela nous donne le résultat suivant :
![[Pasted image 20230214095512.png | center]]

A l'aide de la commande ls -l on va vérifier la taille des deux fichiers, on obtient cette sortie :
![[Pasted image 20230214095944.png | center]]
On constate que la version static est beaucoup plus volumineuse puisqu'elle embarque elle même les librairies qu'elle utilise.

# Exercice 4 :
---

On va donc compléter le makeFile de sorte à ajouter les directives requises afin de compiler en utilisant une librairies faites avec nos .o, on va donc le faire comme ceci :
![[Pasted image 20230214101745.png | center]]

En faisant un make all on a donc ces lignes là en plus : 
![[Pasted image 20230214101813.png]]

Vérifions que la sortie généré par ce nouveau code correspond bien à ce que l'on a avec les deux précédents à l'aide de make test :
![[Pasted image 20230214101924.png | center]]

On ne constate aucun changements sur les résultats des tris.

On va donc maintenant comparer leurs tailles à l'aide de ls -l :
![[Pasted image 20230214102017.png | center]]

On constate un léger gain de taille par rapport à la version basicExe.
On va exécuter la commande size sur la version basicExe et la version staticLib pour vérifier d'où viens ce gain :
![[Pasted image 20230214102443.png | center]]

Une partie du gain se fait dans la catégorie text et on a pas de changements pour le data et le bss.

Vérifions la présence des méthodes de unused.c dans la version basicExe :
![[Pasted image 20230214103026.png | center]]
On constate la présence de foo et de bar.

Maintenant faisons la même chose pour la version staticLib.exe :
![[Pasted image 20230214103113.png | center]]
On constate cette fois ci que foo et bar ne sont pas inclus. C'est expliqué par le fait que lorsque l'on utilise un .a on ne va copier dans l'exécutable que les .o dont notre programme ce sert.

# Exercice 5 :
---

On va modifier le makefile afin de pouvoir faire la compilation dynamique.
Pour cela, dans les CFLAGS on va ajouter -fpic afin de pouvoir générer un .so après.
![[Pasted image 20230214111941.png | center]]
Après cela on va ajouter la création du .so comme ceci :
![[Pasted image 20230214112020.png | center]]
On a donc deux lignes en plus lors du make :
![[Pasted image 20230214112200.png | center]]
On va ensuite tester la sortie des codes avec make test :
![[Pasted image 20230214112249.png | center]]
On constate que les sorties sont identiques.

Comparons les tailles avec ls -l :
![[Pasted image 20230214112401.png | center]]
On constate que la version dynamicLib.exe à quasiment la même taille que la version staticLib.exe.

# Exercice 6 :
---
Pour ne pas avoir de problème pour cet exercice dans le terminal on exécute la commande qui aura pour effet d'ajouter le dossier courant au library path :
![[Pasted image 20230214113333.png | center]]

Afin de faire la compilation pour tous les tris simultanément on décommente le contenu de cette ligne.
![[Pasted image 20230214112836.png | center]]
x
Le make nous produit alors les .exe pour chaque tri.
On va donc les tester avec make test :
![[Pasted image 20230214113048.png | center]]
![[Pasted image 20230214113128.png | center]]
Comme on peut le voir le tri fonctionne à chaque fois.

# Exercice 7 :
---

On commence d'abord par remettre 