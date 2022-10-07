# Introduction
---
### Lessons date :
- 07/10/22

### Teachers :
- M Dino Lopez

### Tags :
#Architecture #Réseaux

---
**Ce cours est divisé en deux parties**
	- 1 - Introduction Réseau et Programme Sockets
	- 2 - Architecture de programmes

La topologie des réseau dépend de la façon dont ils sont cablés, en voici quelques exemple :
![[Pasted image 20221007081330.png | center]]
- Dans la topologie Ring (anneau), on a pour n machines, n liens.
- Pour un bus **à compléter** pas ouf niveau sécurité.
- Pour la topologie Star (étoile) pour n machine et un switch, on a n liens des machines vers le switch. Un peu mieux niveau sécurité.
- Pour la topologie Mesh (maillé), "on va tirer des câbles là où c'est possible". (un peu opportuniste d'après le prof)
- Pour la topologie Full mesh (pleinement maillé) tous les dispositifs sont interconnecté avec toutes les autres machines, cela nous donne pour n machines, n(n-1) liens.
- Pour la topologie Tree (arbre), topologie normalement utilisé pour les data-center.