/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:16:25 by frivaton          #+#    #+#             */
/*   Updated: 2018/12/15 19:20:03 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void			make_iter(char mat[20][20], t_piece *pieces, int *az, int *size, int *xstart, int *ystart, int nb_pieces)
{
	*xstart = pieces[*az].posx;
	*ystart = pieces[*az].posy;
	clean_matrice_from(mat, pieces, pieces[*az].letter, nb_pieces);
	if (*xstart < *size - 1)
		(*xstart)++;
	else if (*ystart < *size - 1)
	{
		*xstart = 0;
		(*ystart)++;
	}
	else
	{
		*xstart = 0;
		*ystart = 0;
		next_position(mat, &pieces[*az], size, nb_pieces);
	}
}

static void			make_move(char mat[20][20], t_piece *pieces, int *az, int *size, int *xstart, int *ystart, int nb_pieces)
{
	if (*az == 0)
	{
		*xstart = 0;
		*ystart = 0;
		next_position(mat, &pieces[*az], size, nb_pieces);
		return ;
	}
	if (*az)
		(*az)--;
	make_iter(mat, pieces, az, size, xstart, ystart, nb_pieces);
}

static void			make_init(t_piece *pieces, int *az, int *xstart, int *ystart)
{
	pieces[*az].posx = *xstart;
	pieces[*az].posy = *ystart;
	*xstart = 0;
	*ystart = 0;
	(*az)++;
}

int					i_check_solution(int nb_pieces, int size, t_piece *pieces)
{
	int		ret;
	int		xstart;
	int		ystart;
	char	mat[20][20];
	int		az;

	az = 0;
	xstart = 0;
	ystart = 0;
	ret = 1;
	initialize_matrice(mat);
	while (1)
	{
		while (az < nb_pieces)
		{
			while ((ret = i_check_tetris(mat, &pieces[az], &xstart, &ystart, &size)))
			{
				make_init(pieces, &az, &xstart, &ystart);
				if (az == nb_pieces && ret)
					break ;
			}
			if (az == nb_pieces && ret)
			{
				print_matrice(mat, size);
				return (1);
			}
			if (!ret)
				make_move(mat, pieces, &az, &size, &xstart, &ystart, nb_pieces);
		}
	}
	return (1);
}
