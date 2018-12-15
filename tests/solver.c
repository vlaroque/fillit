/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 14:25:42 by vlaroque          #+#    #+#             */
/*   Updated: 2018/12/11 11:37:41 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int pos_check_n_write(int size, int pos, int shape, short **tab)
{
	if ((tab[ / size] | ))
	return (0);
}

int pos_unwrite(int size, int pos, int shape, short **tab)
{
	return (0);
}

int			grid_solver(int size, short pos, t_tetri **tetri, short **tab)
{
	int		i;
	int		res;

	i = 0;
	while (tetri[i]->pos != 0)
		i++;
	if (tetri[i]->shape == 0)
		return (42);
	i = 0;
	while (tetri[i]->shape != 0 )
	{
		res = pos_check_n_write(size, pos, shape, tab);
		if (res == 1)
		{
			if (42 == grid_solver(size, pos++, tetri))
				return (42);
			pos_unwrite(size, pos, tetri);
		}
		i++;
	}
	if(42 == grid_solver(size, pos++, tetri))
		return(42);
	return(0);
}

t_tetri		**solver(t_tetri **tetri, int tetri_nbr_max)
{
	short	tab[16];
	int		res;
	int		size;

	size = ft_sqrt_plus(tetri_nbr_max * 4);
	res = 0;
	while (size <= 17 && res == 0)
	{
		res = grid_solver(size, 0, tetri, &tab);
		size++;
	}
	return (tetri);
}
