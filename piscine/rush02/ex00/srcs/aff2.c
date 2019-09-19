/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aff2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 21:20:23 by jfeuilla          #+#    #+#             */
/*   Updated: 2019/09/15 21:20:25 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "aff2.h"

int		ft_aff(t_nombre *display, t_data *p_data)
{
	int i;

	i = 0;
	if (ft_cat(&(p_data->str), " "))
		return (ERREUR_MALLOC);
	while (p_data->lex[i].str[0] != 0)
	{
		if (0 == ft_strcmp(display->str, p_data->lex[i].dgt))
		{
			if (ft_cat(&(p_data->str), p_data->lex[i].str))
				return (ERREUR_MALLOC);
			return (SUCCESS);
		}
		i++;
	}
	return (ERREUR_CONVERT);
}
