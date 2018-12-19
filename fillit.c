/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 13:16:36 by vlaroque          #+#    #+#             */
/*   Updated: 2018/12/18 18:54:50 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		error(t_piece *res, int fd, int true_res)
{
	close(fd);
	if (true_res)
		free(res);
	ft_putstr("error\n");
	return (0);
}

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

	res = NULL;
	if (ac != 2)
		ft_putstr("usage: fillit [filename]\n");
	if ((fd = open(av[1], O_RDONLY)) <= 0)
		return (error(res, fd, 0));
	if (!(res = file_analyser(fd, &nb_pieces)))
		return (error(res, fd, 0));
	initialize_matrice(mat);
	size = determine_square_min(nb_pieces);
	if (!(size = i_check_solution(nb_pieces, &size, res, mat)))
		return (error(res, fd, 1));
	print_matrice(mat, size);
	close(fd);
	free(res);
	return (0);
}
