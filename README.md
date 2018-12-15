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