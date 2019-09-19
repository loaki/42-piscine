/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <jfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/30 10:22:44 by jfeuilla          #+#    #+#             */
/*   Updated: 2019/08/31 21:44:36 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strlowcase(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 91 && str[i] > 64)
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	ft_strlowcase(str);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 123 && str[i] > 96)
		{
			str[i] = str[i] - 32;
			i++;
		}
		while ((str[i] < 123 && str[i] > 96) || (str[i] < 91
					&& str[i] > 64) || (str[i] < 58 && str[i] > 47))
		{
			i++;
		}
		i++;
	}
	return (str);
}
