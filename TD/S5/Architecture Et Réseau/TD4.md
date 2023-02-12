# Routage
---
1. Le package est bien installé sur ma machine.
2. Le fichier testroutage.imn est bien déployé.
3. J'ai bien attribué les ip à toutes mes interfaces et j'ai fais des script en .sh pour les réattribuer en cas de fermeture de core, les script ressemble à ça pour c1 :
```bash
#!/bin/bash

ip a add 190.0.1.2/24 dev eth0

```
La liste des ip que j'ai attribué est :
- c1 : 190.0.1.2/24 vers eth0
- c2 : 190.0.2.2/24 ves eth0
- R1 : 203.1.113.1/26 vers eth0, 203.1.113.65/26 vers eth1 et 190.0.1.1/24 vers eth2.
- R2 : 203.1.113.2/26 vers eth0, 203.1.113.129/26 vers eth1 et 190.0.2.1/24  vers eth2.
- R3 : 203.1.113.130/26 vers eth0, 203.1.113.66/26 vers eth2 et  203.0.113.193/26 vers eth1.
- R4 : 203.0.113.194/26 vers eth0, 190.0.3.1/26 vers eth1.
- svr1 : 190.0.3.2/24 vers eth0.
- svr2 :190.0.3.3/24 vers eth0.

4. Pour ajouter les routes par défaut on va sur les hôtes (c1,c2,svr1,svr2) et on fait la commande : 
 ip route add default via \[ip sans le /xx de l'interface réseau de l'interface qui est connecté à notre hôte, ex : 190.0.1.1] dev  \[insérer interface de notre hôte qui ira vers le router, ex : eth0]
 ex : ip route add default via 190.0.1.1 dev eth0.

5. Oui j'ai bien le message d'erreur de l'énoncé.

6. Voici les tables de routages de chaque hôtes :
- C1 :
	- default via 190.0.1.1 dev eth0 
	 - 190.0.1.0/24 dev eth0 proto kernel scope link src 190.0.1.2 
- C2 :
	- default via 190.0.2.1 dev eth0 
	 - 190.0.2.0/24 dev eth0 proto kernel scope link src 190.0.2.2 
- SVR1 :
	- default via 190.0.3.1 dev eth0 
       - 190.0.3.0/24 dev eth0 proto kernel scope link src 190.0.3.2 
- SVR2 :
	- default via 190.0.3.1 dev eth0 
	- 190.0.3.0/24 dev eth0 proto kernel scope link src 190.0.3.3 

7. Voici les tables de routage des routeurs :
R1 : 
190.0.1.0/24 dev eth2 proto kernel scope link src 190.0.1.1 
203.1.113.0/26 dev eth0 proto kernel scope link src 203.1.113.1 
203.1.113.64/26 dev eth1 proto kernel scope link src 203.1.113.65 

R2 :
190.0.2.0/24 dev eth2 proto kernel scope link src 190.0.2.1 
203.1.113.0/26 dev eth0 proto kernel scope link src 203.1.113.2 
203.1.113.128/26 dev eth1 proto kernel scope link src 203.1.113.129 

R3 :
203.0.113.192/26 dev eth1 proto kernel scope link src 203.0.113.193 
203.1.113.64/26 dev eth2 proto kernel scope link src 203.1.113.66 
203.1.113.128/26 dev eth0 proto kernel scope link src 203.1.113.130 

R4 :
190.0.3.0/26 dev eth1 proto kernel scope link src 190.0.3.1 
203.0.113.192/26 dev eth0 proto kernel scope link src 203.0.113.194

8. Table de routage complète (nouvelles routes en gras) :
- R1 :
190.0.1.0/24 dev eth2 proto kernel scope link src 190.0.1.1 
203.1.113.0/26 dev eth0 proto kernel scope link src 203.1.113.1 
203.1.113.64/26 dev eth1 proto kernel scope link src 203.1.113.65 
**ip r add 190.0.3.0/24 via 203.1.113.66 dev eth1**
- R2 :
190.0.2.0/24 dev eth2 proto kernel scope link src 190.0.2.1 
203.1.113.0/26 dev eth0 proto kernel scope link src 203.1.113.2 
203.1.113.128/26 dev eth1 proto kernel scope link src 203.1.113.129 

- R3 :
203.0.113.192/26 dev eth1 proto kernel scope link src 203.0.113.193 
203.1.113.64/26 dev eth2 proto kernel scope link src 203.1.113.66 
203.1.113.128/26 dev eth0 proto kernel scope link src 203.1.113.130 

- R4 :
190.0.3.0/26 dev eth1 proto kernel scope link src 190.0.3.1 
203.0.113.192/26 dev eth0 proto kernel scope link src 203.0.113.194
