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

### Table routage
- Explication structure/fonctionnement table de routage dans le cas d'un partage de connexion d'un téléphone. Dans cette situation le téléphone à la fonction de modem (modulation/démodulation) et de router donc il possède une table de routage.![[Schéma table de routage.png]]
- Dans le cas d'un serveur web hébergé localement, pour transférer la requête de notre router à notre serveur web l'on se sert d'un NAT (network adress translation), qui va dire ok j'ai reçu une requête pour cette adresse, je la transmet au serveur web sans la toucher pour qu'il se débrouillera avec.