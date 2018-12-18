/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 13:16:59 by vlaroque          #+#    #+#             */
/*   Updated: 2018/12/18 12:31:05 by vlaroque         ###   ########.fr       */
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
# include <stdlib.h>
# define BUFF_SIZE 547

typedef struct	s_tetris
{
	char	tab[4][4];
	char	letter;
	int		posx;
	int		posy;
	int		width;
	int		heigth;
}				t_piece;
typedef struct	s_pos
{
	char	x;
	char	y;
}				t_pos;
int				ft_num(int nbr, char position);
int				*ft_tetrimino_tab(int *tetri);
t_piece			*file_analyser(int fd, int *nbr);
void			clean_matrice_from(char mat[20][20], t_piece *pieces,
				int value);
int				i_check_tetris(char mat[20][20], t_piece *tetris, t_pos *pos,
				int *size);
int				i_check_solution(int nb_pieces, int *size, t_piece *pieces,
				char mat[20][20]);
int				ft_sqrt(int nb);
void			initialize_matrice(char mat[20][20]);
void			print_matrice(char mat[20][20], int size);
int				next_position(char mat[20][20], t_piece *tetris, int *size);
int				ft_maximum(int a, int b, int c, int d);
#endif
