/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 13:34:25 by frivaton          #+#    #+#             */
/*   Updated: 2018/12/14 12:41:06 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

extern int		g_mat[106][106];
extern t_piece	g_tetris[26];
extern int		g_nb_piece;

void				clean_matrice_from(int value)
{
	int i;
	int j;

	j = 0;
	while (j < 106)
	{
		i = 0;
		while (i < 106)
		{
			if (g_mat[i][j] >= value)
				g_mat[i][j] = 0;
			i++;
		}
		j++;
	}
	if (value == 'A')
	{
		i = value - 'A';
		while (i < g_nb_piece)
		{
			g_tetris[i].posx = 0;
			g_tetris[i].posy = 0;
			i++;
		}
	}
}

static int			i_clone_matrice(t_piece *g_tetris, int ref_col,
						int ref_lin)
{
	int i;
	int j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (g_tetris->tab[i][j])
				g_mat[ref_lin + i][ref_col + j] = g_tetris->tab[i][j];
			j++;
		}
		i++;
	}
	g_tetris->posx = ref_col;
	g_tetris->posy = ref_lin;
	return (1);
}

static int			i_touch_tetris(t_piece *g_tetris, int *ref_col,
					int *ref_lin, int *x_max, int *y_max)
{
	int i;
	int j;
	int i_touch;

	i = 0;
	i_touch = 0;
	while (i < 4 && !i_touch)
	{
		j = 0;
		while (j < 4 && !i_touch)
		{
			if (g_tetris->tab[i][j] && ((*ref_lin + i) >= *x_max ||
						(*ref_col + j) >= *y_max))
				i_touch = 2;
			else if (g_tetris->tab[i][j] && g_mat[*ref_lin + i][*ref_col + j])
				i_touch = 1;
			j++;
		}
		i++;
	}
	return (i_touch);
}

int					i_check_tetris(t_piece *g_tetris, int *ref_col,
					int *ref_lin, int *x_max, int *y_max)
{
	int i_touch;
	int ret;

	i_touch = i_touch_tetris(g_tetris, ref_col, ref_lin, x_max, y_max);
	if (!i_touch)
	{
		ret = i_clone_matrice(g_tetris, *ref_col, *ref_lin);
		return (ret);
	}
	if (*ref_col < *x_max - 1)
		*ref_col = *ref_col + 1;
	else if (*ref_lin < *y_max - 1)
	{
		*ref_col = 0;
		*ref_lin = *ref_lin + 1;
	}
	else
		return (0);
	return (i_check_tetris(g_tetris, ref_col, ref_lin, x_max, y_max));
}
