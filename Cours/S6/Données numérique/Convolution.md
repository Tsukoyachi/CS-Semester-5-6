![[Pasted image 20230428101434.png | center]]

Par convention on ne va pas calculer la convolution sur les bords.

On effectue le flip en x et en y du filtre ce qui nous donne :

<table style="margin:auto">
	<tr>
		<th>2</th>
		<th>1</th>
		<th>-2</th>
	</tr>
	<tr>
		<th>2</th>
		<th>1</th>
		<th>0</th>
	</tr>
	<tr>
		<th>-1</th>
		<th>2</th>
		<th>1</th>
	</tr>
</table>

On va donc appliquer ce filtre aux différentes case qui ne sont pas sur les bords, par exemple pour la case (1;1) cela donne :

2\*10 + 1\*20 - 2\*36 + 2\*12 + 34 + 0\*46 - 6 + 2\*18 + 24 = 80

On continue ce calcul sur chaque case pour obtenir ceci :

<table style="margin:auto">
	<tr>
		<th>80</th>
		<th>148</th>
		<th>180</th>
	</tr>
	<tr>
		<th>64</th>
		<th>161</th>
		<th>193</th>
	</tr>
</table>
