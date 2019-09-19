/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <jfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 13:55:28 by jfeuilla          #+#    #+#             */
/*   Updated: 2019/09/01 13:11:06 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_base(char *tab)
{
	int i;

	i = 0;
	while (i <= 9)
	{
		tab[i] = '0' + i;
		i++;
	}
	while (i <= 15)
	{
		tab[i] = 87 + i;
		i++;
	}
	tab[i] = '\0';
}

void	ft_hexa(char c)
{
	unsigned int	d;
	unsigned int	u;
	unsigned int	a;
	unsigned char	k;
	char			tab[17];

	if (c < 0)
	{
		k = c;
		ft_base(tab);
		a = k;
		d = a / 16;
		u = a % 16;
		ft_putchar(tab[d]);
		ft_putchar(tab[u]);
	}
	else
	{
		ft_base(tab);
		a = c;
		d = a / 16;
		u = a % 16;
		ft_putchar(tab[d]);
		ft_putchar(tab[u]);
	}
}

void	ft_putstr_non_printable(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 32 || str[i] > 126)
		{
			ft_putchar('\\');
			ft_hexa(str[i]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}
