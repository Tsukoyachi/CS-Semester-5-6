# Routage
---
1. Le package est bien installé sur ma machine.
2. Le fichier testroutage.imn est bien déployé.
3. J'ai bien attribué les ip à toutes mes interfaces et j'ai fais des script en .sh pour les réattribuer en cas de fermeture de core, les script ressemble à ça pour c1 :
```bash
#!/bin/bash

ip a add 190.0.1.2/24 dev eth0

```
