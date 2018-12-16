/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:16:25 by frivaton          #+#    #+#             */
/*   Updated: 2018/12/16 10:43:47 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void			make_iter(char mat[20][20], t_piece *pieces, int *az, int *size, t_pos *pos)
{
	pos->x = pieces[*az].posx;
	pos->y = pieces[*az].posy;
	clean_matrice_from(mat, pieces, pieces[*az].letter);
	if (pos->x < *size - 1)
		(pos->x)++;
	else if (pos->y < *size - 1)
	{
		pos->x = 0;
		(pos->y)++;
	}
	else
	{
		pos->x = 0;
		pos->y = 0;
		next_position(mat, &pieces[*az], size);
	}
}

static void			make_move(char mat[20][20], t_piece *pieces, int *az, int *size, t_pos *pos)
{
	if (*az == 0)
	{
		pos->y = 0;
		pos->x = 0;
		next_position(mat, &pieces[*az], size);
		return ;
	}
	if (*az)
		(*az)--;
	make_iter(mat, pieces, az, size, pos);
}

static void			make_init(t_piece *pieces, int *az, t_pos *pos)
{
	pieces[*az].posx = pos->x;
	pieces[*az].posy = pos->y;
	pos->x = 0;
	pos->y = 0;
	(*az)++;
}

int					i_check_solution(int nb_pieces, int size, t_piece *pieces)
{
	int		ret;
	t_pos	pos;
	char	mat[20][20];
	int		az;

	az = 0;
	pos.x = 0;
	pos.y = 0;
	ret = 1;
	initialize_matrice(mat);
	while (1)
	{
		while (az < nb_pieces)
		{
			while ((ret = i_check_tetris(mat, &pieces[az], &pos, &size)))
			{
				make_init(pieces, &az, &pos);
				if (az == nb_pieces && ret)
					break ;
			}
			if (az == nb_pieces && ret)
			{
				print_matrice(mat, size);
				return (1);
			}
			if (!ret)
				make_move(mat, pieces, &az, &size, &pos);
		}
	}
	return (1);
}
