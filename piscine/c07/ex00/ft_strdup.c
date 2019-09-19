/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <jfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 21:16:11 by jfeuilla          #+#    #+#             */
/*   Updated: 2019/09/12 18:01:18 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

char	*ft_strdup(char *src)
{
	int		i;
	char	*ret;

	i = 0;
	while (src[i] != '\0')
		i++;
	i++;
	ret = (char*)malloc(sizeof(src) * i);
	i = 0;
	if (ret == 0)
	{
		errno = ENOENT;
		return (0);
	}
	while (src[i] != '\0')
	{
		ret[i] = src[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
