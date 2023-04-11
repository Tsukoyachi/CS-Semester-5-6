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

```c
#include <signal.h>  
void on_signal(int sig) {  
	printf("*** signal %d\n", sig);  
}  
main() {  
	void (*ph)(int);  
	signal(SIGQUIT, SIG_IGN);  
	ph = signal(SIGINT, SIG_IGN);  
	printf("INT et QUIT ignorés\n");  
	sleep(5);  
	signal(SIGQUIT, on_signal);  
	signal(SIGINT, on_signal);  
	printf("INT et QUIT piégés\n");  
	sleep(5);  
	signal(SIGQUIT, SIG_DFL);  
	signal(SIGINT, ph);  
	printf("INT restauré "QUIT défaut\n");  
	sleep(5);  
}
```

```shell
$ test-signal  
INT et QUIT ignorés  
^\^CINT et QUIT piégés  
^\*** signal 3  
^\*** signal 3  
^C*** signal 2  
INT restauré QUIT défaut  
^C  
$
```

### Inconvénients des signaux en ANSI C

- On ne peut gérer que les 6 signaux définis par ANSI C
- Il est impossible de consulter l'action/état courant
- Il est impossible de bloquer/masquer d'autres handler pendant l'exécution du handler
- Pas de possibilité d'extension

## Etat d'un signal en Posix

Posix introduit de nouveaux mécanismes :
- La fonction sigaction() comme remplacement de signal()
- Blocage (masquage) de signaux (emprunté à BSD)
- Permet de positionner le masque et le handler à l'appel

**Il ne faut pas mélanger les deux appels système !!!**
Mauvaise intéraction entre les deux, recommendation d'utiliser la norme Posix et sigaction().

### Action associée en Posix

![[Pasted image 20230411083722.png | center]]

### Masque des signaux Posix

```c
#include <signal.h>  
int sigprocmask(int how,  
const sigset_t *set,  
sigset_t *old_set);
```

-  set contient l'ensemble des signaux à masquer ou  
démasquer  
-  how détermine la fonction à effectuer  
	- SIG_BLOCK : bloque les signaux de set  
	- SIG_UNBLOCK : débloque les signaux de set  
	- SIG_SETMASK : positionne le masque du processus à set  
-  old_set contient l'ancien masque  
```c
int sigpending(sigset_t *set);  
```
-  sigpending retourne les signaux bloqués en attente
-  Ensemble de signaux  
-  Ensemble de bits, 1 bit par signal  

-  Fonctions de manipulation  
```c
#include <signal.h>  
int sigemptyset(sigset_t *set);  
int sigfillset(sigset_t *set);  
int sigaddset(sigset_t *set, int sig);  
int sigdelset(sigset_t *set, int sig);  
int sigismember(const sigset_t *set, int sig);
```

### Fonction sigaction()

```c
#include <signal.h>  
int sigaction(int sig,  
const struct sigaction *actp,  
struct sigaction *old_actp);
```

-  Champs de struct sigaction  
-  void (*sa_handler)(int)  
	-  fonction de capture (identique à signal())  
-  sigset_t sa_mask  
	-  masque des signaux à bloquer lors de l'exécution du handler  
-  int sa_flags  
	-  utile seulement pour SIGCHLD

#### Exemple d'utilisation de sigaction()

```c
#include <signal.h>  
void on_signal(int sig) {  
	printf("*** signal %d\n", sig);  
	sleep(5);  
	printf("*** fin handler\n");  
}  
main() {  
	struct sigaction sigact;  
	sigset_t msk_int, msk_quit;  
	sigemptyset(&msk_int);  
	sigaddset(&msk_int, SIGINT);  
	sigemptyset(&msk_quit);  
	sigaddset(&msk_quit, SIGQUIT);
	sigact.sa_handler = on_signal;  
	sigact.sa_mask = msk_quit;  
	sigaction(SIGINT, &sigact, NULL);  
	sigact.sa_mask = msk_int;  
	sigaction(SIGQUIT, &sigact, NULL);  
	printf("INT et QUIT piégés\n");  
	sleep(10);  
}
```

```shell
$ test-sigaction  
INT et QUIT piégés  
^C*** signal 2  
^\^\*** fin handler  
*** signal 3  
*** fin handler  
$
```

### Durée de vie du handler

Lorsque la fonction sigaction() est utilisée pour piéger  
un signal le handler est valide jusqu'à ce qu'un prochain sigaction() l'invalide.

En revanche la durée de vie du handler établi par signal() est dépendante de l'implémentation après réception du signal, l'action par défaut est rétablie on est donc souvent conduit à réarmer le handler dans le handler lui-même (cas d'Unix SVR4, de Solaris...).

## Signaux et autres fonctions

### fork() et exec()

 Attributs de processus  
– État des signaux (ignoré, action par défaut, piégé)  
– Masque des signaux bloqués  
 Héritage de l'état et du masque lors d'un fork()  
 Transmission de l'état et du masque à travers un exec()  
– sauf pour les signaux piégés qui sont rétablis à l'action par défaut
