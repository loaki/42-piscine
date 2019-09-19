/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <jfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 23:11:00 by jfeuilla          #+#    #+#             */
/*   Updated: 2019/08/28 15:16:46 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char a)
{
	write(1, &a, 1);
}

void	ft_putchainchar(char a, char b, char c)
{
	ft_putchar(a);
	ft_putchar(b);
	ft_putchar(c);
}

void	ft_return(char a, char b, char c)
{
	if (a == '7' && b == '8' && c == '9')
	{
		ft_putchainchar(a, b, c);
	}
	else
	{
		ft_putchainchar(a, b, c);
		write(1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	char a;
	char b;
	char c;

	a = '0';
	b = '0';
	c = '0';
	while (a < 56)
	{
		b = a + 1;
		while (b < 57)
		{
			c = b + 1;
			while (c < 58)
			{
				ft_return(a, b, c);
				c++;
			}
			b++;
		}
		a++;
	}
}
