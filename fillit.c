/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 13:16:36 by vlaroque          #+#    #+#             */
/*   Updated: 2018/12/16 11:59:46 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		determine_square_min(int nb_pieces)
{
	int		val;
	int		i;
	int		tmp;

	tmp = nb_pieces * 4;
	val = ft_sqrt(tmp);
	if (!val)
	{
		i = 1;
		while (!val)
		{
			val = ft_sqrt(tmp + i);
			i++;
		}
	}
	return (val);
}

int				main(int ac, char **av)
{
	int		fd;
	int		nb_pieces;
	int		size;
	t_piece	*res;
	char	mat[20][20];

	if (ac != 2)
		ft_putstr("usage: fillit [filename]\n");
	fd = open(av[1], O_RDONLY);
	if (fd <= 0 || !(res = file_analyser(fd, &nb_pieces)))
	{
		ft_putstr("error\n");
		return (0);
	}
	initialize_matrice(mat);
	size = determine_square_min(nb_pieces);
	if (!(size = i_check_solution(nb_pieces, &size, res, mat)))
	{
		ft_putstr("error\n");
		return (0);
	}
	print_matrice(mat, size);
	close(fd);
	free(res);
	return (0);
}
