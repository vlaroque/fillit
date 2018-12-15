/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_n_register.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 09:13:34 by vlaroque          #+#    #+#             */
/*   Updated: 2018/12/15 13:49:13 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdlib.h>

void	tetri_filler(t_piece *onepiece, int pce, int shape)
{
	int		pos;

	pos = -1;
	while (++pos < 16)
	{
		onepiece->tab[pos / 4][pos % 4] = 0;
	}
	onepiece->letter = 'A' + pce;
	onepiece->tab[ft_num(shape, 0)][ft_num(shape, 1)] = onepiece->letter;
	onepiece->tab[ft_num(shape, 2)][ft_num(shape, 3)] = onepiece->letter;
	onepiece->tab[ft_num(shape, 4)][ft_num(shape, 5)] = onepiece->letter;
	onepiece->tab[ft_num(shape, 6)][ft_num(shape, 7)] = onepiece->letter;
	onepiece->posx = 0;
	onepiece->posy = 0;
}

int		tetri_normaliser(int shape)
{
	int			tmp;
	int			i;
	int			tetri[19];

	i = 0;
	ft_tetrimino_tab(tetri);
	if ((tmp = ft_num(shape, 0)) > 0)
		shape = shape - (tmp * 10101010);
	while (ft_num(shape, 1) * ft_num(shape, 3) *
		ft_num(shape, 5) * ft_num(shape, 7))
		shape = shape - 1010101;
	while (i <= 18)
	{
		if (tetri[i] == shape)
			return (shape);
		i++;
	}
	return (0);
}

t_piece		*tetri_analyser(char *str, int count, t_piece *pieces)
{
	int		pce;
	int		i;
	int		pts;

	pce = -1;
	while (++pce < count)
	{
		i = -1;
		pts = 1;
		while (++i < 20)
		{
			if (str[pce * 21 + i] == '#')
			{
				if (pts > 100000000)
					return (NULL);
				pts = pts * 100 + ((i / 5) * 10) + (i % 5);
			}
		}
		if ((pts = tetri_normaliser(pts)) == 0)
			return (NULL);
		tetri_filler(&(pieces[pce]), pce, pts);
	}
	return (pieces);
}

int		file_parsing(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i + j])
	{
		if ((i + j) % 21 == 20)
			j++;
		else if (i % 20 == 19 && str[i + j] == '\n')
			i++;
		else if (i % 5 == 4 && str[i + j] == '\n')
			i++;
		else if (!(i % 5 == 4) && (str[i + j] == '.' || str[i + j] == '#'))
			i++;
		else
			return (0);
	}
	if (i % 20 == 0)
		return (j + 1);
	return (0);
}

t_piece		*file_analyser(int fd, int *nbr)
{
	//int			nbr;
	char		*str;
	int			rd;
	t_piece		*pieces;

	if (!(str = (char *)ft_memalloc(BUFF_SIZE)))
		return (0);
	if (!(pieces = (t_piece *)malloc(sizeof(t_piece) * 27)))
	{
		free(str);
		return (NULL);
	}
	ft_bzero(pieces, 27 * sizeof(t_piece));
	if (((rd = read(fd, str, BUFF_SIZE)) >= 546) || ((*nbr = file_parsing(str)) == 0))
	{
		ft_strdel(&str);
		ft_memdel((void *)&pieces);
		return (NULL);
	}
	if ((pieces = tetri_analyser(str, *nbr, pieces)) == NULL)
	{
		ft_strdel(&str);
		ft_memdel((void *)&pieces);
		return (NULL);
	}
	ft_strdel(&str);
	return (pieces);
}
