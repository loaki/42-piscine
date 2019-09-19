/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <jfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 23:56:03 by jfeuilla          #+#    #+#             */
/*   Updated: 2019/09/03 14:13:23 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

char	*ft_strstr(char *str, char *to_find)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (to_find[i] == '\0')
		return (str);
	while (str[j] != '\0')
	{
		if (str[j] == to_find[0])
		{
			while (to_find[i] != '\0' && str[i + j] == to_find[i])
				i++;
		}
		if (to_find[i] == '\0')
			return (&str[j]);
		j++;
	}
	return (0);
}
