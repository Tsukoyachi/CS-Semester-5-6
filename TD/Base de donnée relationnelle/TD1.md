# TD n°1 Base de Données Relationnelle
---
## Enoncé :
![[BDR_TD1.pdf]]

## 1/ Formalisation de contraintes

1. $\forall m_{1},m_{2} \in marque$ : 
$(t_{1}.NomM = t_{2}.NomM$ ^ $t_{1}.Classe = t_{2}.Classe$ ^ $t_{1}.Pays= t_{2}.Pays) \Rightarrow (t_{1}.IdM = t_{2}.IdM)$           

2. $\forall s_{1},s_{2} \in societe$ :
($t_{1}.IdSoc = t_{2}.IdSoc$) $\Rightarrow$ ($t_{1}.NomSoc = t_{2}.NomSoc$ ^ $t_{1}.Pays = t_{2}.Pays$)

3. $\forall m_{1} \in marque, \exists s_{1} \in societe \Rightarrow t_{1}$ 