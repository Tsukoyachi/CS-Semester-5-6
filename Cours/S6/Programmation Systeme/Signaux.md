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
- L'interruption terminal (^C, ^Z, ^\\)
- La terminaison d'un processus fils
- erreur arithmétique (division par 0)
- violation de protection mémoire

#### Etat, Action associée

L'état d'un signal (action associée) peut être :
- Ignoré (et donc perdu)
- Associé à son action par défaut, cela dépend du signal (rien, suspension, reprise, terminaison avec ou sans core...)
- Associé à une action définie par l'utilisateur (piégé, capturé, "trappé") via un "handler" de signal (fonction utilisateur)

Signal différé (masqué, bloqué), le signal est mémorisé, l'action sera effectuée lors du déblocage (démasquage)

#### Propriétés Signaux

Il n'y a aucune priorité entre les différents signaux.

L'ordre de délivrance de plusieurs signaux "simultanés" n'est pas garantie.

Les signaux sont traités lorsque le processus passe du mode noyau au mode utilisateur au moment d'un changement de contexte ou lors du retour d'un appel système.

Le traitement est donc **asynchrone**, par exemple envoyer la commande *kill -9 pid* ne signifie pas que le processus est interrompu immédiatement mais il sera interrompu dès lors que celui-ci écoute.

