# TD3
---
## Exercice 1 :

1. Dans une table avec 3 connecteurs logiques, (4 variables) on a 16 états possible (2^4=16).
2. La formule peut se simplifier de la façon suivante :
$$\displaylines{
(P\wedge\neg Q)\vee(\neg P \wedge \neg Q) = \neg Q
}$$
3. Une table de vérité qui nécessitera une formule canonique avec plus de 3 connecteurs logique pourrait être :
![[Pasted image 20221018141847.png | center]]
Dans ce cas-ci la formule sera : $(P \wedge \neg Q) \vee (\neg P \wedge Q) \vee (\neg P \wedge \neg Q)$ Et on constate qu'il y a bien plus de 3 connecteurs logiques.

4. Si on reprend la table de la question 3, sa formule est équivalente à :
$$\displaylines{
\neg (P \wedge Q) = \neg P \vee \neg Q
}$$

5. Formule de base du XOR : $(\neg P \wedge Q) \vee (P \wedge \neg Q)$ 
La formule du XOR est non simplifiable donc on a besoin de 3 connecteurs logiques pour l'exprimer.

6. Oui avec le théorème de Morgan.
---
## Exercice 2 :
![[Pasted image 20221018143425.png |center]]
1. $$\displaylines{
   \Leftrightarrow B \wedge ((A \wedge C) \vee (A \wedge \neg C) \vee (\neg A \wedge \neg C) \vee (\neg A \wedge C)) \newline
   \Leftrightarrow B \wedge (A \vee \neg A) \newline
   \Leftrightarrow B
   }$$
   ![[Pasted image 20221018143734.png | center]]
   2. $$\displaylines{
      A \wedge ((\neg B \wedge \neg C) \vee (B \wedge \neg C) \vee (B \wedge C) \vee (B \wedge \neg C)) \newline
      \Leftrightarrow A\wedge (\neg C \vee B)
      }$$
      ![[Pasted image 20221018144004.png | center]]
  3. $$\displaylines{
     \Leftrightarrow (\neg A \wedge \neg C) \vee (A\wedge B) \wedge (\neg C \vee D \vee (C \wedge \neg D)) \newline
     \Leftrightarrow (\neg A \wedge \neg C) \vee (A\wedge B) 
     }$$