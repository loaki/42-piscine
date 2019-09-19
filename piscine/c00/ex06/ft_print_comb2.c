/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <jfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 13:31:46 by jfeuilla          #+#    #+#             */
/*   Updated: 2019/08/29 00:30:13 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char a, char b)
{
	char ad;
	char au;
	char bd;
	char bu;

	ad = '0' + a / 10;
	au = '0' + a % 10;
	bd = '0' + b / 10;
	bu = '0' + b % 10;
	write(1, &ad, 1);
	write(1, &au, 1);
	write(1, " ", 1);
	write(1, &bd, 1);
	write(1, &bu, 1);
	if (a != 98)
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb2(void)
{
	int a;
	int b;

	a = 0;
	b = 0;
	while (a < 99)
	{
		b = a + 1;
		while (b < 100)
		{
			ft_putchar(a, b);
			b++;
		}
		a++;
	}
}
