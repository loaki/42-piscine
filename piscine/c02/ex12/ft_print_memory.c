/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <jfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 11:38:01 by jfeuilla          #+#    #+#             */
/*   Updated: 2019/09/04 12:19:17 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_hexa_address(int nb, int size)
{
	char hexa;
	char *base;

	if (nb / 16 || size > 1)
		ft_hexa_address(nb / 16, size - 1);
	base = "0123456789abcdef";
	hexa = base[nb % 16];
	ft_putchar(hexa);
}

void	ft_hexa_char(unsigned char *addr, unsigned int limit)
{
	unsigned int	i;
	unsigned int	j;
	char			*base;

	base = "0123456789abcdef";
	i = 0;
	while (i < 16)
	{
		if (i < limit)
		{
			j = addr[i];
			ft_putchar(base[j / 16]);
			ft_putchar(base[j % 16]);
		}
		else
		{
			write(1, "  ", 2);
		}
		if (i % 2)
			ft_putchar(' ');
		i++;
	}
}

void	ft_print_char(unsigned char *addr, unsigned int limit)
{
	unsigned int i;

	i = 0;
	while (i < 16 && i < limit)
	{
		if (addr[i] >= 32 && addr[i] <= 126)
			ft_putchar(addr[i]);
		else
			ft_putchar('.');
		i++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int lines;
	unsigned int s;
	unsigned int limit;

	s = size;
	lines = 0;
	if (!(size / 16))
		s++;
	while (lines < s)
	{
		limit = size - lines;
		ft_hexa_address((int)(addr + lines), 15);
		write(1, ":", 1);
		write(1, " ", 1);
		ft_hexa_char((unsigned char *)(addr + lines), limit);
		ft_print_char((unsigned char *)(addr + lines), limit);
		ft_putchar('\n');
		lines = lines + 16;
	}
	return (addr);
}
