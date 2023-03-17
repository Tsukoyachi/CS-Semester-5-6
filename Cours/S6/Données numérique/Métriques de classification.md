# Métriques de classification
---
### Lessons date :
- 17-03-2023

### Teachers :
- Diane Lingrand

### Tags :
- #Données 
- #Numérique 

---

On a des sons classés en 3 classes :
- "Dog"
- "Cat"
- "Bird"
Tous provenant du dataset Speech Commands
- 200 sons par classes pour l'entraînement, 200 autres par classe pour les tests.
- 1 son est décris par un seul vecteur MFCC (durée du son)
- Classification par algorithme kNN :
	- quel k ?


### Evaluation d'une classification binaire : positifs et négatifs

vrai positifs (VP) : données positives calculées comme positive
vrai négatifs (VN)  données négatives calculées comme négatives
faux positifs (FP) : données négatives calculées comme positive
faux négatifs (FN) : données positives calculées comme négatives

Matrice de confusion :
                              Classes estimées
                              Positif   |   Négatif
Classes | positif  |     9       |        1             Ici le 9 est un VP et le 1 est un FN
réelles   | négatif |     1       |        9             Ici le 1 est un VN et le 9 est un FP

#### Formules à ne pas apprendre

Précision (accuracy) : $\frac{VP + VN}{P + N} = \frac{VP + VN}{VP+FP+VN+FN}$ 
Sensibilité, rappel (recall, taux de VP) : $\frac{VP}{VP+FN}$
Spécificité, sélectivité, taux de VN : $\frac{VN}{VN+FP}$
Précision (précision), valeur de prédiction positive : $\frac{VP}{VP+FP}$
Valeur de prédiction négative : $\frac{VN}{VN+FN}$
**liste incomplète**


### Métriques pour la classification multi-classes

- Précision accuracy : Fraction des prédictions correctes
- mesures F1 : plusieurs options sont disponibles, entre autre :
	- 'micro' : calcul global des VP, FP,FN
	- **incomplet**

