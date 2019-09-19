/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 10:05:27 by jfeuilla          #+#    #+#             */
/*   Updated: 2019/09/13 10:06:51 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_str_cpy(char *str, int size, char **strs, char *sep)
{
	int i;
	int j;

	i = -1;
	j = 0;
	while (++i < size)
	{
		j = -1;
		while (++j < ft_strlen(strs[i]))
		{
			(*str) = strs[i][j];
			str++;
		}
		if (i != size - 1)
		{
			j = -1;
			while (++j < ft_strlen(sep))
			{
				(*str) = sep[j];
				str++;
			}
		}
	}
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		sep_size;
	int		str_size;
	int		i;
	char	*str;

	if (size <= 0)
	{
		str = malloc(sizeof(char));
		if (str != 0)
			*str = '\0';
		return (str);
	}
	sep_size = ft_strlen(sep);
	str_size = -sep_size + 1;
	i = -1;
	while (++i < size)
		str_size += ft_strlen(strs[i]) + sep_size;
	str = malloc(str_size * sizeof(char));
	if (str == 0)
		return (0);
	ft_str_cpy(str, size, strs, sep);
	str[str_size - 1] = '\0';
	return (str);
}
