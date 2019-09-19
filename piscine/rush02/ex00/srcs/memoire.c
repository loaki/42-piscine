/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memoire.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 21:23:52 by jfeuilla          #+#    #+#             */
/*   Updated: 2019/09/15 21:23:54 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memoire.h"

int		ft_init(t_data *p_data, char *filename)
{
	int err;

	if ((err = ft_parsefile(&(p_data->lex), filename)))
		return (err);
	if (!(p_data->str = malloc(sizeof(char))))
	{
		free(p_data->lex);
		return (ERREUR_MALLOC);
	}
	p_data->str[0] = '\0';
	ft_dictspace(p_data->lex);
	return (SUCCESS);
}

void	ft_dest(t_data *p_data)
{
	free(p_data->str);
	free(p_data->lex);
}

void	ft_remspace(char *str)
{
	char	copy[STR_SIZE];
	int		i;
	int		j;

	i = 0;
	j = 0;
	ft_strcpy(copy, str);
	while (copy[i])
	{
		while (copy[i] != ' ' && copy[i])
			str[j++] = copy[i++];
		if (copy[i] == ' ' && copy[i])
			str[j++] = copy[i++];
		while (copy[i] == ' ' && copy[i])
			i++;
	}
	str[j] = '\0';
}

void	ft_dictspace(t_definition *lex)
{
	int i;

	i = 0;
	while (lex[i].str[0])
	{
		ft_remspace(lex[i].str);
		i++;
	}
}
