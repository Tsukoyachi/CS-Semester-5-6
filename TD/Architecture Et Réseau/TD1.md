# Introduction aux Réseaux
---
Lesson Date : 07/10/2022
Teacher :
- M Martinet
---
**profondeur arbre** : distance maximale entre la racine et une feuille d'un arbre.

1 - On utilise une topologie en arbre de profondeur 3 (ça commence à 0), avec 7 switch pour 20 clients dans notre schéma.
![[Pasted image 20221007094248.png |center]]

2 - $(p-1)^{profondeur}\geq n \Leftrightarrow profondeur \geq log_{p-1}(n)$ 

3 - Il suffit juste d'ajouter un routeur en haut de l'arbre
![[Pasted image 20221007095542.png | center]]
4 - C'est un réseau en anneau, avec seulement 2 ou 3 routeurs c'est à la fois un anneau et un mesh et un full mesh.
![[Pasted image 20221007095955.png]]

5 - Topologie en anneau (pour les routeur) et en arbre (pour chaque site).

6 - Quand il y a trop d'envois de paquets par rapport au nombre maximal d'envoi de paquet possible par seconde.

7 - On peut connecter 6*(6/2)² = 6\*9 = 54 clients.
![[Pasted image 20221007102034.png | center]]
8 - commande ip addr show, l'interface avec le port 24 se nomme : enp0s3
![[Pasted image 20221007102501.png | center]]
![[Pasted image 20221007102710.png]]
\-i sert à préciser une interface
\-w sert à créer un fichier
![[Pasted image 20221007103016.png |center]]
Chaque ligne correspond à un paquet qui transite, avec leur point de départ et d'arrivée, le protocole de transit, leur taille, des informations et lorsque l'on en sélectionne un, des informations sur le paquet apparaissent sur le menu du milieu.

9 - La commande "tcpdump "tcp port 80" "-i enp0s3 -w /tmp/test2.1.pcap" refait la même capture que précédemment mais n'écoutera que les paquets à destination ET en provenance du port 80 en utilisant le protocole TCP.

DHCP = "tcpdump "udp and (port 67 or port 68)" ..."
DNS = "tcpdump "port 53" ..."
www.unice.fr = "tcpdump "host www.unice.fr" ..."
à destination du réseau 134.59.1.0/24 = "tcpdump "dst host 134.59.1.0/24" ..."
tout le trafic non ICMP : "tcpdimp -i enp0s3 -w not icmp /tmp/test4.1.pcap"

10 - "tcpdump "dst localhost and (port 80 or port 443)" ..."