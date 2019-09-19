/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 21:20:29 by jfeuilla          #+#    #+#             */
/*   Updated: 2019/09/15 21:21:07 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_check.h"

int		ft_checknbr(char *nbr)
{
	int i;

	i = 0;
	if (nbr[0] == '+' || (nbr[0] == '-' && nbr[1] == '0' && nbr[2] == '\0'))
		i++;
	while ((nbr[i] > 47 && nbr[i] < 58) && nbr[i])
		i++;
	if (nbr[i] != '\0')
		return (ERREUR_ARG);
	return (SUCCESS);
}

int		ft_checkdata(t_data *p_data)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (p_data->lex[i + 1].str[0])
	{
		if (p_data->lex[i].str[0] == '\n')
			return (ERREUR_DICT);
		j = i + 1;
		while (p_data->lex[j].str[0])
		{
			if (ft_strcmp(p_data->lex[i].dgt, p_data->lex[j].dgt) == 0)
				return (ERREUR_DICT);
			j++;
		}
		i++;
	}
	if (p_data->lex[i].str[0] == '\n')
		return (ERREUR_DICT);
	return (SUCCESS);
}

int		ft_checkarg(int ac, char **av)
{
	if (ac == 2)
	{
		if (ft_checknbr(av[1]) == ERREUR_ARG)
			return (ERREUR_ARG);
	}
	else if (ac == 3)
	{
		if (ft_checknbr(av[2]) == ERREUR_ARG)
			return (ERREUR_ARG);
	}
	else
		return (ERREUR_ARG);
	return (SUCCESS);
}
