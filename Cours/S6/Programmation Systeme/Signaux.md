# Signaux
---
### Lessons date :
- 11-04-2023

### Teachers :
- Stéphane Lavirotte

### Tags :
#Signaux

---
## Communication entre processus

- Entre père et fils :
	- Zone de données après fork (sens unique)
	- Paramètre après exec
	- Tube anonyme : pipe()
- Entre processus sans lien :
	- Tube nommé : fichier spécial FIFO
	- Via de vrai fichier (à bannir)
	- Via socket (pas abordé dans ce cours)
- Problèmes :
	- Limitations (on ne peut pas tout faire)
	- Certaines pas souhaitables (communication par fichier...)

### Les signaux

C'est un moyen simple de communication entre processus et entre le noyaux et les processus.

Les signaux sont des évènements externes qui changent le déroulement d'un processus de manière **asynchrone**, ce signal peut être bloqué par le processus et il peut avoir différentes origines (logiciel, matériel).

On distingue plusieurs types de signaux :
- L'interruption terminal (^C, ^Z, ^\)