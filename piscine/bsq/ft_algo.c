/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 23:27:47 by jfeuilla          #+#    #+#             */
/*   Updated: 2019/09/18 19:02:19 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_checksymb(t_data *p_data, int *a)
{
	if (*a == p_data->symbole[0])
		*a = 1;
	else if (*a == p_data->symbole[1])
		*a = 0;
	else
		return (ERREUR_SYMB);
	return (SUCCESS);
}

void	ft_max(t_data *p_data, int b, int x, int y)
{
	if (b > p_data->max)
	{
		p_data->max = b;
		p_data->x_max = x;
		p_data->y_max = y;
	}
}

int		ft_calculb(t_data *p_data, int a, int b, int x)
{
	if (p_data->calcul[x - 1] <= p_data->calcul[x] &&
			p_data->calcul[x - 1] <= a)
	{
		b = p_data->calcul[x - 1] + 1;
		return (b);
	}
	if (p_data->calcul[x] <= p_data->calcul[x - 1] &&
			p_data->calcul[x] <= a)
	{
		b = p_data->calcul[x] + 1;
		return (b);
	}
	return (a + 1);
}

void	ft_square(t_data *p_data, int *a, int *b, int x)
{
	if (*b != 0)
		*b = ft_calculb(p_data, *a, *b, x);
	p_data->calcul[x - 1] = *a;
	*a = *b;
}

int		ft_algo2(t_data *p_data, int *b, char *c)
{
	if ((ft_lire_buffer(c, p_data) < 1) || *c == '\n')
		return (TAMERE);
	*b = (int)*c;
	if (*b == '\n')
		return (ERREUR_LIGNE);
	if (ft_checksymb(p_data, b) == ERREUR_SYMB)
		return (ERREUR_SYMB);
	return (SUCCESS);
}

void	ft_max2(t_data *p_data, char c, int y)
{
	if (c == p_data->symbole[0] && p_data->max == 0)
	{
		p_data->max = 1;
		p_data->x_max = 0;
		p_data->y_max = y;
	}
}

int		ft_algo(t_data *p_data, int y)
{
	int		x;
	int		a;
	int		b;
	char	c;

	while (++y < p_data->nb_ligne)
	{
		x = 0;
		if (((ft_lire_buffer(&c, p_data) < 1) || c == '\n'))
			return (TAMERE);
		ft_max2 (p_data, c , y);
		a = (int)c;
		if (ft_checksymb(p_data, &a) == ERREUR_SYMB)
			return (ERREUR_SYMB);
		while (++x < p_data->size_l)
		{
			if (ft_algo2(p_data, &b, &c) != SUCCESS)
				return (ERREUR_SYMB);
			ft_square(p_data, &a, &b, x);
			ft_max(p_data, b, x, y);
		}
		p_data->calcul[x - 1] = b;
		if ((ft_lire_buffer(&c, p_data) < 1) || c != '\n')
			return (TAMERE);
	}
	return (SUCCESS);
}
