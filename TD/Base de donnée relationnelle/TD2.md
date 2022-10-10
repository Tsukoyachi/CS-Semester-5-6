# TD2
---
![[BDR2022_TD2.pdf]]

### Exercice 1
1. $\Pi_{DateDeNaissance,Adresse}(\sigma_{Nom=Rochat,Prenom=Juliette}(employe))$ 
2. $\Pi_{Nom,Adresse}(employe \Join \sigma_{NomDepartement=Recherche}(departement))$
3. $\Pi_{NomProjet}((\sigma_{(Prenom=Jean,Nom=Muller)}(employe) \cup \sigma_{Prenom=Annie,Nom=Grandjean}(employe)) \Join travaille \Join \Pi_{NomProjet,NumeroProjet}(projet))$
4. $\Pi_{NomProjet}(\sigma_{(Prenom=Jean,Nom=Muller)}(employe) \Join travaille \Join \Pi_{NomProjet,NumeroProjet}(projet)) \cap \Pi_{NomProjet}(\sigma_{Prenom=Annie,Nom=Grandjean}(employe) \Join travaille \Join \Pi_{NomProjet,NumeroProjet}(projet))$
5. $\Pi_{Nom,Prenom}(employe)$-$\Pi_{Nom,Prenom}(employe \Join travaille)$
6. $\Pi_{Nom,Prenom}(employe)$-$\Pi_{Nom,Prenom}(\sigma_{lieu=Sophia antipolis}(employe \Join travaille \Join \Pi_{NumeroProjet,Lieu}(projet)))$
7. $\Pi_{Nom,Prenom}(\sigma_{lieu=Sophia antipolis}(employe \Join travaille \Join \Pi_{NumeroProjet,Lieu}(projet)))$ - $\Pi_{Nom,Prenom}(\sigma_{lieu\neq Sophia antipolis}(employe \Join travaille \Join \Pi_{NumeroProjet,Lieu}(projet)))$
8. 