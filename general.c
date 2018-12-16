/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 13:34:44 by frivaton          #+#    #+#             */
/*   Updated: 2018/12/16 11:25:29 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				ft_sqrt(int nb)
{
	int nb1;
	int nb2;

	if (nb <= 0)
		return (0);
	if (nb == 1)
		return (1);
	nb1 = nb;
	while (nb1 > 1)
	{
		nb2 = (nb1 + (nb / nb1)) / 2;
		if ((nb2 * nb2) == nb)
			return (nb2);
		if (nb2 >= nb1)
			return (0);
		nb1 = nb2;
	}
	return (0);
}

void			initialize_matrice(char mat[20][20])
{
	int i;
	int j;

	j = 0;
	while (j < 20)
	{
		i = 0;
		while (i < 20)
		{
			mat[i][j] = 0;
			i++;
		}
		j++;
	}
}

void			print_matrice(char mat[20][20], int size)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (mat[i][j])
			{
				ft_putchar(mat[i][j]);
			}
			else
				ft_putchar('.');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int				next_position(char mat[20][20], t_piece *tetris, int *size)
{
	clean_matrice_from(mat, tetris, tetris->letter);
	(*size)++;
	tetris->posx = 0;
	tetris->posy = 0;
	return (1);
}
