/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 16:10:53 by jfeuilla          #+#    #+#             */
/*   Updated: 2019/09/19 10:06:18 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void	ft_putchar(char c);

void	ft_printchar(int h, int l, int x, int y);

void	rush(int x, int y);

int		main(int ac, char **av)
{
	(void)ac;
	rush(atoi(av[1]), atoi(av[2]));
	return (0);
}
