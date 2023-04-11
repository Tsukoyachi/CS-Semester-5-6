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

#### Liste de signaux prédéfinis sous Unix

![[Pasted image 20230411081942.png | center]]
![[Pasted image 20230411082116.png | center]]

On constate que Posix est beaucoup plus complet que ANSI au niveau des signaux.

#### Délivrance d'un signal à un processus

On peut passer des signaux à un code via des caractères spéciaux au terminal :
- ^C = INT
- ^Z = TSTP
- ^\\ = ABRT...

Ou via des fonctions spéciales du shell :
Fonctions spéciales du Shell  
- kill -signal pid  
	- Envoie le signal au processus pid  
- fg (foreground)  
	-  Reprend l’exécution au premier plan d’un processus suspendu  
-  bg (background)  
	-  Reprend l’exécution en arrière plan d’un processus suspendu  

Primitive Posix : fonction kill()  
```c
#include <sys/types.h>  
#include <signal.h>  
int kill(pid_t pid, int sig)
```

## Etat d'un signal en ANSI C

### Fonction signal()

```c
#include <signal.h>  
void (*signal(int sig, void (*ph)(int))(int);
```
 
ou, si l'on préfère  
```c
typedef void (*sighandler_t)(int);  
sighandler_t signal(int sig, sighandler_t ph);  
```
-  Positionne l'action associée à la réception du signal sig  
-  L'action associée est ph (« pointer to handler »)  
	-  SIG_IGN : signal ignoré  
	-  SIG_DFL : action par défaut  
	-  une fonction utilisateur (paramètre int, retour void) : piégé  
-  Retourne l'ancienne action associée