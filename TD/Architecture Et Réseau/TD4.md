# Routage
---
1. Le package est bien installé sur ma machine.
2. Le fichier testroutage.imn est bien déployé.
3. J'ai bien attribué les ip à toutes mes interfaces et j'ai fais des script en .sh pour les réattribuer en cas de fermeture de core, les script ressemble à ça pour c1 :
```bash
#!/bin/bash

ip a add 190.0.1.2/24 dev eth0

```
ip a add 203.1.113.1/26 dev eth0
ip a add 203.1.113.65/26 dev eth1
ip a add 190.0.1.1/24 dev eth2


La liste des ip que j'ai attribué est :
- c1 : 190.0.1.2/24 vers eth0
- c2 : 190.0.2.2/24 ves eth0
- R1 : 203.1.113.1/26 vers eth0, 203.1.113.65/26 vers eth1 et 190.0.1.1/24 vers eth2.
- R2 :203.1.113.1/26 vers eth0, 203.1.113.65/26 vers eth1 et 190.0.1.1/24 vers eth2.
- R3 :
- R4 :
- svr1 :
- svr2 :