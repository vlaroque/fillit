# fillit
fillit projet from 42

#Notes :

determine_square_min()				ND		determine la taille du tableau minimale;
initialise_matrice()				ND		rempli la matrice de 0;
i_check_solution() == solution.c
	> i_check_tetris
		> i_touch_tetris			ND
		> i_clone_matrice			ND
		> i_check_tetris
	> make_init
	> print_matrice					ND		impression finale de la matrice
	> make_move
		> next_position
		> make_iter
			> clean_matrice_from	ND		supprimes toutes les lettres apres l'ASCII value 
											et met toutes les positions de celles ci a 0 dans le tableau
			> next_position
				clean_matrice_from	ND

* time fillit petitegrille : 5.63s

* grille de tab reduite.
	* time fillit minigrille : 4.76s
	* time fillit petitegrille : ~1500s
* supression variables globales pour le tableau buff
	* time fillit minigrille : 0.35s
	* time fillit petitegrille : 128.19s
	* time fillit demigrille : 447.25s
* passage en chars
	* time fillit minigrille : 0.38s
	* time fillit petitegrille : 136.93s
* suppression variable nb_pieces dans toutes les sous fonctions et clean de la table entiere;
	* time fillit minigrille : 0.35s
	* time fillit petitegrille : 123.00s
	* itme fillit demigrille : 420.58s



Futures updates:
* Faire une structure pour les pieces contenant
	* t_pieces *pieces
	* int *az (piece en cours de traitement)
	* int *nb_pieces
* Mettre des a tous les endroits possibles