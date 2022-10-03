# Introduction
---
### Lessons date :
- 03/10/22

### Teachers :
- Catherine Faron

### Tags :
#BDD #Base #Données #Relationnelle

---

### Définition d'une base de données :

Définition large : Ensemble de données stocké numériquement et pouvant servir à un ou plusieurs programme.
	-Inclut à peu près tous les types de fichiers

Définition plus restreinte : Ensemble de données numériques apparentées qui possède une structure, c'est à dire dont l'organisatiion répond à une logique systématique.
	- On parle de modèle logique de données pour décrire cette structure.

### Histoire :
- Années 60 : modèle de données hiérarchique, modèle de données réseaux
- 1970 : modèle relationnel, Tex Codd (prix turing 1981)
- Depuis les années 2000 : NoSQL
Différents modèles : clé-valeurs, document, graphe...

### Système de Gestion de Base de Données (SGBD)
- Décrire les données (DDL : data definition language)
- Modifier, Rechercher de l'information de manière fiable (DML : data manipulation language)
	- Traiter de grands volumes de données
	- Traiter rapidement les données.
- Contrôler les données (DCL : data control language)
	- Sécuriser les accès aux données.
	- Contrôler la qualité des données.
- Partager les données (Entre plusieurs applications)
- Gérer la concurrence des accès parallèles.

### Abstraction des données :
####Architecture ANSI-SPARC
![[Pasted image 20221003135150.png | center| 650]]
Indépendance entre représentation physique et logique.

DIfférentes vues de la structure.

### Le modèle relationnel
- Fondamentaux
	- Contenant : Schéma de relation
		- n-uplet d'attributs
		- Attribut : Nom x Domaine
	- Contenant : Instances de relation
		- Ensemble fini de n'uplets (ou tuples) de valeurs d'attributs.

### Exemples et contre-exemples de domaine
- entier
- reel
- chaîne de caractères

Mais on ne peut pas faire de types structurés par exemple on ne peut pas mettre un Point avec un réel pour x et un réel pour y dans une seule case d'une base de données, par contre on pourra faire un champ pour un réel x et un champ pour un réel y.

**Un slide à rattraper**

### Instances de relation
**insérer exemple bdd simple**
- Les lignes peuvent être permutées.
- Les lignes ne peuvent pas être dupliquées.
- Les colonnes peuvent être permutées... mais cela complique l'écriture des tuples :
	- Imaginons une relation avec deux attributs A et B, tous les deux du même domaine entier. En principe on note un tuple de cette relation sous la **slide à rattraper**.
- Soit R une relation, ayant comme ensemble d'attributs A = {A1,...,An}.
- On appelle tuple défini sur R, tout n-uplet de valeurs t = (v1,...,vn) avec v1,...,vn associées respectivement aux attributs A1,...,An et v1 appartient à dom(Ai)
- Formellement, un tuple est un élément du produit cartésien des **slide à rattraper**

**slide à rattraper car juste écouté**

