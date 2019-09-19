/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <jfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 17:21:28 by jfeuilla          #+#    #+#             */
/*   Updated: 2019/08/29 11:19:30 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char a)
{
	write(1, &a, 1);
}

void	ft_return(int *t, int n)
{
	char c;

	n--;
	while (n >= 0)
	{
		c = '0' + *(t + n);
		ft_putchar(c);
		n--;
	}
}

void	ft_incremente(int *t, int n, int i)
{
	if (t[i] < 9 - i)
	{
		t[i] = t[i] + 1;
		while (i > 0)
		{
			t[i - 1] = t[i] + 1;
			i--;
		}
	}
	else
	{
		i++;
		ft_incremente(t, n, i);
	}
}

void	ft_ini(int *t, int n)
{
	t[n - 1] = 0;
	n--;
	while (n > 0)
	{
		t[n - 1] = t[n] + 1;
		n--;
	}
}

void	ft_print_combn(int n)
{
	int tab[n];

	ft_ini(tab, n);
	while (tab[n - 1] != 10 - n)
	{
		ft_return(tab, n);
		ft_incremente(tab, n, 0);
		write(1, ", ", 2);
	}
	ft_return(tab, n);
}
