/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 21:01:47 by jfeuilla          #+#    #+#             */
/*   Updated: 2019/09/18 23:08:11 by karmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void putnbr(int n);

int  ft_ligne_argin(int fd, t_data *p_data)
{
	int  i;
	int  r;
	char c[11];
	int  puissance;

	puissance = 1;
	i = 0;
	while ((r = read(fd,&(c[i]),1)) && c[i] != '\n' && i < 10)
		i++;
	if (i == 10 || !r )
		return (ERREUR_PARAM);
	p_data->symbole[2] = c[--i];
	p_data->symbole[1] = c[--i];
	p_data->symbole[0] = c[--i];
	while (--i != -1)
	{
		if (c[i] < '0' || c[i] > '9')
			return (ERREUR_SYMB);
		p_data->nb_ligne += puissance * (c[i] - '0');
		puissance *= 10;
	}

	return (0);
}

int  ft_first_ligne2in( t_data *p_data)
{
	int i;
	char c;
	char lign[100000];

	i =0;
	read(p_data->fd, &(lign[i]),1);
	while(lign[i] != '\n')
	{
		++i;
		read(p_data->fd, &(lign[i]),1);
	}

	p_data->size_l=i;
	p_data->stock = malloc(sizeof(unsigned int) * (p_data->nb_ligne * p_data->size_l / 16 + 20));
	if (!(p_data->calcul = malloc(p_data->size_l * sizeof(int))))
		return (ERREUR_MALLOC);
	i = 0;
	while ( i < p_data->size_l)
	{
		c = lign[i];

		if (c == '\n')
			return (ERREUR_LIGNE);
		if (c == p_data->symbole[1])
		{
			p_data->calcul[i] = 0;
			ft_stock(p_data, 1);
		}
		else if (c == p_data->symbole[0])
		{
			p_data->calcul[i] = 1;
			ft_max(p_data, 1, i, 0);
			ft_stock(p_data, 0);
		}
		else
			return (ERREUR_SYMB);
		i++;

	}
	c = lign[i];
	if (c != '\n')
		return(ERREUR_LIGNE);
	if (ft_algo(p_data, 0) != SUCCESS)
		return (1);
	ft_aff(p_data);
	return (SUCCESS);
}
