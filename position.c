/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 13:34:25 by frivaton          #+#    #+#             */
/*   Updated: 2018/12/16 10:43:48 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void				clean_matrice_from(char mat[20][20], t_piece *pieces, int value)
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
		while (i < 26)
		{
			pieces[i].posx = 0;
			pieces[i].posy = 0;
			i++;
		}
	}
}

static int			i_clone_matrice(char mat[20][20], t_piece *pieces, t_pos *pos)
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
				mat[pos->y + i][pos->x + j] = pieces->tab[i][j];
			j++;
		}
		i++;
	}
	pieces->posx = pos->x;
	pieces->posy = pos->y;
	return (1);
}

static int			i_touch_tetris(char mat[20][20], t_piece *pieces, t_pos *pos, int *size)
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
			if (pieces->tab[i][j] && ((pos->y + i) >= *size ||
						(pos->x + j) >= *size))
				i_touch = 2;
			else if (pieces->tab[i][j] && mat[pos->y + i][pos->x + j])
				i_touch = 1;
			j++;
		}
		i++;
	}
	return (i_touch);
}

int					i_check_tetris(char mat[20][20], t_piece *pieces, t_pos *pos, int *size)
{
	int i_touch;
	int ret;

	i_touch = i_touch_tetris(mat, pieces, pos, size);
	if (!i_touch)
	{
		ret = i_clone_matrice(mat, pieces, pos);
		return (ret);
	}
	if (pos->x < *size - 1)
		pos->x = pos->x + 1;
	else if (pos->y < *size - 1)
	{
		pos->x = 0;
		pos->y = pos->y + 1;
	}
	else
		return (0);
	return (i_check_tetris(mat, pieces, pos, size));
}
