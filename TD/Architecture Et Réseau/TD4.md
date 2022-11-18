# Routage
---
1. Le package est bien installé sur ma machine.
2. Le fichier testroutage.imn est bien déployé.
3. J'ai bien attribué les ip à toutes mes interfaces et j'ai fais des script en .sh pour les réattribuer en cas de fermeture de core, les script ressemble à ça pour c1 :
```bash
#!/bin/bash

ip a add 190.0.1.2/24 dev eth0

```
ip a add 203.1.113.130/26 dev eth0
ip a add 203.1.113.66/26 dev eth2
ip a add 203.0.113.193/26 dev eth1



La liste des ip que j'ai attribué est :
- c1 : 190.0.1.2/24 vers eth0
- c2 : 190.0.2.2/24 ves eth0
- R1 : 203.1.113.1/26 vers eth0, 203.1.113.65/26 vers eth1 et 190.0.1.1/24 vers eth2.
- R2 : 203.1.113.2/26 vers eth0, 203.1.113.129/26 vers eth1 et 190.0.2.1/24  vers eth2.
- R3 : 203.1.113.130/26 vers eth0, 203.1.113.66/26 vers eth2 et  203.0.113.193/26 vers eth1.
- R4 : 203.1.113.1/26 vers eth0, 203.1.113.65/26 vers eth1.
- svr1 :
- svr2 :