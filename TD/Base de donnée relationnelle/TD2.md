# TD2
---
![[BDR2022_TD2.pdf]]

## Exercice 1
1. $\Pi_{DateDeNaissance,Adresse}(\sigma_{Nom=Rochat,Prenom=Juliette}(employe))$ 
2. $\Pi_{Nom,Adresse}(employe \Join \sigma_{NomDepartement=Recherche}(departement))$
3. $\Pi_{NomProjet}((\sigma_{(Prenom=Jean,Nom=Muller)}(employe) \cup \sigma_{Prenom=Annie,Nom=Grandjean}(employe)) \Join travaille \Join \Pi_{NomProjet,NumeroProjet}(projet))$
4. $\Pi_{NomProjet}(\sigma_{(Prenom=Jean,Nom=Muller)}(employe) \Join travaille \Join \Pi_{NomProjet,NumeroProjet}(projet)) \cap \Pi_{NomProjet}(\sigma_{Prenom=Annie,Nom=Grandjean}(employe) \Join travaille \Join \Pi_{NomProjet,NumeroProjet}(projet))$
5. $$\Pi_{Nom,Prenom}(employe - (employe \Join \Pi_{NumeroSecuriteSociale}(travaille)))$$
6. $\Pi_{Nom,Prenom}(employe)$-$\Pi_{Nom,Prenom}(\sigma_{lieu=Sophia antipolis}(employe \Join travaille \Join \Pi_{NumeroProjet,Lieu}(projet)))$
7. $\Pi_{Nom,Prenom}(\sigma_{lieu=Sophia antipolis}(employe \Join travaille \Join \Pi_{NumeroProjet,Lieu}(projet)))$ - $\Pi_{Nom,Prenom}(\sigma_{lieu\neq Sophia antipolis}(employe \Join travaille \Join \Pi_{NumeroProjet,Lieu}(projet)))$
8. $$\displaylines{A = \delta_{Superieur\rightarrow NumeroSecuriteSociale}(\sigma_{Prenom=Juliette,Nom=Rochat}(employe)) \newline
   B = \Pi_{NumeroSecuriteSociale}(A) \newline
   res = \Pi_{Nom,Prenom}(employe\Join B)}$$
9. $$\displaylines{
   A = \Pi_{NumeroDepartement}(departement) \newline
   B = employe \Join travaille \newline
   res = \Pi_{NumeroProjet}(B \div A)
   }$$
---
## Exercice 2

1. On veut les nom, prénom, des employés ayant un salaire supérieur à leur employeur et ayant dont l'employeur est X.
2. On veut les projets dont les employés ne travaillent pas dans le département du projet.
---
## Exercice 3

1. $$\displaylines{
   A = \sigma_{IdS = X}(societe \Join \delta_{X \rightarrow IdProp}(marque)) \newline
   res = \Pi_{Nom,Pays}(A)
   }$$
2. $$\displaylines{
   A = \sigma_{Classe = 24}(marque) \newline
   B = \sigma_{IdS = X}(societe \Join \delta_{X \rightarrow IdProp}(A)) \newline
   res = \Pi_{Nom,Pays}(B)
   }$$
3. $$\displaylines{
   A = \sigma_{IdS = X}(societe \Join \delta_{X \rightarrow IdProp}(marque)) \newline
   B = \sigma_{Pays=France}(A \Join \Pi_{IdDeposant}(enreg)) \newline
   C = \Pi_{IdM,IdProp,NomM,Classe}(B) \newline
   D = C \Join \delta_{IdM2\rightarrow IdM,IdProp2 \rightarrow IdProp2,NomM2 \rightarrow NomM,Classe2 \rightarrow Classe}(C) \newline
   E = \sigma_{NomM=NomM2,Classe\neq Classe2,IdProp\neq IdProp2}
   }$$