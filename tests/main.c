/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlaroque <vlaroque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 15:50:20 by vlaroque          #+#    #+#             */
/*   Updated: 2018/12/05 21:05:55 by vlaroque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

int main(void)
{
	int *tetri;
	int i;
	int j;
	char tab[] = "0123456789012345\0";

	i = 0;
	tetri = ft_tetrimino_tab(tetri);
	while (i <= 18)
	{
		j = 0;
		while(tab[j])
			tab[j++] = '.';
		tab[4 * ft_num(tetri[i], 0) + ft_num(tetri[i], 1)] = '#';
		tab[4 * ft_num(tetri[i], 2) + ft_num(tetri[i], 3)] = '#';
		tab[4 * ft_num(tetri[i], 4) + ft_num(tetri[i], 5)] = '#';
		tab[4 * ft_num(tetri[i], 6) + ft_num(tetri[i], 7)] = '#';
		i++;

		printf("%c %c %c %c\n", tab[0], tab[1], tab[2], tab[3]);
		printf("%c %c %c %c\n", tab[4], tab[5], tab[6], tab[7]);
		printf("%c %c %c %c\n", tab[8], tab[9], tab[10], tab[11]);
		printf("%c %c %c %c\n________\n", tab[12], tab[13], tab[14], tab[15]);
	}
	return (0);
}
