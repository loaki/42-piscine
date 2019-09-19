/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karmand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 23:26:01 by karmand           #+#    #+#             */
/*   Updated: 2019/09/18 22:32:53 by karmand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		ft_first_line(int fd, t_data *p_data)
{
	int		i;
	int		r;
	char	c;

	i = 0;
	while ((r = read(fd, &c, 1)) && c != '\n')
		i++;
	if (!r)
		return (ERREUR_LIGNE);
	p_data->size_l = i;
	return (SUCCESS);
}

int		ft_ligne_arg(int fd, t_data *p_data)
{
	int		i;
	int		r;
	char	c[11];
	int		puissance;

	puissance = 1;
	i = 0;
	while ((r = read(fd, &(c[i]), 1)) && c[i] != '\n' && i < 10)
		i++;
	if (i == 10 || !r)
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
	ft_first_line(fd, p_data);
	return (0);
}

int		ft_first_ligne2(t_data *p_data)
{
	int		i;
	int		r;
	char	c;

	p_data->stock = malloc(sizeof(unsigned int) *
			(p_data->nb_ligne * p_data->size_l / 32 + 40));
	i = 0;
	while ((r = read(p_data->fd, &c, 1)) && c != '\n')
		;
	if (r == 0)
		return (TAMERE);
	while ((r = ft_lire_buffer(&c, p_data)) && i < p_data->size_l)
	{
		if (c == '\n')
			return (ERREUR_LIGNE);
		if (c == p_data->symbole[1])
			p_data->calcul[i] = 0;
		else if (c == p_data->symbole[0])
		{
			p_data->calcul[i] = 1;
			ft_max(p_data, 1, i, 0);
		}
		else
			return (ERREUR_SYMB);
		i++;
	}
	if (c != '\n')
		return (ERREUR_LIGNE);
	if (ft_algo(p_data, 0) != SUCCESS)
		return (1);
	ft_aff(p_data);
	return (SUCCESS);
}

int		ft_bsq(char *filename)
{
	t_data	data;
	int		err;

	d_init(&data);
	data.fd = open(filename, O_RDONLY);
	if (!data.fd)
		return (ERREUR_OPEN);
	if ((err = ft_ligne_arg(data.fd, &data)))
		return (err);
	close(data.fd);
	data.fd = open(filename, O_RDONLY);
	if (!data.fd)
		return (ERREUR_OPEN);
	if (!(data.calcul = malloc(data.size_l * sizeof(int))))
	{
		close(data.fd);
		return (ERREUR_MALLOC);
	}
	return (ft_first_ligne2(&data));
}
