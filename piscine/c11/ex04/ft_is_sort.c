/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/13 13:27:47 by jfeuilla          #+#    #+#             */
/*   Updated: 2019/09/14 16:27:48 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;

	i = 0;
	if (length <= 2)
		return (1);
	while (i < length - 1)
	{
		if ((*f)(tab[i], tab[i + 1]) <= 0)
			i++;
		else
		{
			i = 0;
			while (i < length - 1)
			{
				if ((*f)(tab[i], tab[i + 1]) < 0)
					return (0);
				i++;
			}
			return (1);
		}
	}
	return (1);
}
