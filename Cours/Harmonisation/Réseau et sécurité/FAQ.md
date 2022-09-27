# Network, Internet, Web and Services
---
### Lessons date :
- 27/09/22

### Teachers :
- Jean-Yves Tigli
- Yves Roudier

### Tags :
#Réseaux, #Network, #Harmonisation

---

### Adresse IPv4 et masque réseau :
- Le FAI donne une adresse de réseau, il nous laisse quelques bits de libre pour "immatriculer" nos appareils.
- 195.168.35.203/29 donc les 3 derniers bits binaire peuvent être modifiés
- Deux adresses ne peuvent pas être utilisés, l'adresse de réseau (que des 0) et de broadcast (que des 1) donc il nous reste 2^N - 2 adresses lorsque l'on nous laisse N bits libres.
- Masque : Il sert avec un opérateur booléen "et" qui va permettre de sortir les N bits du réseau en mettant les bits des machines à 0.
- Lorsque l'on envoie une info sur l'adresse de broadcast toutes les machines sur le réseau le recoivent.
- Tout les bits à 1 lorsqu'il s'agit de réseau et tous les bits à 0 quand il s'agit de host id (les bits libre pour les machines).
- Explication schématisé de masque réseau : ![[Schéma masque réseau.png |center | 750]] 
### Internet :
- topologie : Irrégulière et dynamique, il n'y a pas de topologie fixe parce qu'elle évolue dans le temps.