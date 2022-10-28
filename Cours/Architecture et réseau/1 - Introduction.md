# Introduction
---
### Lessons date :
- 07/10/22

### Teachers :
- M Dino Lopez

### Tags :
#Architecture #Réseaux

---
**Diapo pas à jour...**
![[slides-intro-net.pdf]]

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
- Pour la topologie Tree (arbre), topologie normalement utilisé pour les data-center. "switch d'accès ?"

### Topologie arbre
En général dans un data-center, on a une topologie en arbre à 3 niveaux.
![[Pasted image 20221007082947.png | center]]
Le problème de ce genre d'architecture c'est les failles temporaires, un câble cassé, un switch en panne,... Pour résoudre ce problème on introduit la redondance.

### Topologie data-center "K-ary fat tree"
![[Pasted image 20221007083452.png | center]]
Le réseau est séparé en PoD (Point of Delivery) avec :
- k PoD
- (k/2)² serveurs par PoD
- k/2 edge et aggregation switches par PoD
- chaque edge switch va se connecter à k/2 serveurs et k/2 aggregation switch
- chaque aggregation switch va se connecter à k/2 edge switch et k/2 core switch
- On a (k/2)² core switch, chacun connecté à k PoD.
Ceci est une configuration **idéale**, en réamité on change un peu le modèle.

### Une vrai topologie de data-center
![[Pasted image 20221007084023.png | center]]
Ici, Spine Block = core switch, Edge Aggregation Block c'est l'équivalent des deux couches précédente Edge switch et Aggregation Switch.

**à compléter car j'ai compris à moitité**

### Vue globale
Internet c'est l'interconnexion des réseaux.

![[Pasted image 20221007084947.png |center]]

### Switching
Pour permettre à deux utilisateurs (end point) de communiquer, des appareils intemédiaires seront nécessaires.
Les appareils intermédiaires vont transférer le trafic entre quelques utilisateurs.
Et les appareils intermédiaires ont besoin de switcher d'une conversation à une autre.
On a 3 types de switching :
- Circuit switching :
	- Téléphones fixe et portable
	- Réseau optique (en anneau)
- Message switching :
	- Application-layer protocols
- Packet switching
	- Internet

#### Circuit switching
Dans les circuit switching, les resources sont réservé pour toute la durée de la conversation.
	- ça prends du temps de créer un circuit (virtuel)
	- Les données utilisateurs vont à la limite des liens
	- Les périodes de silences entraîne des ressources gaspillées.
Le chemin complet du début à la fin est appelé circuit/
Un circuit peut être implémenté en utilisant :
	- Frequency Division Multiplexing (FDM)
	- Time Division Multiplexing (TDM)

##### Représentation Circuit (Virtuel)
![[Pasted image 20221007085734.png | center]]
##### FDM vs TDM
FDM :  Frequency Division Multiplexing 
TDM : Time Division Multiplexing
![[Pasted image 20221007090049.png |center]]

FDM : On a des fréquences qui sont réservées pour chaque sender, pour écouter on a juste à se mettre sur la bonne fréquence.

TDM : Des intervals de temps sont réservés pour chaque utilisateurs qui parlent chacun leurs tours.

#### Packet switching
![[Pasted image 20221007090344.png | center]]

### Internet elements
Internet est un réseau qui interconnecte des appareils
- Fournisseur de service internet
- Le réseau des réseaux
Les appareils, hôtes ou fin de systèmes :
- PC fixe ou portable, serveurs.
- Aujourd'hui : Téléphones, objets connectés
Lien de communications :
- Câble ethernet, câble RJ45, radio fréquence
- ?
Packet switches
- Routeurs, **à compléter**

### Internet application
Applications distribués :
- Client-server
- Peer to peer

Les échanges d'informations doivent suivres quelques protocoles.

Il y a différents protocoles pour différents objectives à différents niveau de la pile de différents internet.

Les protocoles les plus utilisés :
- Configuration de client réseau facile => DHCP
- Conversion de nom de domaine à IP => DNS (domain name system)
- Télécharger/uploader/modifier/supprimer des documents => HTTP, ?? ...
- Obtenir l'heure courente (trad approximative) => NTP
- ...
- Protocole de transfert de données utilisateurs entre deux application => TCP/UDP
- Management de réseau, signalement et contrôle
- ...

#### DHCP (Dynamic Host Configuration Protocol)
- Configuration automatique des fins de systèmes (des end points du réseaux)
	- Adresse IP, masque réseau, addresse router, serveur DNS, réseau de domaine,...
- DHCP fonctionne avec le protocole UDP
	- Port numéro 67 et 68
- Flexible mais avec un contrôle minimal sur les paramètre réseau
- Les utilisateurs vérifient rarement la configuration obtenue, cela pose des problèmes de sécurité.

![[Pasted image 20221014081657.png | center]]

Pour qu'un client choisisse entre un serveur 1 et un serveur 2 il fait une requête (broadcast ?) pour ensuite collecter les offres que lui envoient les serveurs ayant reçu la requête, le client fera alors un choix puis enverra une requête à chaque Serveur pour lui dire si oui ou non il a accepté son offre. Enfin le serveur qui a été accepter devra lui envoyer un **DHCP ACK** pour confirmer au client que le choix est effectif. Après cela le client pourra utiliser son adresse IP à souhait.

![[Pasted image 20221014081938.png | center]]

Mais le DHCP étant dynamique, lorsque le serveur nous fournit une adresse IP il nous fournit également un temps d'utilisation de l'adresse IP, se pose alors plusieurs cas de figure :
- Si le client est présent sur le réseau : au bout de 50% d'utilisation du temps fournit, le client fournit une requête DHCP pour renouveller le temps d'utilisation, si le serveur nous répond avec un DHCP ACK alors c'est bon, s'il nous répond avec un DHCP NACK alors il faudra recommencer la procédure.
- S'il n'est pas présent quand le temps est écoulé il faudra juste recommencer la procédure

#### DNS (Domain Name System)
- Permet de traduire un nom qui est user-friendly en une adresse IP
	- ex : google.com => XXX.XXX.XXX.XXX (flemme de chercher l'ip officielle)
- Architecture hiérarchique
- Quelques définitions :
	- Name server => DNS server software
	- Resolver => DNS client software
	- Fully Qualified Domain Name => FQDN
	- Partially Qualified Domain Name => PQDN
	- Top level domains => domains just below the root (unamed domain)
		- Generic top level domains => gTLD (.com, .edu, .gov, ...)
		- Country code top level domain => ccTLD (.fr, .br, .jp, ...)
	- subdomain => domain inside a domain
- DNS utilise TCP et UDP sur le port 53

Voici un schéma qui représente l'architecture DNS :
![[Pasted image 20221014082841.png | center]]

Pour construire un PQDN ou un FQDN on part d'en bas et on remonte en ajoutant des point entre chaque mots.

Un PQDN pourrait être : www.yahou.com car il manque le . de la racine
Un FQDN pourrait être : www.yahou.com. **avec le point à la fin**

En principe on utilise les PQDN sur notre navigateur, et à partir du PQDN le navigateur essaye de retrouver le FQDN.

#### Solution itérative et récursives
![[Pasted image 20221014083456.png | center]]

À gauche on a la solution itérative et à droite la solution récursives, les deux ayant l'architecture du schéma au milieu.

Pour la solution itérative, si l'on veut accéder à www.example.com, si le serveur DNS n'a pas l'information en cache concernant www il va la demander à example, mais s'il il n'a pas non plus l'information concernant example il va la demander à com et s'il n'a pas l'information en cache concernant com il va la demander à root.

Pour la solution récursive, le serveur DNS, demande à un serveur local qui va lui même contacter le serveur root qui va contacter le serveur top level DNS puis qui contactera le serveur DNS authoritative.

#### Authoritative vs Non-Authoritative answers
Une réponse avec autorité sur le serveur sera une réponse qui a plus de chance d'être correcte, elle est plus fiable, on l'obtient en demandant directement au serveur DNS qui contient les informations sur la page de destinations.

Une réponse sans autorité sur le serveur sera quant a elle obtenue via les données en cache du serveur DNS, elle est moins fiable, on ne l'utilisera par exemple pas pour des données sensible je pense.

#### Types d'enregistrements DNS
En DNS on a plusieurs types de données :
- type A : adresse IPV4
- type AAAA : adresse IPV6
- type MX (Mail eXchange) : adresse SMTP
- type NS : server name d'un domaine

Exemple je vais demander le type A par rapport avec google.com le serveur DNS sait que je veux l'adresse IPv4 de google.com.

Si je demandais le type MX d'un DNS le serveur DNS sait que je veux l'adresse SMTP lié au DNS en question.

## Network, Layers and Protocols
### Packetization
**à rattraper**

###  The Layering approach
![[Pasted image 20221014085758.png | center]]


Pour le protocole Application on a mit HTTP mais on aurait pu également mettre DHCP et DNS.

Pour le protocole Physical on aurait pu également mettre Wifi et 4G.

#### Encapsulation

![[Pasted image 20221021080601.png |center | 600]]
Lorsque l'on envoie un message il passe par la couche application puis il passe par la couche transport, la couche Réseau, la couche Link, et la couche Physique (pas noté sur l'image mais c'est le cas) qui ajoute chacun une entête puis il est envoyé à un switch.

Le switch (**dispositif de niveau 2** car dans ce type d'équipement on déploie le protocole de la couche physique pour décripter les données de la couche physique, puis on déploie le protocole de la couche liaison des données) renvoie le message au router.

Le router (**dispsitif de niveau 3** car en plus de ce que fait le switch, le router déploie également le protocole de la couche réseau, lors du passage par la couche réseau une entête est supprimée avant de la récupérer lors du second passage par la couche liaison des données) qui choisira d'envoyer le message au sein de son réseau ou vers l'extérieur.

Enfin le message arrive à destination et refait le trajet inverse de la première étape, il passe successivement par la couche physique, la couche liaison des données, la couche réseau, la couche transport en perdant à chaque étape une entête pour enfin arriver à la couche application.

Dans la vraie vie, le router peut également faire le travail du switch ce qui simplifie le trajet des données tout en effectuant les mêmes étapes.

##### Exemple d'utilisation avec le cas des requête HTTP

![[Pasted image 20221021081629.png | center]]

##### L'encapsulation dans la vraie vie

![[Pasted image 20221021081722.png | center]]

Sur cette image on voit la liste des paquets capturé lors d'une requête HTTP, et si l'on sélectionne la ligne "Internet Protocol Version 4..." on sélectionnera en bas les octets surlignés en bas pour déchiffrer l'entête de la requête.

#### Le multiplexage

On peut faire l'analogie entre les ports d'un serveur et un vraie port avec plusieurs entrée où chacune d'entre elle est dédiée à un type de cargaison (de donnée/requête)

![[Pasted image 20221021082137.png | center]]

```ad-note
title: Quelques types de requête avec les ports associé

- Protocole HTTP : port 80
- Protocole HTTPS : port 443
- DNS : port 53 (je crois)
```

![[Pasted image 20221021082414.png | center]]
Pour une connexion à un site internet on va utiliser le protocole TCP et la radio va utiliser le protocole UDP, si les données viennent du même serveur rien ne les empêche d'arriver sur le même port mais ce qui permettra alors de les distinguer sera le protocole liée à chaque paquet, ici TCP et UDP.


### Les délais dans les réseaux

#### Packet forwarding in packet-switched networks

- En général on envoie les paquets x par x même si certain protocole pourrait en envoyer plusieurs à la fois, il faut donc stocket les paquets pour les envoyer x par x.
- Un appareil recevra les paquets et les enregistrera dans un buffer.
- Une fois que ls packets complet est reçu, le paquet est traîté et puis redirigé.

Le nombre de paquets envoyé à la fois (x) est défini par la bande passante.

![[Pasted image 20221021083109.png | center | 600]]

(ici l'image parle d'elle même je vais juste faire une traduction)

Le délais total de l'envoie d'un paquets à un noeud est consitué de :
- Un délai de traitement : Est ce qu'un paquet doit être envoyé ? Si oui, par quel port ?
- Un délai d'attente : On est limité par la bande passante donc on doit fait patienter les paquets avant envoi
- Un délai de transmission : On découpe le paquets en plein de morceau pour l'envoi et on envoie les morceau x par x mais cela nécessite du temps.

On a ensuite le délai de propagation : la vitesse à laquelle les bits s'envoyent à travers un lien.

#### End-to-end delay

- Un paquet passera par **N lien et N-1 appareil de redirection** (switch, router,...) lors de son envoi.
- Un paquet composé de **L bits**, transmis à une vitesse de **R bits/sec** aura besoin de **L/R secondes** pour être transmis => **délai de transmission**.
	- Le calcul précédent est pour l'envoi d'un noeud à un autre, si un paquet passe par N lien (donc N-1 appareil de redirection) aura besoin de **NL/R** secondes
- Mais les réseaux ne sont pas symétrique (**à rattrapper**).

#### Délai d'attente (Queuing delay)

- En reprenant les notation de la partie "End-to-end delay", l'intensité du traffic est défini aves le ratio **aL/R**, où a est le ratio moyen d'arrivée de paquets par seconde (pkts/s)
- Le nombre de paquets stockés dans le buffer grandira si le ratio d'arrivée dépasse la capacité de la liaison de sortie.
	- **aL/R > 1**
**reste du diapo à rattraper**
![[Pasted image 20221021084456.png |center]]

#### Pourquoi la latence c'est importent
**rattrapper les quelques slide sur ça**

#### End-to-End throughput (client performance)

![[Pasted image 20221021084805.png |center]]

La vitesse moyenne d'envoi d'un paquets est limité par la vitesse minimum d'envoi des paquets au sein du réseau, peu importe si l'un des lien envoie 12 Gigabits/sec, si l'un des liens est limité à 100 Megabits/sec le réseau sera limité à 100 Megabits/sec.

Donc de nos jours on fait des réseaux surdimensionnés afin de pouvoir endurer le traffic réseau de tous les clients.

### Adressage IPv4

#### Récap' définition adresse Ipv4

![[Pasted image 20221021084903.png | center]]

#### Cibler un appareil sur le réseau

- Pour identifier un routeur ou un hôte d'arrivée, pour lui envoyer un paquet particulier, on aura besoin d'une adresse.
- Les adresses IP identifient les sous-réseaux et indiquent l'ID de l'hôte d'un appareil sur le réseau.
	- Cela permet de savoir si l'appareil est situé sur mon réseau local ou ailleurs.
	- Ou encore de savoir quel trajet faire prendre au paquets pour l'envoyer à un hôte précis.
- Parlons du schéma des adresses IPv4.

#### Adresses Classfull

![[Pasted image 20221021085233.png | center | 650]]
Les adresses de classes A ont leur bit significatif (le plus à gauche) à 0.
(Essayer de comprendre en quoi cela force le masque réseau à valoir 255.0.0.0).

Pour les adresses de classe B le bit le plus significatif va valoir 1 et le second bit le plus significatif va valoir 0.
Cela force le masque réseau à valloir 255.255.0.0 (voir pourquoi).

Pour les addresses de classe C les 3 bits les plus significatifs vont valloir 110. Cela force le masque réseau à valoir 255.255.255.0

Pour les adresses de Classe D les 4 bits les plus significatifs vont valloir 1110. Et ses addresses n'ont pas de masque réseau.

Pour les adresses de Classe E les 4 bits les plus significatifs vont valloir 1111.Et ses addresses n'ont pas de masque réseau.

La première adresse (adresse zéro) est l'adresse réseau, elle n'est pas attribuable.
La dernière adresse (adresse tout à un) est l'adresse boradcast, elle n'est pas attribuable non plus.

Etant donné qu'on a deux adresse non attribuable, sur un réseau avec n bit utilisé pour l'adresse d'hôte on a $2^n-2$ hôtes possible sur le réseau en question.

#### Adresse Classless

- CIDR (classless inter-domain rooting) est l'adresse actuel utilisé sur internet.
- La nombre de bits utilisés sur l'adresse réseau ne dépend plus des premiers bits de l'adresse IP.
- 