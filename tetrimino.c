/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrimino.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 12:06:19 by vlaroque          #+#    #+#             */
/*   Updated: 2018/12/16 11:32:25 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_tetrimino_tab(int *tetri)
{
	tetri[0] = 100011011;
	tetri[1] = 100102030;
	tetri[2] = 100010203;
	tetri[3] = 101021011;
	tetri[4] = 100101121;
	tetri[5] = 100011112;
	tetri[6] = 101101120;
	tetri[7] = 100102021;
	tetri[8] = 100010210;
	tetri[9] = 100011121;
	tetri[10] = 102101112;
	tetri[11] = 101112021;
	tetri[12] = 100101112;
	tetri[13] = 100011020;
	tetri[14] = 100010212;
	tetri[15] = 100010211;
	tetri[16] = 101101121;
	tetri[17] = 101101112;
	tetri[18] = 100101120;
	return (tetri);
}

int		ft_num(int nbr, char position)
{
	while (7 - position > 0)
	{
		nbr = nbr / 10;
		position++;
	}
	return (nbr % 10);
}

int		ft_sqrt_plus(int nbr)
{
	long long	root;

	if (nbr < 0)
		return (0);
	root = 0;
	while (root * root <= (long long)nbr)
	{
		if (root * root == nbr)
			return (root);
		root++;
	}
	return (root);
}
