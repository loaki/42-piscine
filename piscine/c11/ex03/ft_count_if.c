/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 12:00:24 by jfeuilla          #+#    #+#             */
/*   Updated: 2019/09/13 18:00:10 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int i;
	int res;

	res = 0;
	i = 0;
	while (i < length)
	{
		if ((*f)(tab[i]) != 0)
			res++;
		i++;
	}
	return (res);
}