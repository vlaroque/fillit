/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:16:25 by frivaton          #+#    #+#             */
/*   Updated: 2018/12/14 12:39:08 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

extern int		g_mat[106][106];
extern t_piece	g_tetris[26];
extern int		g_nb_piece;
//extern int		g_x_max;
//extern int		g_y_max;
int				g_xstart;
int				g_ystart;
int				g_k;

static void			make_iter(int *x_max, int *y_max)
{
	g_xstart = g_tetris[g_k].posx;
	g_ystart = g_tetris[g_k].posy;
	clean_matrice_from(g_tetris[g_k].letter);
	if (g_xstart < *x_max - 1)
		g_xstart++;
	else if (g_ystart < *y_max - 1)
	{
		g_xstart = 0;
		g_ystart++;
	}
	else
	{
		g_xstart = 0;
		g_ystart = 0;
		next_position(&g_tetris[g_k], x_max, y_max);
	}
}

static void			make_move(int *x_max, int *y_max)
{
	if (g_k == 0)
	{
		g_xstart = 0;
		g_ystart = 0;
		next_position(&g_tetris[g_k], x_max, y_max);
		return ;
	}
	if (g_k)
		g_k--;
	make_iter(x_max, y_max);
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
	int x_max;
	int y_max;

	g_k = 0;
	g_xstart = 0;
	g_ystart = 0;
	x_max = 0;
	y_max = 0;
	ret = 1;
	while (1)
	{
		while (g_k < g_nb_piece)
		{
			while ((ret = i_check_tetris(&g_tetris[g_k], &g_xstart, &g_ystart, &x_max, &y_max)))
			{
				make_init();
				if (g_k == g_nb_piece && ret)
					break ;
			}
			if (g_k == g_nb_piece && ret)
			{
				print_matrice(x_max, y_max);
				return (1);
			}
			if (!ret)
				make_move(&x_max, &y_max);
		}
	}
	//printf("---------------val(%d)(%d)\n", x_max, y_max);
	//print_matrice(x_max, y_max);
	return (1);
}
