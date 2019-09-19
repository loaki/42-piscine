/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ini.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 16:59:09 by jfeuilla          #+#    #+#             */
/*   Updated: 2019/09/08 17:00:46 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librush.h"

void	ft_zerotab(int tab[6][6])
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < 6)
	{
		while (j < 6)
		{
			tab[i][j] = 0;
			j++;
		}
		j = 0;
		i++;
	}
}

int		ft_checkarg(int ac, char **av)
{
	int i;

	i = 0;
	if (ac != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	while (av[1][i])
	{
		if (i % 2 == 0)
		{
			if (av[1][i] < '1' || av[1][i] > '4')
			{
				write(1, "Error\n", 6);
				return (0);
			}
		}
		i++;
	}
	return (1);
}

int		ft_checkarg2(char **av)
{
	int i;

	i = 0;
	while (av[1][i])
	{
		if (i % 2 != 0)
		{
			if (av[1][i] != ' ')
			{
				write(1, "Error\n", 6);
				return (0);
			}
		}
		i++;
	}
	if (i != 31)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (1);
}

void	ft_initab(int tab[6][6], char **av)
{
	tab[0][1] = av[1][0] - 48;
	tab[0][2] = av[1][2] - 48;
	tab[0][3] = av[1][4] - 48;
	tab[0][4] = av[1][6] - 48;
	tab[5][1] = av[1][8] - 48;
	tab[5][2] = av[1][10] - 48;
	tab[5][3] = av[1][12] - 48;
	tab[5][4] = av[1][14] - 48;
	tab[1][0] = av[1][16] - 48;
	tab[2][0] = av[1][18] - 48;
	tab[3][0] = av[1][20] - 48;
	tab[4][0] = av[1][22] - 48;
	tab[1][5] = av[1][24] - 48;
	tab[2][5] = av[1][26] - 48;
	tab[3][5] = av[1][28] - 48;
	tab[4][5] = av[1][30] - 48;
}
