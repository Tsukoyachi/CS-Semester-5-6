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

8. $\forall t_{1} \in enreg, $