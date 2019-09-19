/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:28:24 by jfeuilla          #+#    #+#             */
/*   Updated: 2019/09/12 12:25:09 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <unistd.h>

void				ft_putchar(char c)
{
	write(1, &c, 1);
}

void				ft_putnbr(int nb)
{
	long int	n;

	n = nb;
	if (n < 0)
	{
		n = -n;
		ft_putchar('-');
	}
	if (n <= 9)
		ft_putchar(n + '0');
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

void				ft_show_tab(struct s_stock_str *par)
{
	int		i;
	int		j;

	i = 0;
	while (par[i].str != 0)
	{
		j = 0;
		while (par[i].str[j] != '\0')
		{
			ft_putchar(par[i].str[j]);
			j++;
		}
		ft_putchar('\n');
		ft_putnbr(par[i].size);
		ft_putchar('\n');
		j = 0;
		while (par[i].copy[j] != '\0')
		{
			ft_putchar(par[i].copy[j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
