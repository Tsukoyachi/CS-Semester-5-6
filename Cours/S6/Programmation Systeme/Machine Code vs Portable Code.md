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

L'interprète de la JVM est très élaboré pour être le plus rapide possible, il inclut par exemple un JIT (Just in Time Compiler) qui permet la traduction du Bytecode vers