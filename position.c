/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 13:34:25 by frivaton          #+#    #+#             */
/*   Updated: 2018/12/15 18:36:10 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void				clean_matrice_from(char mat[20][20], t_piece *pieces, int value, int nb_pieces)
{
	int i;
	int j;

	j = 0;
	while (j < 20)
	{
		i = 0;
		while (i < 20)
		{
			if (mat[i][j] >= value)
				mat[i][j] = 0;
			i++;
		}
		j++;
	}
	if (value == 'A')
	{
		i = value - 'A';
		while (i < nb_pieces)
		{
			pieces[i].posx = 0;
			pieces[i].posy = 0;
			i++;
		}
	}
}

static int			i_clone_matrice(char mat[20][20], t_piece *pieces, int ref_col,
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
			if (pieces->tab[i][j])
				mat[ref_lin + i][ref_col + j] = pieces->tab[i][j];
			j++;
		}
		i++;
	}
	pieces->posx = ref_col;
	pieces->posy = ref_lin;
	return (1);
}

static int			i_touch_tetris(char mat[20][20], t_piece *pieces, int *ref_col,
					int *ref_lin, int *size)
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
			if (pieces->tab[i][j] && ((*ref_lin + i) >= *size ||
						(*ref_col + j) >= *size))
				i_touch = 2;
			else if (pieces->tab[i][j] && mat[*ref_lin + i][*ref_col + j])
				i_touch = 1;
			j++;
		}
		i++;
	}
	return (i_touch);
}

int					i_check_tetris(char mat[20][20], t_piece *pieces, int *ref_col,
					int *ref_lin, int *size)
{
	int i_touch;
	int ret;

	i_touch = i_touch_tetris(mat, pieces, ref_col, ref_lin, size);
	if (!i_touch)
	{
		ret = i_clone_matrice(mat, pieces, *ref_col, *ref_lin);
		return (ret);
	}
	if (*ref_col < *size - 1)
		*ref_col = *ref_col + 1;
	else if (*ref_lin < *size - 1)
	{
		*ref_col = 0;
		*ref_lin = *ref_lin + 1;
	}
	else
		return (0);
	return (i_check_tetris(mat, pieces, ref_col, ref_lin, size));
}
