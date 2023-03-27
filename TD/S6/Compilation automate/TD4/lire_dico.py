import re

with open("dico.txt") as fichier:
	mots = fichier.read()
	#Le r devant les guillemets demande à python de ne pas interpréter certaines combinaisons de caractères comme \n.
	#Ici ça ne change rien mais ça permet d'éviter des erreurs quand on fait des regex.
	ma_regex = r"^[aeiouy]+$" #tous les mots composés seulement de voyelles 
	#re.MULTILINE permet à ^ et $ de désigner le début et la fin d'une ligne
	for mot in re.findall(ma_regex, mots,re.MULTILINE): 
		print(mot)