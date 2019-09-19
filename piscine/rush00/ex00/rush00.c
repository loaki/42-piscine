/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 14:50:58 by jfeuilla          #+#    #+#             */
/*   Updated: 2019/09/01 20:02:42 by bmassamb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	ft_printchar(int h, int l, int x, int y)
{
	if (h == 0 || h == y - 1 || l == 0 || l == x - 1)
	{
		if (h == 0 && l == 0)
			ft_putchar('o');
		else if (h == 0 && l == x - 1)
			ft_putchar('o');
		else if (h == y - 1 && l == 0)
			ft_putchar('o');
		else if (h == y - 1 && l == x - 1)
			ft_putchar('o');
		else if (h == 0 || h == y - 1)
			ft_putchar('-');
		else if (l == 0 || l == x - 1)
			ft_putchar('|');
	}
	else
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int h;
	int l;

	h = 0;
	l = 0;
	if (x < -1000 || x > 1000 || y < -1000 || y > 1000)
		write(1, "bien essaye, petit malin", 24);
	else
	{
		while (h < y && x > 0)
		{
			while (l < x)
			{
				ft_printchar(h, l, x, y);
				l++;
			}
			l = 0;
			ft_putchar('\n');
			h++;
		}
	}
}
