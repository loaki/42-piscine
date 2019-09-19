/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <jfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 15:13:47 by jfeuilla          #+#    #+#             */
/*   Updated: 2019/09/04 00:38:30 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

int		ft_signe(char *str)
{
	int i;
	int s;

	i = 0;
	s = 1;
	while ((str[i] == 32) || (str[i] == 12) || (str[i] == 10) ||
			(str[i] == 13) || (str[i] == 9) || (str[i] == 11))
	{
		i++;
	}
	while ((str[i] == 45) || (str[i] == 43))
	{
		if (str[i] == 45)
			s = s * -1;
		i++;
	}
	return (s);
}

int		ft_checkbase(char *base)
{
	int i;
	int j;

	i = 0;
	while (base[i + 1])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	i = 0;
	while (base[i])
	{
		if ((base[i] == 43) || (base[i] == 45) || (base[i] == 32)
				|| (base[i] == 12) || (base[i] == 10) || (base[i] == 13)
				|| (base[i] == 9) || (base[i] == 11))
			return (0);
		i++;
	}
	return (1);
}

int		ft_indice(char str, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (base[i] == str)
			return (i);
		i++;
	}
	return (-1);
}

int		fuck_lanorme(char *str)
{
	int i;
	int s;

	i = 0;
	s = 1;
	while ((str[i] == 32) || (str[i] == 12) || (str[i] == 10) ||
			(str[i] == 13) || (str[i] == 9) || (str[i] == 11))
	{
		i++;
	}
	while ((str[i] == 45) || (str[i] == 43))
	{
		if (str[i] == 45)
			s = s * -1;
		i++;
	}
	return (i);
}

int		ft_atoi_base(char *str, char *base)
{
	int s;
	int start;
	int base_size;
	int res;

	res = 0;
	s = ft_signe(str);
	base_size = 0;
	while (base[base_size])
		base_size++;
	s = ft_signe(str);
	start = fuck_lanorme(str);
	if (ft_checkbase(base) > 0)
	{
		while (str[start] && (ft_indice(str[start], base) != -1))
		{
			res = res * base_size + ft_indice(str[start], base);
			start++;
		}
	}
	return (res * s);
}
