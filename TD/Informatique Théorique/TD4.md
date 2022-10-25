![[TD4_2021_preuvepropositionnel.pdf]]

---
# Exercice 1

1.  $$\displaylines{
	   \neg(MgO \land H_{2}) \lor (Mg \land H_{2}O) \newline \Leftrightarrow (\neg MgO \lor \neg H_{2} \lor Mg) \land (\neg MgO \lor \neg H_{2} \lor H_{2}O) \newline
	   \newline
	   C_{1}= \neg MgO \lor \neg H_{2} \lor Mg \newline
	   C_{2}= \neg MgO \lor \neg H_{2} \lor H_{2}O \newline
	   \newline
	   \neg (C \land O_{2}) \lor (CO_{2}) \newline
	   \Leftrightarrow \neg C \lor \neg O_{2} \lor CO_{2} \newline
	   C_{3} = \neg C \lor \neg O_{2} \lor CO_{2} \newline \newline
	   \neg (CO_{2} \land H_{2}O) \lor (H_{2}CO_{3}) \newline \Leftrightarrow \neg CO_{2} \lor \neg H_{2}O \lor H_{2}CO_{3} \newline C_{4}= \neg CO_{2} \lor \neg H_{2}O \lor H_{2}CO_{3}
	   \newline C_{5}=MgO, C_{6}= H_{2}, C_{7}=O_{2} \newline C_{8}= C, C_{9} = \neg H_{2}CO_{3} \newline \newline Résolution : \newline
	   C_{3},C_{7} \Rightarrow C_{10}= \neg C \lor CO_{2} \newline C_{10},C_{8} \Rightarrow C_{11}= CO_{2} \newline C_{2},C_{5} \Rightarrow C_{12}= \neg H_{2} \lor H_{2}O \newline C_{12},C_{6}\Rightarrow C_{13} =  H_{2}O \newline C_{4},C_{13} \Rightarrow C_{14} = \neg CO_{2} \lor H_{2}CO_{3} \newline
	   C_{11},C_{14} \Rightarrow C_{15}= H_{2}CO_{3} \newline
	   C_{9},C_{15} \Rightarrow C_{16}= \emptyset
   }$$
   2. LC = lasagnes cuites, LTS = Lasagnes trop salées, LV = Lasagnes Végétariennes, ID = invités déçus.
      $$\displaylines{
	      C_{1}= \neg LC \lor LTS \newline
	      LV \lor LTS \Rightarrow ID \newline
	      \Leftrightarrow \neg (LV \lor LTS) \lor ID \newline \Leftrightarrow (\neg LV \land \neg LTS) \lor ID \newline \Leftrightarrow (\neg LV \lor ID) \land (\neg LTS \lor ID) \newline 
	      C_{2} = \neg LV \lor ID, C_{3}=\neg LTS \lor ID \\
	      C_{4}= \neg LV \\ C_{5}= LC \\
	      C_{6}= \neg ID \newline \newline
	      Résolution : \\
	      C_{1},C_{5} \Rightarrow C_{7} = LTS
	      \\ C_{7},C_{3} \Rightarrow C_{8} = ID \\
	      C_{8},C_{6} \Rightarrow C_{9} = \emptyset
      }$$

3. $$\displaylines{
	   \neg\Phi : \neg((A\Rightarrow(B\Rightarrow C)) \Rightarrow ((A \Rightarrow B) \Rightarrow (A \Rightarrow C))) \\
	   \Leftrightarrow \neg (\neg (\neg A \lor (\neg B \lor C)) \lor (\neg (\neg A \lor B) \lor (\neg A \lor C))) \\
	   \Leftrightarrow \neg(\neg (\neg A \lor \neg B \lor C) \lor ((A \land \neg B) \lor (\neg A \lor C))) \\
	   \Leftrightarrow \neg ((A\land B \land \neg C) \lor ((A\land \neg B)\lor (\neg A \lor C))) \\
	   
   }$$
