# Algèbre relationnelle
---
### Lessons date :
- 10/10/22

### Teachers :
- Catherine Faron

### Tags :
#BDD #Base #Données #Relationnelle

---

![[BDR2022_cours2.pdf]]

On va effectuer de opérations sur des relations dont le résultat sera une nouvelle relation qui pourra à son tour être manipulée. Le but étant de faire des recherches dans les relations.

## Opérations ensemblistes (théorie des ensembles)
- Union, intersection, différence
- Produit cartésien

### Union, intersection, différences
Soient r et s deux instances d'un même schéma de relation R.
Les trois opérations suivantes définissent chacune une instance du même schéma de relation R :

- $r\cup s = \{t | t \in r$ ou $t \in s\}$ 
- $r\cap s = \{ t|t \in r$ et $ t $\in s\}$
- r - s = { t | t $\in r$ et $t \notin s$} 

```ad-warning
title: Attention !!!!

Pour effectuer l'une des 3 opérations, les deux relations doivent posséder les mêmes attributs !!!
![[Pasted image 20221010140254.png | center]]
```


### Produit cartésien
```ad-warning
title: Attention !!!

Il est impossible de faire un produit cartésien si les deux relation ont au moins un attribut en commun
```

## Opérations relationnelles
- Projection
- Sélection
- Jointure naturelle
- Division
- Renommage

### Projection 

