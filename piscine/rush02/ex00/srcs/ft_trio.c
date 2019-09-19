/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trio.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 21:22:13 by jfeuilla          #+#    #+#             */
/*   Updated: 2019/09/15 21:22:16 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_trio.h"

int		ft_centaine(t_nombre *display, t_nombre *nbr, t_data *p_data)
{
	int err;

	display->str[0] = nbr->str[0];
	display->str[1] = '\0';
	if ((err = ft_aff(display, p_data)))
		return (err);
	display->str[0] = '1';
	display->str[1] = '0';
	display->str[2] = '0';
	display->str[3] = '\0';
	if ((err = ft_aff(display, p_data)))
		return (err);
	return (SUCCESS);
}

int		ft_dizaine(t_nombre *display, t_nombre *nbr, t_data *p_data)
{
	int err;

	display->str[0] = nbr->str[1];
	display->str[1] = '0';
	display->str[2] = '\0';
	if ((err = ft_aff(display, p_data)))
		return (err);
	return (SUCCESS);
}

int		ft_unite(t_nombre *display, t_nombre *nbr, t_data *p_data)
{
	int err;

	display->str[0] = nbr->str[2];
	display->str[1] = '\0';
	if ((err = ft_aff(display, p_data)))
		return (err);
	return (SUCCESS);
}

int		ft_trio(t_nombre *nbr, t_data *p_data)
{
	char		tab[4];
	t_nombre	display;
	int			err;

	display.str = tab;
	if (nbr->str[0] > '0')
		if ((err = ft_centaine(&display, nbr, p_data)))
			return (err);
	if (nbr->str[1] == '1')
	{
		display.str[0] = '1';
		display.str[1] = nbr->str[2];
		display.str[2] = '\0';
		if ((err = ft_aff(&display, p_data)))
			return (err);
	}
	if (nbr->str[1] > '1')
		if ((err = ft_dizaine(&display, nbr, p_data)))
			return (err);
	if (nbr->str[2] > '0' && nbr->str[1] != '1')
		if ((err = ft_unite(&display, nbr, p_data)))
			return (err);
	return (SUCCESS);
}
