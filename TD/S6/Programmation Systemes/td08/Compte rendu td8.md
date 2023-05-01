## Question 1

La struct Data est constitué d'un tableau de 100 char et d'un int qui font respectivement 100 octet et 4 octet, donc on demande à malloc d'allouer 104 octets.

## Question 2

On appelle malloc avec 80 octets, hors on a déjà un espace libre d'une taille de 272 octets donc on va insérer ses 80 octets + 16 octets requis pour le header donc 96 octets dans cet espace libre, cela ne nécessitera aucun appel à sbrk().

## Question 3

Comme le header fait 16 octet on peut insérer au maximum 272 - 16 = 256 octets dans le trou de 272 octets.