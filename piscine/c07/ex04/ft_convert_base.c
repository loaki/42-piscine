/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/10 10:57:44 by jfeuilla          #+#    #+#             */
/*   Updated: 2019/09/12 18:06:54 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			ft_check_valid(char *base);
int			ft_strlen(char *str);
int			ft_base_index(char c, char *base);
int			ft_atoi_base(char *str, char *base);

int			ft_putchar_p(int nbr, char *base_to, char *res, int index)
{
	unsigned int nb;
	unsigned int rad;

	rad = ft_strlen(base_to);
	if (nbr < 0)
	{
		res[0] = '-';
		nb = nbr * -1;
	}
	else
		nb = nbr;
	if (nb >= rad)
		ft_putchar_p(nb / rad, base_to, res, index - 1);
	res[index] = base_to[nb % rad];
	return (index);
}

int			ft_nbr_len(int nb, char *base_to)
{
	int b_len;
	int len;

	b_len = ft_strlen(base_to);
	len = 0;
	if (nb < 0)
	{
		len++;
		nb = nb * -1;
	}
	while (nb >= b_len)
	{
		len++;
		nb /= b_len;
	}
	return (++len);
}

void		ft_max_num(char *res)
{
	int		i;
	char	*max_pos;

	i = 0;
	max_pos = "-2147483648";
	while (max_pos[i])
	{
		res[i] = max_pos[i];
		i++;
	}
}

char		*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		nb;
	char	*res;
	int		last_index;
	int		res_len;

	if (ft_check_valid(base_from) || ft_check_valid(base_to))
		return (0);
	nb = ft_atoi_base(nbr, base_from);
	res_len = ft_nbr_len(nb, base_to);
	if (nb < 0)
		res_len += 1;
	if ((res = malloc(sizeof(char) * res_len)) == NULL)
		return (0);
	if (nb == -2147483648)
	{
		ft_max_num(res);
		return (res);
	}
	if (nb < 0)
		last_index = ft_putchar_p(nb, base_to, res, res_len - 2);
	else
		last_index = ft_putchar_p(nb, base_to, res, res_len - 1);
	res[last_index + 1] = '\0';
	return (res);
}
