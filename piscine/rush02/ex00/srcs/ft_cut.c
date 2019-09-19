/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 21:21:54 by jfeuilla          #+#    #+#             */
/*   Updated: 2019/09/15 21:23:36 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cut.h"

void		ft_initab(char *str)
{
	int i;

	i = 0;
	while (i < 4)
	{
		str[i] = 0;
		i++;
	}
}

int			ft_cut(t_nombre *nbr, t_data *p_data)
{
	int			i;
	int			compt;
	char		str[4];
	t_nombre	ret;
	int			err;

	compt = 0;
	err = 0;
	ft_initab(str);
	i = -1;
	ret.str = str;
	while (++i < nbr->size)
	{
		if (((nbr->size - i) % 3 == 1))
		{
			compt = -1;
			ret.size = nbr->size - i - 1;
			while ((++compt < 3) && (i - compt) != -1)
				ret.str[2 - compt] = nbr->str[i - compt];
			ret.str[3] = '\0';
			if ((err = ft_splitnbr(&ret, p_data)))
				return (err);
		}
	}
	return (SUCCESS);
}

int			ft_power(t_nombre *ret, char *str, t_nombre *nbr, t_data *p_data)
{
	int err;

	err = 0;
	ret->str = str;
	ret->str[nbr->size + 1] = '\0';
	if ((err = ft_aff(ret, p_data)))
	{
		free(str);
		return (err);
	}
	return (SUCCESS);
}

int			ft_splitnbr(t_nombre *nbr, t_data *p_data)
{
	int			i;
	char		*str;
	t_nombre	ret;
	int			err;

	if (!(str = malloc(sizeof(char) * (nbr->size + 2))))
		return (ERREUR_MALLOC);
	if ((err = ft_trio(nbr, p_data)))
	{
		free(str);
		return (err);
	}
	str[0] = '1';
	i = 0;
	if (!(nbr->str[0] == '0' && nbr->str[1] == '0' && nbr->str[2] == '0'))
		while (++i < nbr->size + 1)
			str[i] = '0';
	if (i > 1)
		if ((err = ft_power(&ret, str, nbr, p_data)))
			return (err);
	free(str);
	return (SUCCESS);
}

int			ft_struct(char *av, t_data *p_data)
{
	int			i;
	int			j;
	int			err;
	t_nombre	ret;

	i = 0;
	j = 0;
	while ((av[i] == '0' && av[i + 1] != '\0' &&
			(av[i + 1] > 47 && av[i + 1] < 58)) ||
			(av[i] == '+' || av[i] == '-'))
		i++;
	while (av[i] > 47 && av[i] < 58)
	{
		av[j] = av[i];
		j++;
		i++;
	}
	ret.str = av;
	ret.str[j] = '\0';
	ret.size = j;
	if (ret.str[0] == '0' && ret.str[1] == '\0')
		err = ft_aff(&ret, p_data);
	else
		err = ft_cut(&ret, p_data);
	return (err);
}
