# TD2
---
![[BDR2022_TD2.pdf]]

### Exercice 1
1. $\Pi_{DateDeNaissance,Adresse}(\sigma_{Nom=Rochat,Prenom=Juliette}(employe))$ 
2. $\Pi_{Nom,Adresse}(employe \Join \sigma_{NomDepartement=Recherche}(departement))$
3. $\Pi_{NomProjet}(\sigma_{(Prenom=Jean,Nom=Muller)\vee(Prenom=Annie,Nom=Grandjean)}(employe) \Join travaille \Join \Pi_{NomProjet,NumeroProjet}(projet))$
4. 