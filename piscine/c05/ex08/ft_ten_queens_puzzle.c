/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 19:39:22 by jfeuilla          #+#    #+#             */
/*   Updated: 2019/09/06 11:51:29 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_print_table(int *tab)
{
	int i;

	i = 0;
	while (i < 10)
	{
		ft_putchar(tab[i] + '0');
		i++;
	}
	ft_putchar('\n');
}

int		ft_queen_safe(int x, int y, int *tab)
{
	int i;

	i = 0;
	while (i < x)
	{
		if (tab[i] == y)
			return (0);
		else if (tab[i] - i == y - x)
			return (0);
		else if (tab[i] + i == x + y)
			return (0);
		i++;
	}
	return (1);
}

void	ft_backtrack(int tab[10], int *success, int x)
{
	int y;

	y = 0;
	if (x == 10)
	{
		ft_print_table(tab);
		*success = *success + 1;
	}
	while (y < 10)
	{
		if (ft_queen_safe(x, y, tab))
		{
			tab[x] = y;
			ft_backtrack(tab, success, x + 1);
		}
		y++;
	}
}

int		ft_ten_queens_puzzle(void)
{
	int tab[10];
	int success;

	success = 0;
	ft_backtrack(tab, &success, 0);
	return (success);
}
