/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:16:25 by frivaton          #+#    #+#             */
/*   Updated: 2018/12/15 17:19:58 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//extern t_piece		g_tetris[26];
int					g_k;

static void			make_iter(int mat[20][20], t_piece *pieces, int *size, int *xstart, int *ystart, int nb_pieces)
{
	*xstart = pieces[g_k].posx;
	*ystart = pieces[g_k].posy;
	clean_matrice_from(mat, pieces, pieces[g_k].letter, nb_pieces);
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
		next_position(mat, &pieces[g_k], size, nb_pieces);
	}
}

static void			make_move(int mat[20][20], t_piece *pieces, int *size, int *xstart, int *ystart, int nb_pieces)
{
	if (g_k == 0)
	{
		*xstart = 0;
		*ystart = 0;
		next_position(mat, &pieces[g_k], size, nb_pieces);
		return ;
	}
	if (g_k)
		g_k--;
	make_iter(mat, pieces, size, xstart, ystart, nb_pieces);
}

static void			make_init(t_piece *pieces ,int *xstart, int *ystart)
{
	pieces[g_k].posx = *xstart;
	pieces[g_k].posy = *ystart;
	*xstart = 0;
	*ystart = 0;
	g_k++;
}

int					i_check_solution(int nb_pieces, int size, t_piece *pieces)
{
	int	ret;
	int	xstart;
	int	ystart;
	int	mat[20][20];

	g_k = 0;
	xstart = 0;
	ystart = 0;
	ret = 1;
	initialize_matrice(mat);
	while (1)
	{
		while (g_k < nb_pieces)
		{
			while ((ret = i_check_tetris(mat, &pieces[g_k], &xstart, &ystart, &size)))
			{
				make_init(pieces, &xstart, &ystart);
				if (g_k == nb_pieces && ret)
					break ;
			}
			if (g_k == nb_pieces && ret)
			{
				print_matrice(mat, size);
				return (1);
			}
			if (!ret)
				make_move(mat, pieces, &size, &xstart, &ystart, nb_pieces);
		}
	}
	return (1);
}
