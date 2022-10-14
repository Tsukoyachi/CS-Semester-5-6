# Introduction
---
### Lessons date :
- 07/10/22

### Teachers :
- M Dino Lopez

### Tags :
#Architecture #Réseaux

---
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

Un PQDN pourrait être : \www.yahou.com car il manque le . de la racine
Un FQDN pourrait être : \www.yahou.com**.** 