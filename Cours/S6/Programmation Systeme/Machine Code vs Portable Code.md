# Machine Code vs Portable Code
---
### Lessons date :
- 02-05-2023

### Teachers :


### Tags :


---

## Machine Code

Le langage machine est le langage natif du processeur. Il est composé d'instructions et de données à traiter.

Chaque processeur possède son propre langage machine. Si un processeur A peut exécuter toutes les instructions d'un processeur B on dit que A est compatible avec B.

Ce code machine est aujourd'hui généré par le compilateur du langage.

Donc compilation en code natif (dans le langage du processeur), c'est ce que l'on a vu au semestre précédent avec le C.

## Portable Code

Un code portable est un langage intermédiaire pas directement exécutable.

Il possède plusieurs dénominations :
- A la fin des années 60 c'était le **p-code**
- Bytecode (code en "bytes")
- Managed Code (exécuté par une machine virtuelle CLR)

Principales motivations :
- Renforcer la sureté de fonctionnement
- Lutter contre les fuites mémoires (source principale de bugs en C) -> grâce au Garbage Collector
- Permet la compilation à la volée (JIT : Just-in-Time)

Nécessite une machine virtuelle pour interpréter le code et le traduire dans le langage du processeur.
- Dans le cas de Java il faut une JVM
- Dans le cas de .NET (C#) il faut la CLR (Common Language Runtime)
- Mais aussi dans d'autres langages : Matlab, ...

### Bytecode Java pour la JVM

![[Pasted image 20230502081542.png | center]]
\*jvm et non jvvm sur le schéma

Le code source Java est compilé dans un langage intermédiaire (Bytecode), ce code fonctionnera aussi bien sous Unix que sous Windows ou autre, sans aucune modification.

Le Bytecode est transformé en un code machine compréhensible par le processeur de la machine réelle, Java est donc aussi un langage interprété.

L'interprète de la JVM est très élaboré pour être le plus rapide possible, il inclut par exemple un JIT (Just in Time Compiler) qui permet la traduction du Bytecode vers du code natif seulement lorsque c'est nécessaire (première instanciation d'un classe, boucles...)

### Quelques définitions du monde Microsoft

- CLI : Common Language Infrastructure
	- L'environnement d'exécution (donc pas seulement la machine virtuelle) basée sur le CLR et le CIL.
- CLR : Common Language Runtime
	- La machine virtuelle chargée d'exécuter le portable-code
- CIL : Common Intermediate Language
	- Equivalent au Bytecode Java
	- Normalisé par l'ECMA
	- Language proche de la machine
	- MSIL : implémentation MS du CIL.

![[Pasted image 20230502082221.png | center]]

## Comment rendre du code natif et du p-code interopérable ?

Ici on continue en Java car c'est l'un des langages que l'on a vu au cours de notre formations mais on pourrait le faire dans tous les langages.

### Pourquoi JNI ?

Le but n'est pas d'avoir à réécrire tout ce qui existe déjà en C ou autre. On souhaite pouvoir faire cohabiter plusieurs langages afin de ne pas recommencer from scratch.

Programmation d’un nouveau périphérique, logiciel de base, Entrées/Sorties, Cartes d’acquisition de commandes :
- Avec l'adressage physique, accès au matériel, aux pilotes de la carte, interruptions...

Développement en C/C++, tout en bénéficiant de l’environnement Java pour des IHM par exemple.

Code natif pour de meilleures performances en temps d'exécution (plus toujours vrai).

Mais ..... portabilité remise en question

### Possibilité de JNI

L’API JNI offre l’accès à la machine virtuelle et son environnement :
- accès aux variables d’instance, appel de méthodes, chargement d’une classe, création d'instances...
- Mécanisme de bas-niveau...
- Exceptions
- Threads
- ...

### Deux grands intérêts

Quand Java appelle C/C++ :
- Prototypes et conventions entre les deux langages
- Chargement dynamique de bibliothèques en Java

Quand du C/C++ accède à l'environnement Java :
- Lecture/écriture de données d'instance et de classes
- Invocation de méthodes d'instance et de classes
- Création d'objet
- Création de tableaux et de String
- Levée et filtrage d'exceptions
- Utilisation des moniteurs (de Hoare)
- Entrées/sorties Série
- Création de machine(s) Java

### Quand Java appelle du C/C++

#### Le principe :

![[Pasted image 20230502082936.png | center]]

1. Ecrire le Code source en Java
2. Produire le .h (javac -h)
3. Ecrire le code source C/C++
4. Générer la bibliothèque dynamique
5. Exécuter le code java (après avoir rendu la bibliothèque dynamique accessible)

#### Compilation avec javac

1. javac javaVersC.java
2. Usage du mot clé *native*
3. Chargement de la bibliothèque (dll/so), dans laquelle sera implémentée le code C de bonjour, avec la méthode loadLibrary de la classe System

![[Pasted image 20230502083510.png | center]]

#### Création du fichier d’entête .h avec javac –h ...

Génération de l'interface ".h" -> `javac -h dir javaVersC.java`

![[Pasted image 20230502083619.png | center]]

#### Compilation et édition de lien du source C/C++

```C
#include <stdio.h>
#include "JavaVersC.h"
JNIEXPORT void JNICALL Java_JavaVersC_bonjour (JNIEnv *env, jobject j){
	printf("Java_JavaVersC_bonjour");
}
```

Génération de la dll, (JavaVersC.dll) avec visual C++ :

cl -Ic:\\jdk\\include -Ic:\\jdk\\include\\win32 -LD  
JavaVersC.c -FeJavaVersC.dll

Exécution par -> java javaVersC