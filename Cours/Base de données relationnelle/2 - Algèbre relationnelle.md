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
Une projection va isoler certains champs d'une table, dans l'exemple si dessous la projection par rapport à classe et prop sur la table marque va isoler les colonnes classe et prop et **supprimer les doublons** donc il ne reste que 3 éléments car le tuple {12:Classe, sun:Prop} est présent deux fois.

![[Pasted image 20221010140616.png | center | 600]]

```ad-important
title: Distributivité

On a une distributivité de la projection par rapport à l'union :
![[Pasted image 20221010141115.png | center]]

Mais on n'a pas la distributivité de la projection par rapport à l'intersection ou la différence :
![[Pasted image 20221010141215.png | center]]
```

### Sélection
![[Pasted image 20221010141643.png | center | 600]]

L'opération sélection est en réalité une sorte de filtre qui trie les instances d'une relation afin de ne garder que celle respectant tout les critères de la sélection, ici l'on ne garde que les instances ayant une valeur de 14 pour l'attribut classe.

```ad-info
title: Propriétés **à refaire**

![[Pasted image 20221010142119.png |center |500]]

![[Pasted image 20221010142028.png | center]]
![[Pasted image 20221010141857.png | center]]
![[Pasted image 20221010142017.png | center]]
```


#### Sélection étendue
**à rattraper j'ai pas trop compris**

### Jointure naturelle
Contrairement aux autres opérations, elle est définie pour les tuples avant d'être définie pour les relations.

#### Jointure naturelle de tuple
Si les deux tuples n'ont pas d'attributs commun, alors leurs jointure est la concaténation des deux donc leur produit cartésien.

Sinon, ils ne peuvent se joindre que lorsque leurs attributs de même nom sont de même valeurs.

La jointure peut donc retourner **l'ensemble vide** dans deux cas :
- Si les deux relations n'ont aucun élément alors la jointure retournera l'ensemble vide.
- Si les deux relations ont des valeurs différentes sur leurs attributs commun cela retournera également l'ensemble vide.

Bien sûr peut importe la cas, on ne duplique pas les attributs en commun.

Deux tuples $t_{r}(R)$ et $t_{s}(S)$  sont **joignables** si et seulement si il existe un tuple $t(R\cup S)$ tel que : $\Pi_{r}(t) = t_{r}$ et $\Pi_{s}(t) = t_{s}$ 

Ce tuple unique est noté :
	$t = t_{r} \Join t_{s}$

$(t_{r}\Join t_{s}) existe \Leftrightarrow \Pi_{R \cap S}(t_{r}) = \Pi_{R \cap S}(t_{s})$ 

Si $(t_{r}\Join t_{s}) existe, alors \Pi_{R}(t_{r}\Join t_{s}) = t_{r}$ et $\Pi_{s}(t_{r}\Join t_{s}) = t_{s}$

![[Pasted image 20221017140336.png |center]]

![[Pasted image 20221017140425.png |center]]

- Propriétés
	- Associativité : $r \Join (s \Join t) = (r \Join s) \Join t$ 
	- Distibutivité vis à vis de l'union : $r \Join (s \cup t) = (r \Join s) \cup (r \Join t)$
	- Jointure et produit cartésien : Si $R \cap S = \emptyset$ alors $r \Join s$ est isomorphe à    r **x** s

### Division

```ad-note
title: Ce que j'ai compris

Le but de la division est de construire un élément qui lorsque l'on en fait la jointure natuelle avec le 'diviseur' est inclu dans la table de départ.
```

![[Pasted image 20221017141826.png | center]]
Ici r est la table de départ, s la table qui divise et q le résultat obtenu, on voit que lorsque l'on fait la jointure de q et de s on obtient les 3 premiers tuples de r.

Si l'on avait tenté d'ajouté Paul à q on aurait eu deux lignes en trop car il n'y a pas les tuples Paul 200m et Paul 800m, idem pour Jacques.

![[Pasted image 20221017142050.png | center]]

