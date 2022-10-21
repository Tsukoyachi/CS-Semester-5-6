# TD3 Architecture et Réseau
## Axel Delille

---

1. d_prop représente le délai de propagation, donc le délai de traversée d'un bit au travers un lien de longueur l (en km) avec une vitesse v (km/sec).

d_prop = l/v

d_trans quant à lui représente le délai de transmission, donc le délai pour placer tous les paquets dans la liaison, on place un paquet de taille L (en bits) avec un débit d (bits/sec). 

d_trans = L/d

Si d_prop > d_trans alors le premier paquet n'a pas fini de franchir la liaison lorsque le dernier rentre dans la liaison.



2. L = 56 octets = 448 bits, d = 2 Mbps = 2000000 bits/s, d_prop = 10ms

d_prep = 448/64000 = 7ms

nb_paquet = 64000 bits/448 bits = 142,8 paquets.
Donc d_trans_1Paquet = L/d = 0,000224s = 0,224ms

d_total_1_Paquet = 4d_prep + d_trans_1Paquet + d_prop = 17,224 ms



3. Le délai de transmission d_trans est de L/R. 

Dans le premier cas il y a L/R secondes entre l'arrivée de chaque paquet, on a donc aucun délai dans la file d'attente car lorsque un paquet arrive, le précédent est déjà chargé dans la liaison.

Dans le second cas tous les paquets arrivent en même temps, le premier ne va pas attendre mais le dernier va attendre NL/R secondes, donc on fait la moyenne et on obtient un temps moyen dans la file d'attente de ((N-1)L)/(2R) secondes.

explication : $\frac{1}{N}*\sum_{k=0}^{n-1}\left(\frac{kL}{R}\right)= \frac{\frac{L}{R}*(N-1)N}{2}*\frac{1}{N} = \frac{L(N-1)}{2R}$



4. Les adresses Classless ne réservent plus les premiers bits d'une adresse IP, et elles réservent un préfixe routeur pour identifier un réseau particulier.



5. Une adresse publique peut être routé sur internet. Une adresse privée quant a elle ne DOIT pas l'être.



6. Ils utilisent des NATs (network adress translators) to reach the internet.



7. Il y a 20 bits utilisés pour écrire l'adresse réseau.
Il reste donc 12 bits pour l'adresse des hôtes.
Le masque réseau correspondant est 255.255.240.0 (à vérifier).

L'adresse réseau de la machine : 192.168.1.129

L'adresse réseau de broadcast : 192.168.16.255



8. 192.168.0.15 : 1100 0000.1010 1000.0000 0000.0000 1111

Pour découper ce réseau en 8 sous réseau on réserve 3 bits de plus pour adresser les 8 sous réseau et on laisse le reste pour avoir les adresse réseaux.

ex : 192.168.128.15/19 : 1100 0000.1010 1000.1000 0000.0000 1111/19

La première adresse valable serait du premier sous réseau serait : 192.168.0.1/19
La dernière serait : 192.128.31.254

On va découper l'une de nos sous réseau en deux sous réseau distinct on passera donc de :
192.168.0.15/19 à 192.168.0.15/20 le nouveau bit servant à adresser les deux nouveau sous réseau.

adresse broadcast du nouveau sous réseau : 
192.168.15.255 (1100 0000.1010 1000.0000 1111.1111 1111)

![[Pasted image 20221021111938.png |center | 700]]


