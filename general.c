/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   general.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 13:34:44 by frivaton          #+#    #+#             */
/*   Updated: 2018/12/14 12:50:49 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

extern int		g_mat[106][106];
extern t_piece	g_tetris[26];
extern int		g_nb_piece;

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

void			clean_tetris(void)
{
	int	i;
	int k;
	int j;

	i = 0;
	while (i < 26)
	{
		g_tetris[i].letter = 0;
		g_tetris[i].posx = 0;
		g_tetris[i].posy = 0;
		k = 0;
		while (k < 4)
		{
			j = 0;
			while (j < 4)
			{
				g_tetris[i].tab[k][j] = 0;
				j++;
			}
			k++;
		}
		i++;
	}
}

void			initialize_matrice(void)
{
	int i;
	int j;

	j = 0;
	while (j < 106)
	{
		i = 0;
		while (i < 106)
		{
			g_mat[i][j] = 0;
			i++;
		}
		j++;
	}
}

void			print_matrice(int x_max, int y_max)
{
	int i;
	int j;

	i = 0;
	while (i < x_max)
	{
		j = 0;
		while (j < y_max)
		{
			if (g_mat[i][j])
			{
				ft_putchar(g_mat[i][j]);
			}
			else
				ft_putchar('.');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

int				next_position(t_piece *tetris, int *x_max, int *y_max)
{
	clean_matrice_from(tetris->letter);
	(*x_max)++;
	(*y_max)++;
	tetris->posx = 0;
	tetris->posy = 0;
	return (1);
}
