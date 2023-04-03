## Exercice 1 :
---
Pour cette exercice, on ouvre juste le fichier foo avec les options pour l'écraser ou le créer et avoir le droit d'écrire.
Ensuite on redirige la sortie standard sur ce fichier.
Enfin on fait un execlp afin que la commande ls -l s'exécute, le résultat est alors écrit dans le fichier foo.

## Exercice 2 :
---
Cet exercice est à peu près équivalent, la seule différence est de faire la différence entre ouvrir en lecture et modifier le file descriptor 0 pour modifier l'entrée standard, ou ouvrir en écriture et modiflie