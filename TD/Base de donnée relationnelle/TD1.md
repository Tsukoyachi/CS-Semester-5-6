# TD n°1 Base de Données Relationnelle
---
## Enoncé :
![[BDR_TD1.pdf]]

## 1/ Formalisation de contraintes

1. $\forall m_{1},m_{2} \in marque$ : 
$(t_{1}.NomM = t_{2}.NomM$ ^ $t_{1}.Classe = t_{2}.Classe$ ^ $t_{1}.Pays= t_{2}.Pays) \Rightarrow (t_{1}.IdM = t_{2}.IdM)$           

2. $\forall s_{1},s_{2} \in societe$ :
($t_{1}.IdSoc = t_{2}.IdSoc$) $\Rightarrow$ ($t_{1}.NomSoc = t_{2}.NomSoc$ ^ $t_{1}.Pays = t_{2}.Pays$)

3. $\forall m_{1} \in marque, \exists s_{1} \in societe \Rightarrow t_{1}.IdProp = t_{2}.IdSoc$ 

4. $\forall m_{1},m_{2} \in marque :$
($t_{1}.pays = t_{2}.pays$ ^ $t_{1}.NomM = t_{2}.NomM$ ^ $t_{1}.Classe = t_{2}.Classe$) $\Rightarrow$ ($t_{1}.IdM = t_{2}.IdM$ ^ $t_{1}.IdProp = t_{2}.IdProp$)

5. $\forall t_{1},t_{2} \in enreg:$
$t_{1}.IdM = t_{2}.IdM \Rightarrow (t_{1}.NumE = t_{2}.NumE$ ^ $t_{1}.Pays = t_{2}.Pays$ ^ $t_{1}.DateE = t_{2}.DateE$ ^ $t_{1}.IdDeposant = t_{2}.IdDeposant$)

6. $\forall t_{1},t_{2} \in enreg:$
($t_{1}.Pays = t_{2}.Pays$ ^ $t_{1}.NumE = t_{2}.NumE) \Rightarrow t_{1}.IdM= t_{2}.IdM$ 
**ou**
($t_{1}.Pays = t_{2}.Pays$ ^ $t_{1}.IdM \neq t_{2}.IdM) \Rightarrow t_{1}.NumE \neq t_{2}.NumE$  
**ou**
$t_{1}.Pays = t_{2}.Pays \Rightarrow$  ($t_{1}.NumE = t_{2}.NumE \Rightarrow t_{1}.IdM= t_{2}.IdM$) 

7. $\forall t_{1} \in enreg, \exists t_{2} \in marque, t_{1}.Pays= t_2.Pays$ ^ $t_{1}.IdM = t_{2}.IdM$

8. $\forall t_{1} \in enreg, \exists t_{2} \in societe, t_1.IdDeposant = t_{2}.IdSoc$ 

9. $\forall t_{1},t_{2} \in enreg:$
($t_{1}.Pays = t_{2}.Pays$ ^ $t_{1}.NumE \geq t_{2}.NumE$) $\Rightarrow$ ($t_{1}.Pays = t_{2}.Pays$ ^ $t_{1}.DateE \geq t_{2}.DateE$)

10. $\forall t_{1} \in vente, \exists t_{2} \in enreg, t_{1}.IdM = t_{2}.IdM$

11. $\forall t_{1} \in vente, \exists t_{2} \in marque, t_{1}.IdM = t_{2}.IdM$ ^ $t_{1}.Pays =t_{2}.Pays$ 

12. $\forall t_{1},t_{2} \in vente:$
$t_{1}.NumV = t_{2}.NumV \Rightarrow (t_{1}.IdM = t_{2}.IdM$ ^ $t_{1}.DateV = t_{2}.DateV$ ^ $t_{1}.Pays = t_{2}.Pays$ ^ $t_{1}.IdVend = t_{2}.IdVend$ ^ $t_{1}.IdAch = t_{2}.IdAch$) 

13. $\forall t_{1},t_{2} \in vente:$
($t_{1}.Pays = t_{2}.Pays$ ^ $t_{1}.DateE < t_{2}.DateE$) $\Rightarrow$ ($t_{1}.NumV < t_{2}.NumV$)

14. $\forall v_{1}\in Vente$ :
$\forall v_{2} \in Vente$ ($v_{1}.IdM = v_{2}.IdM$) $\Rightarrow$ ($v_{1}.NumV < v_{2}.NumV \wedge \exists e_{3}\in enreg (v_{1}.IdVend = e_{3}.IdDeposant \wedge v_{1}.IdM = e_{3}.IdM)$) $\vee$ $\exists v_{3}\in Vente, (v_{1}.IdM = v_{3}.IdM) \wedge (v_{1}.NumV < v_{3}.NumV) \wedge$
$\neg(\exists v_{4}\in Vente, (v_{1}.IdM = v_{4}.IdM)\Rightarrow (v_{1}.NumV<v_{4}.NumV<v_{3}.NumV)) \wedge (v_{1}.IdAch = v_{3}.IdVend)$  