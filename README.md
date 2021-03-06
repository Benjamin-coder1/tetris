# TETRIS

Comment lancer le jeu ? 

	>> bash compilation.sh 
	>> ./tetris      sur un terminal
	>> ./tetris_client  pour chaque jouer ( "localhost" si jeu en local)

La partie se lance : en local c'est immédiat /  en ligne la connexion peut être longue, c'est pourquoi il est plutot recommandé de jouer en réseau local (comme par exemple en partage de connexion) 
Pour jouer utiliser les fleches de direction, celle du haut permettant de tourner les autres d'aller a droit / gauche / en bas.

Comment trouver l'adresse IP ? 
<ul>
	<li> <i> <b> Window </i> </b> : paramètres > réseaux > wifi > propriété du matériel > IPV4  </li>
 	<li> <i> <b> linux </i> </b>  : Tapez la commande ifconfig dans le terminal </li>
</ul>


Le jeu  peut permettre a un joueur de jouer seul ou bien a plusieurs joueurs de jouer ensemble. Chaque joueur dispose de sa grille, le gagnant est celui qui obtient le plus haut score. L'architecture logiciel est sous forme client / serveur  : 
<ul>
	<li> <i> <b> Client </i> </b> : Reçoit la grille du joueur et l'affiche / capte les touches et les envois  </li>
 	<li> <i> <b> Serveur </i> </b>  : Pour chaque joueur, recoit les touches puis met à jour la grille et l'envoie </li>
</ul>

## Grille.cpp

On créer une classe grid, chaque joueur aura la sienne. Celle-ci va permettre dans la suite de contenir le jeu de chaque joueur et de faire les calculs et opérations pour chaque joueur. Chaque grille possède un attribut principal grid_tab : un tableau de 10*22 qui contient les pièces. Le principe de fonctionnement de la grille est le suivant, on créer une pièce que l'on insère dans la grille puis que l'on déplace grace aux méthodes de la grille.

Pour chaque joueur on procède ainsi : 
<ol>
	<li>  On commence par créer aléatoirement une pièce </li>
	<li>  On pose cette pièce dans la grille </li>
	<li>  On reçoit les touches du joueur et on actualise la grille jusqu'à ce que la pièce soit posée </li>
	<li>  La piece est alors "figée" dans la grille et on en créer une nouvelle afin de recommencer </li>

</ol>


## piece.cpp

Cette méthode permet de créer une pièce que l’on insérera dans la grille puis que l’on manipulera selon la volonté du joueur. Une fois arriver au bas de la grille la pièce sera « figée » tandis qu’une nouvelle piece sera créée et ainsi de suite jusqu'à que le jeu se termine

 

## value_piece.cpp

Ce fichier contient un tableau de dimension 7*4*4*4 qui permet de stocker les pièces, leur forme et leurs différentes orientations.

Il y a 7 pièces : <i><b> O  I  S  Z  L  J  T </i></b> chaque pièce est représentée par une grille de 4 * 4. À chaque grille est associé un numéro afin de pouvoir conserver les couleurs. Pour chaque pièce on a 4 grilles de 4 par 4, chaque grille représentant une rotation de la pièce.


## tetris_client.cpp 

Ce fichier se trouve côté client, elle est lancée par chaque joueur afin de se connecter au serveur et de pouvoir jouer. On utilise le module sfml pour gérer l'affichage, on crée alors une fenêtre puis des objets(Rectangle, Textes) que l'on incruste à la fenêtre au fil de l'algorithme. Il suffit alors de regarder dans la grille quelle valeur donc piece on a puis d'afficher un carré de la couleur correspondante. L'algorithme fonctionne ainsi

<ol>
	<li> Établissement d'une connexion avec le serveur et attente du lancement de la partie  </li>
	<li> Réception des données : grille du jeu / score / status de la partie / non joueur </li>
	<li> Affichage de la grille et réception de la touche du choix du joueur </li>
	<li> Envoi de cette touche au serveur afin de mettre a jour la grille </li>
	<li> Retour à 3 tant que le joueur n'a pas perdu </li>
</ol>


## tetris_serveur.cpp 

Ce fichier est situé côté serveur, un seul joueur le lance puis envoyé aux autres joueurs sont adresses IP. Le principe est le suivant :

<ol>
	<li> Attente de connexion de tous les joueurs </li>
	<li> Creation d'un thread par joueur qui s'occupent de la partie. Dans chaque thread :  </li>
	<ol> 
		<li> Création d'un objet grid </li>
		<li> Réception d'une touche</li> 
		<li> MAJ de la grille </li>
		<li> Envoit de cette nouvelle grille puis retour ii </li>
	</ol>
</ol>
