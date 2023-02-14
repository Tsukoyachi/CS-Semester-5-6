![[01 Prod et Exe Prog.pdf]]

---

# Modèle de Von Neumann

## Concept de base

Distinction entre Programme et Processus :
- Un programme est l'ensemble des procédures, le résultats statique d'une compilation/édition de liens (binaire exécutable)
	- Ensemble de procédures
- Un processus est l'activité dynamique résultant de l'exécution d'un programme
	- Enchaînement (séquentiel ou concurrent d'activité)

Qu'est ce qu'un contexte ?

Il peut s'agir d'une information caractérisant l'état courant d'un processus qui est sauvegardé lors de la suspension du processus et rechargé lors de sa reprise.

Il peut également s'agir d'un contexte matériel comprenant donc :
- Mot d'état 
- Compteur ordinal 
- Registres de l'unité centrale

Enfin, on peut parler de contexte logiciel (ou système) :
- Segments de texte (instructions), de données, de pile… 
- Attributs : identification utilisateur, droits d'accès, priorité… 
- Ressources utilisées : fichiers ouverts...

## Evénements, interruptions et déroutements

Une **inter**