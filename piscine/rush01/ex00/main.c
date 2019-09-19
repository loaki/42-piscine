/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 17:01:08 by jfeuilla          #+#    #+#             */
/*   Updated: 2019/09/08 17:02:29 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librush.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	unsigned int i;

	if (nb < 0)
	{
		ft_putchar('-');
		i = nb * -1;
	}
	else
		i = nb;
	if (i >= 10)
		ft_putnbr(i / 10);
	ft_putchar(i % 10 + '0');
}

void	ft_printtab(int tab[6][6])
{
	int i;
	int j;

	i = 1;
	j = 1;
	while (i < 5)
	{
		while (j < 5)
		{
			ft_putnbr(tab[i][j]);
			if (j != 4)
				ft_putchar(' ');
			j++;
		}
		write(1, "\n", 1);
		i++;
		j = 1;
	}
}

int		*ft_backtrack(int tab[6][6], int pos, int *x)
{
	int i;
	int j;
	int k;

	i = (pos / 4) + 1;
	j = (pos % 4) + 1;
	if (pos == 16 && ft_checkrowleft(tab, 0) == 1 &&
			ft_checkrowright(tab, 0) == 1 && ft_checkcolup(tab, 0) == 1 &&
			ft_checkcoldo(tab, 0) == 1 && *x == 0)
	{
		(*x)++;
		ft_printtab(tab);
	}
	k = 0;
	if (tab[i][j] == 0)
	{
		while (++k <= 4)
		{
			tab[i][j] = k;
			if (ft_checknbr(tab, pos) == 1)
				(ft_backtrack(tab, (pos + 1), x));
			tab[i][j] = 0;
		}
	}
	return (x);
}

int		main(int ac, char **av)
{
	int tab[6][6];
	int pos;
	int x;

	x = 0;
	pos = 0;
	if ((ft_checkarg(ac, av) == 0) || (ft_checkarg2(av) == 0))
		return (0);
	ft_zerotab(tab);
	ft_initab(tab, av);
	ft_backtrack(tab, pos, &x);
	if (x == 0)
		write(1, "Error\n", 6);
	return (0);
}
