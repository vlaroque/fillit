/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:16:25 by frivaton          #+#    #+#             */
/*   Updated: 2018/12/15 13:49:11 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

extern int			g_mat[20][20];
extern t_piece		g_tetris[26];
int					g_k;

static void			make_iter(int *size, int *xstart, int *ystart, int nb_pieces)
{
	*xstart = g_tetris[g_k].posx;
	*ystart = g_tetris[g_k].posy;
	clean_matrice_from(g_tetris[g_k].letter, nb_pieces);
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
		next_position(&g_tetris[g_k], size, nb_pieces);
	}
}

static void			make_move(int *size, int *xstart, int *ystart, int nb_pieces)
{
	if (g_k == 0)
	{
		*xstart = 0;
		*ystart = 0;
		next_position(&g_tetris[g_k], size, nb_pieces);
		return ;
	}
	if (g_k)
		g_k--;
	make_iter(size, xstart, ystart, nb_pieces);
}

static void			make_init(int *xstart, int *ystart)
{
	g_tetris[g_k].posx = *xstart;
	g_tetris[g_k].posy = *ystart;
	*xstart = 0;
	*ystart = 0;
	g_k++;
}

int					i_check_solution(int nb_pieces, int size)
{
	int ret;
	int xstart;
	int ystart;

	g_k = 0;
	xstart = 0;
	ystart = 0;
	ret = 1;
	while (1)
	{
		while (g_k < nb_pieces)
		{
			while ((ret = i_check_tetris(&g_tetris[g_k], &xstart, &ystart, &size)))
			{
				make_init(&xstart, &ystart);
				if (g_k == nb_pieces && ret)
					break ;
			}
			if (g_k == nb_pieces && ret)
			{
				print_matrice(size);
				return (1);
			}
			if (!ret)
				make_move(&size, &xstart, &ystart, nb_pieces);
		}
	}
	return (1);
}
