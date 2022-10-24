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

1. On veut les nom, prénom, des employés ayant un salaire supérieur à leur employeur et ayant X comme employeur.
2. On veut les projets dont les employés ne travaillent pas dans le département du projet.
---
## Exercice 3

1. On aurait pu également faire une projection sur marque pour ne garder que IdProp à la place du renommage de Pays, le but étant juste d'éviter la jointure entre l'attribut Pays de societe et l'attribut Pays de marque. 
   $$\displaylines{
   A = societe \Join \delta_{IdS \rightarrow IdProp, X \rightarrow Pays}(marque) \newline
   res = \Pi_{Nom,Pays}(A)
   }$$
2. $$\displaylines{
   A = \sigma_{Classe = 24}(marque) \newline
   B = societe \Join \delta_{IdS \rightarrow IdProp, X \rightarrow Pays}(A) \newline
   res = \Pi_{Nom,Pays}(B)
   }$$
3. $$\displaylines{
   A = marque \newline
   B = \sigma_{Pays=France}(A \Join \Pi_{IdM}(enreg)) \newline
   C = \Pi_{NomM,Classe}(B) \newline
   D = C \Join \delta_{NomM2 \rightarrow NomM,Classe2 \rightarrow Classe}(C) \newline
   E = \sigma_{NomM=NomM2,Classe\neq Classe2}(D) \newline
   res = \Pi_{NomM}(E) 
   }$$
4. $$\displaylines{
      A = \Pi_{Pays}(enreg) \newline
      res = \Pi_{IdM}(enreg \div A)
      }$$
5. $$\displaylines{
 A = \sigma_{DateE \geq 29/01/1995}(enreg) \newline
 B = \delta_{IdS \rightarrow IdDeposant}(\Pi_{IdM,IdDeposant}(A)) \Join \Pi_{IdM,NomM}(marque) \Join societe \newline
 C = \Pi_{NomM,Nom,Pays}(B)
   }$$
   