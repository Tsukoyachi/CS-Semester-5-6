## Exercice 1 :
---

Sans rien modifier au code "tres_simple.c" on obtient le résultat suivant :
![[Pasted image 20230314091814.png | center]]

En retirant l'appel à pthread_join() me donne aléatoirement trois résultats distincts :
![[Pasted image 20230314092916.png | center]]
![[Pasted image 20230314092957.png | center]]
![[Pasted image 20230314092935.png | center]]
Dans les trois cas ma conclusion est la même, la durée de vie d'un thread est la même que celle du programme principal.

Dans le cas où l'on ajoute un exit(0) après le printf("Hello from the thread"), on obtient ceci :
![[Pasted image 20230314093409.png | center]]
Dans ce cas-ci on constate que l'exécution du programme et de ses threads est stoppée par un exit(0) dans le thread. Pour quitter un thread sans couper le programme il faut utiliser pthread_exit().

Enfin, dans le cas où on déplace le exit(0) juste avant le pthread_join(), on obtient ceci :
![[Pasted image 20230314093712.png | center]]
Dans ce cas, le exit(0) a également coupé l'exécution du code principal et celle de son thread.

On comprends donc que exit(0) coupe tous les threads alors que pthread_exit() ne coupe que le thread courant, cela s'applique également à l'exécution du code principal.

## Exercice 2 :
---

Voici mon code pour thread.c :
![[Pasted image 20230314101427.png | center]]
Voici le résultat de son exécution :
![[Pasted image 20230314101455.png | center]]

Avant passage dans les pthread_create n1 et n2 sont des chaînes de caractères contenant des nombres, on utilise la fonction atoi afin de les reconvertir en int, cela traîte également les cas où je ne passe pas des nombres à ma fonction puisque dans ce cas 0 sera mis à la place.

## Exercice 3 :
---
Après ajout de la ligne permettant d'afficher l'Id du thread via sycall(SYS_gettid) pour les thread on obtient ceci :
![[Pasted image 20230314102111.png | center]]
On constate effectivement que l'id obtenu pour chaque thread est différent de l'identifiant du thread Posix.

## Exercice 4 :
---

En modifiant la variable NPROCESS de multiple_fork à 100000 on obtient :
![[Pasted image 20230314102619.png | center]]
Donc non, il n'est pas possible de créer autant de processus qu'on le souhaite.

## Exercice 5 :
---
Voici mon programme multiple_thread.c :
![[Pasted image 20230314110318.png | center]]
On va donc appeler ce programme et multiple_fork.c pour créer 4000 threads et 4000 processus puis on va comparer les temps :
![[Pasted image 20230314110236.png | center]]
On constate que la création des threads est plus rapide que la création des processus.

## Exercice 6 :
---
Avec htop on obtient ceci pour multiple_fork.c :
![[Pasted image 20230314112218.png | center]]
![[Pasted image 20230314111443.png | center]]

Et ceci pour multiple_thread.c :
![[Pasted image 20230314112414.png | center]]
![[Pasted image 20230314111701.png]]

Dans le cas du multiple_fork.c apparaît plusieurs fois sous htop, une ligne par processus comme sur ps aux, on voit également que le nlwp est à 1 à chaque fois, donc que chaque processus ne possède qu'un seul thread avec un PID qui est différent à chaque fois.

Dans le cas du multiple_thread.c, le programme apparait plusieurs fois sous htop mais qu'une seule fois sous ps aux, mais c'est dû à l'implémentation des threads sous linux qui sont implémenté comme les processus, d'où le fait qu'il est des pid différent à chaque fois, cependant on note le NLWP à 4001 (4000 thread + exécution principale).

## Exercice 7 :
---

Première exécution de juste_presque.c sans rien enlever (en augmentant le sleep à 7):
![[Pasted image 20230314114616.png | center]]

Maintenant supprimons le sleep() et voyons l'exécution :
![[Pasted image 20230314115345.png | center]]

Le problème ici est un accès concurrant à la variable i à chaque fois, les threads sont bien créer comme il faut, mais le paramètre passé est l'adresse de i et non sa valeur, d'une executieton du for à l'autre la valeur a cette adresse est modifiée.

Pour résoudre cela on peut faire un tableau pour stocker les valeurs de i et mettre l'adresse d'une case de ce tableau en paramètre, comme ceci :
![[Pasted image 20230319110555.png | center]]
Cela corrige le soucis sans modifier l'autre méthode.

## Exercice 8 :
---

Malgré de nombreuses exécution du jeu, je n'ai pas réussi à constater le bug où les joueurs prenaient des allumettes alors que le plateau n'en possédait plus.

En retirant l'appel à sleep par contre, on constate l'apparition du bug cité précédemment ainsi qu'une désynchronisation des valeurs du nombre d'allumette :
![[Pasted image 20230319112542.png | center]]
Après avoir remis l'appel à sleep on constate également une utilisation de 100% du CPU avec htop :
![[Pasted image 20230319112808.png | center]]

## Exercice 9 :
---
