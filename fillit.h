/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 13:16:59 by vlaroque          #+#    #+#             */
/*   Updated: 2018/12/15 17:19:22 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include <sys/uio.h>
# include <unistd.h>
# include "libft.h"

# define BUFF_SIZE 547

//Debug
# include <stdio.h>

typedef struct	s_tetris
{
	char	tab[4][4];
	char	letter;
	int		posx;
	int		posy;
}				t_piece;
int				ft_num(int nbr, char position);
int				*ft_tetrimino_tab(int *tetri);
t_piece			*file_analyser(int fd, int *nbr);
int				ft_sqrt_plus(int nbr);

void			clean_matrice_from(int mat[20][20], t_piece *pieces, int value, int nb_pieces);
int				i_check_tetris(int mat[20][20], t_piece *tetris, int *ref_col, int *ref_lin, int *size);
int				i_check_solution(int nb_pieces, int min_size, t_piece *pieces);
int				ft_sqrt(int nb);
void			initialize_matrice(int mat[20][20]);
void			print_matrice(int mat[20][20], int size);
int				next_position(int mat[20][20], t_piece *tetris, int *size, int nb_pieces);
#endif
