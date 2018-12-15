/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:16:25 by frivaton          #+#    #+#             */
/*   Updated: 2018/12/15 11:25:24 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

extern int			g_mat[106][106];
extern t_piece		g_tetris[26];
extern int			g_nb_piece;
int					g_xstart;
int					g_ystart;
int					g_k;

static void			make_iter(int *size)
{
	g_xstart = g_tetris[g_k].posx;
	g_ystart = g_tetris[g_k].posy;
	clean_matrice_from(g_tetris[g_k].letter);
	if (g_xstart < *size - 1)
		g_xstart++;
	else if (g_ystart < *size - 1)
	{
		g_xstart = 0;
		g_ystart++;
	}
	else
	{
		g_xstart = 0;
		g_ystart = 0;
		next_position(&g_tetris[g_k], size);
	}
}

static void			make_move(int *size)
{
	if (g_k == 0)
	{
		g_xstart = 0;
		g_ystart = 0;
		next_position(&g_tetris[g_k], size);
		return ;
	}
	if (g_k)
		g_k--;
	make_iter(size);
}

static void			make_init(void)
{
	g_tetris[g_k].posx = g_xstart;
	g_tetris[g_k].posy = g_ystart;
	g_xstart = 0;
	g_ystart = 0;
	g_k++;
}

int					i_check_solution(void)
{
	int ret;
	int size;

	g_k = 0;
	g_xstart = 0;
	g_ystart = 0;
	size = 0;
	ret = 1;
	while (1)
	{
		while (g_k < g_nb_piece)
		{
			while ((ret = i_check_tetris(&g_tetris[g_k], &g_xstart, &g_ystart, &size)))
			{
				make_init();
				if (g_k == g_nb_piece && ret)
					break ;
			}
			if (g_k == g_nb_piece && ret)
			{
				print_matrice(size);
				return (1);
			}
			if (!ret)
				make_move(&size);
		}
	}
	return (1);
}
