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

Dans la section Exercice 3 du MakeFile on aura ceci :
```
## Exercice 3:

STATIC_EXE=$(EXE:.exe=-staticExe.exe)


tri_%-staticExe.exe: main.o %.o timer.o utils.o unused.o

$(CC) -static -o $@ $^
```

