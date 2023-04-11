## Exercice 1
---

1. La commande xeyes, le terminal est bloqué.
2. Après un Ctrl+Z, xeyes est suspendu, toujours ouvert mais on a de nouveau accès au terminal.
3. La commande xeyes est listé parmis les tâches en arrière plan.
![[Pasted image 20230411092128.png]]
4. Le PID de xeyes est 8157. 
   ![[Pasted image 20230411092435.png]]
5. Après une exécution de kill -SIGSTOP 8157 dans une autre instance du terminal rien ne se passe. SIGSTOP est équivalent à Ctrl+Z puisqu'il permet de mettre une suspendre une tâche et de la mettre en arrière plan.
6. Le signal correspondant est SIGCONT et je l'ai envoyé avec la commande kill -18 pid où pid correspond à la commande xeyes.
   ![[Pasted image 20230411092957.png]]
   ![[Pasted image 20230411093040.png]]
7. 