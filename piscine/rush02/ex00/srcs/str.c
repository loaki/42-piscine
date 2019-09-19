/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 21:23:58 by jfeuilla          #+#    #+#             */
/*   Updated: 2019/09/15 21:24:00 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include <stdlib.h>
#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str, 1);
		str++;
	}
	write(1, "\n", 1);
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_cat(char **str, char *src)
{
	char	*savestr;
	int		i;
	int		j;

	i = 0;
	j = 0;
	savestr = (*str);
	if (!((*str) = malloc(ft_strlen(*str) + 1 + ft_strlen(src))))
		return (ERREUR_MALLOC);
	while (savestr[i])
	{
		(*str)[i] = savestr[i];
		i++;
	}
	while (src[j])
	{
		(*str)[i] = src[j];
		i++;
		j++;
	}
	(*str)[i] = '\0';
	free(savestr);
	return (SUCCESS);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}
