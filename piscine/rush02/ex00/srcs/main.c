/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 21:23:47 by jfeuilla          #+#    #+#             */
/*   Updated: 2019/09/15 21:23:48 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int		ft_error(int err)
{
	if (err == ERREUR_CONVERT)
		write(1, "Error\n", 6);
	if (err == ERREUR_DICT)
		write(1, "Dict Error\n", 11);
	if (err == ERREUR_ARG)
		write(1, "Error\n", 6);
	return (SUCCESS);
}

int		ft_ac2(char **av, t_data *p_data)
{
	int err;

	if ((err = ft_init(p_data, "dico.dict")))
		return (ft_error(err));
	if ((err = ft_checkdata(p_data)))
	{
		ft_dest(p_data);
		return (ft_error(err));
	}
	if ((err = ft_struct(av[1], p_data)))
	{
		ft_dest(p_data);
		return (ft_error(err));
	}
	ft_putstr(p_data->str + 1);
	ft_dest(p_data);
	return (SUCCESS);
}

int		ft_ac3(char **av, t_data *p_data)
{
	int err;

	if ((err = ft_init(p_data, av[1])))
		return (ft_error(err));
	if ((err = ft_checkdata(p_data)))
	{
		ft_dest(p_data);
		return (ft_error(err));
	}
	if ((err = ft_struct(av[2], p_data)))
	{
		ft_dest(p_data);
		return (ft_error(err));
	}
	ft_putstr(p_data->str + 1);
	ft_dest(p_data);
	return (SUCCESS);
}

int		main(int ac, char **av)
{
	t_data	data;
	int		err;

	if ((err = ft_checkarg(ac, av)))
		return (ft_error(err));
	if (ac == 2)
		ft_ac2(av, &data);
	else if (ac == 3)
		ft_ac3(av, &data);
	else
		return (ft_error(ERREUR_ARG));
	return (0);
}
