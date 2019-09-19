/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 11:16:53 by jfeuilla          #+#    #+#             */
/*   Updated: 2019/09/12 18:06:23 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_check_valid(char *base)
{
	int i;
	int j;

	i = 0;
	if (!(base[i] && base[1]))
		return (1);
	while (base[i])
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-' ||
				(base[i] >= 9 && base[i] <= 13) || base[i] == ' ')
			return (1);
		while (base[j])
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_base_index(char c, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int		ft_atoi_base(char *str, char *base)
{
	unsigned int i;
	unsigned int sign;
	unsigned int res;

	i = 0;
	sign = 0;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign++;
		i++;
	}
	while (ft_base_index(str[i], base) >= 0)
	{
		res = (res * ft_strlen(base)) + ft_base_index(str[i], base);
		i++;
	}
	if (sign % 2)
		res = -res;
	return (res);
}
