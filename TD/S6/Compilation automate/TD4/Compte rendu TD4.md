## Exercice 1 :
---

1. grep -E \'\^\[aeiouy]\*+$' dico.txt
2. grep -E \'\^\z\.\*\x\$\' dico.txt
3. grep -E \'\^\.\{23\,25\}\$' dico.txt
4. grep -E \'\^\(\.\*\v\.\*\)\{\3\}\$\' dico.txt
5. grep -E \'\^\(\[zrtpqsdfghjklmwxcvbn]{2}\[aeiouy]{2})+$' dico.txt
   Pour celui-ci on aurait pu enlever les voyelles de l'alphabet sans soucis mais il aurait compté les symboles comme étant correctes.
6. grep -E \'\^\.\*\[zrtpqsdfghjklmwxcvbn]\{\5\}\.\*\$\' dico.txt
7. grep -E \'\^\y\.\*\a\.\.\$\' dico.txt
   Pour celui ci on peut remplacer .. par .{2}

