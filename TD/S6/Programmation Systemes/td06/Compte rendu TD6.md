## Exercice 1 :
---
Pour cette exercice, on ouvre juste le fichier foo avec les options pour l'écraser ou le créer et avoir le droit d'écrire.
Ensuite on redirige la sortie standard sur ce fichier.
Enfin on fait un execlp afin que la commande ls -l s'exécute, le résultat est alors écrit dans le fichier foo.

## Exercice 2 :
---
Cet exercice est à peu près équivalent, la seule différence est de faire la différence entre ouvrir en lecture et modifier le file descriptor 0 pour modifier l'entrée standard, ou ouvrir en écriture et modifier le file descriptor 1 pour modifier la sortie standard.

## Exercice 3 :
---
Dans cet exercice on teste la création d'un tube anonyme avec écriture puis lecture depuis un même processus. Tout fonctionne bien.

## Exercice 4 :
---
Dans cet exercice, contrairement au précédent on introduit un fork pour écriture depuis le père et lire depuis le fils. On se rend compte que lorsque l'on tente de lire, tant que tout le monde n'a pas fermé la pipe anonyme en écriture, un read bloquera le programme jusqu'à ce que l'on recoive quelque chose ou un EOF.

## Exercice 5 :
---
Dans cet exercice