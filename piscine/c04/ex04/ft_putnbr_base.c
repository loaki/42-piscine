/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <jfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 19:53:00 by jfeuilla          #+#    #+#             */
/*   Updated: 2019/09/05 09:03:58 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_checkbase(char *base, int t)
{
	int i;
	int j;

	j = 0;
	i = 0;
	if (t < 2)
		return (0);
	while (base[i + 1])
	{
		j = i + 1;
		while (base[j])
		{
			if ((base[i] == base[j]) || (base[j] == 43) || (base[j] == 45))
				return (0);
			j++;
		}
		if ((base[i] == 43) || (base[i] == 45))
			return (0);
		i++;
	}
	return (1);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int		nb;
	unsigned int		base_length;

	base_length = ft_strlen(base);
	if (ft_checkbase(base, base_length) > 0)
	{
		if (nbr < 0)
		{
			nb = -nbr;
			ft_putchar('-');
		}
		else
			nb = nbr;
		if (nb >= base_length)
			ft_putnbr_base(nb / base_length, base);
		ft_putchar(base[nb % base_length]);
	}
}
