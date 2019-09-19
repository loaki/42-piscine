/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_op.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 15:33:01 by jfeuilla          #+#    #+#             */
/*   Updated: 2019/09/15 15:53:19 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

int		ft_atoi(char *str)
{
	int nb;
	int i;
	int s;

	s = 1;
	nb = 0;
	i = 0;
	while ((str[i] == 32) || (str[i] == 12) || (str[i] == 10) ||
			(str[i] == 13) || (str[i] == 9) || (str[i] == 11))
	{
		i++;
	}
	while ((str[i] == 45) || (str[i] == 43))
	{
		if (str[i] == 45)
			s = s * -1;
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		nb = nb * 10 + str[i] - 48;
		i++;
	}
	return (nb * s);
}

int		ft_check(char **av)
{
	if ((av[2][0] != '+') && (av[2][0] != '-') && (av[2][0] != '*') &&
			(av[2][0] != '/') && (av[2][0] != '%'))
	{
		ft_putnbr(0);
		return (0);
	}
	if (av[2][1] != '\0')
		return (0);
	if ((av[2][0] == '/') && (ft_atoi(av[3]) == 0))
	{
		write(1, "Stop : division by zero", 23);
		return (0);
	}
	if ((av[2][0] == '%') && (ft_atoi(av[3]) == 0))
	{
		write(1, "Stop : modulo by zero", 21);
		return (0);
	}
	return (1);
}

int		main(int ac, char **av)
{
	if (ac != 4)
		return (0);
	if (ft_check(av) != 1)
	{
		write(1, "\n", 1);
		return (0);
	}
	if (av[2][0] == '+')
		ft_putnbr(ft_atoi(av[1]) + ft_atoi(av[3]));
	else if (av[2][0] == '-')
		ft_putnbr(ft_atoi(av[1]) - ft_atoi(av[3]));
	else if (av[2][0] == '/')
		ft_putnbr(ft_atoi(av[1]) / ft_atoi(av[3]));
	else if (av[2][0] == '*')
		ft_putnbr(ft_atoi(av[1]) * ft_atoi(av[3]));
	else if (av[2][0] == '%')
		ft_putnbr(ft_atoi(av[1]) % ft_atoi(av[3]));
	write(1, "\n", 1);
	return (0);
}
