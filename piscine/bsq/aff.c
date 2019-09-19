/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:37:04 by jfeuilla          #+#    #+#             */
/*   Updated: 2019/09/18 23:08:37 by karmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	putnbr(int n)
{
	char c;

	if (n >= 10)
		putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

void	ft_stock(t_data *p_data, unsigned int a)
{
	p_data->stock[p_data->j] += a * p_data->p;
	if (p_data->p != 2147483648)
		p_data->p *= 2;
	else
	{
		p_data->p = 1;
		(p_data->j)++;
	}
}

int		ft_lire_buffer(char *c, t_data *p_data)
{
	if (p_data->i == p_data->size_b)
	{
		p_data->size_b = read(p_data->fd, &(p_data->buffer), SIZE_BUFF);
		p_data->i = 0;
	}
	*c = p_data->buffer[p_data->i];
	if (*c == p_data->symbole[0])
		ft_stock(p_data, 0);
	else if (*c == p_data->symbole[1])
		ft_stock(p_data, 1);
	(p_data->i)++;
	return (p_data->size_b);
}

int		ft_test_aff(t_data *p_data, int x, int y)
{
	if (x <= p_data->x_max && x > p_data->x_max - p_data->max)
		if (y <= p_data->y_max && y > p_data->y_max - p_data->max)
			return (1);
	return (0);
}

void	ft_remplir(t_data *p_data, char c)
{
	if (p_data->i == SIZE_BUFF)
	{
		write(1, &(p_data->buffer), SIZE_BUFF);
		p_data->i = 0;
	}
	p_data->buffer[p_data->i] = c;
	(p_data->i)++;
}

int		ft_aff(t_data *p_data)
{
	int i;
	int x;
	int y;
	int k;
	int vrai;

	vrai = 1;
	y = 0;
	x = 0;
	i = -1;
	p_data->i = 0;
	while (vrai && ++i != -2)
	{
		k = 0;
		while (vrai && k < 32)
		{
			if (ft_test_aff(p_data, x, y))
				ft_remplir(p_data, (p_data->symbole[2]));
			else
				ft_remplir(p_data, (p_data->symbole[p_data->stock[i] % 2]));
			k++;
			p_data->stock[i] /= 2;
			x++;
			if (x == p_data->size_l)
			{
				ft_remplir(p_data, '\n');
				x = 0;
				y++;
				if (y == p_data->nb_ligne)
					vrai = 0;
			}
		}
	}
	write(1, &(p_data->buffer), p_data->i);
	return (0);
}
