/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 16:52:24 by jfeuilla          #+#    #+#             */
/*   Updated: 2019/09/08 19:02:54 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "librush.h"

int		ft_checkrowleft(int tab[6][6], int line)
{
	int i;
	int hauteur;
	int visible;

	i = 1;
	hauteur = 1;
	visible = 0;
	while (++line < 5)
	{
		while (i < 5)
		{
			if (tab[line][i] >= hauteur)
			{
				hauteur = tab[line][i];
				visible++;
			}
			i++;
		}
		if (visible != tab[line][0])
			return (0);
		hauteur = 1;
		visible = 0;
		i = 1;
	}
	return (1);
}

int		ft_checkrowright(int tab[6][6], int line)
{
	int i;
	int hauteur;
	int visible;

	i = 4;
	hauteur = 1;
	visible = 0;
	while (++line < 5)
	{
		while (i > 0)
		{
			if (tab[line][i] >= hauteur)
			{
				hauteur = tab[line][i];
				visible++;
			}
			i--;
		}
		if (visible != tab[line][5])
			return (0);
		hauteur = 1;
		visible = 0;
		i = 4;
	}
	return (1);
}

int		ft_checkcolup(int tab[6][6], int i)
{
	int j;
	int hauteur;
	int visible;

	j = 0;
	hauteur = 1;
	visible = 0;
	while (++i <= 4)
	{
		while (++j <= 4)
		{
			if (tab[j][i] >= hauteur)
			{
				hauteur = tab[j][i];
				visible++;
			}
		}
		if (visible != tab[0][i])
			return (0);
		j = 0;
		hauteur = 1;
		visible = 0;
	}
	return (1);
}

int		ft_checkcoldo(int tab[6][6], int i)
{
	int j;
	int hauteur;
	int visible;

	j = 4;
	hauteur = 1;
	visible = 0;
	while (++i <= 4)
	{
		while (j > 0)
		{
			if (tab[j][i] >= hauteur)
			{
				hauteur = tab[j][i];
				visible++;
			}
			j--;
		}
		if (visible != tab[5][i])
			return (0);
		j = 4;
		hauteur = 1;
		visible = 0;
	}
	return (1);
}

int		ft_checknbr(int tab[6][6], int pos)
{
	int i;
	int j;
	int x;
	int y;

	x = 1;
	y = 1;
	i = (pos / 4) + 1;
	j = (pos % 4) + 1;
	while (x < 5)
	{
		if (tab[i][j] == tab[i][x] && x != j)
			return (0);
		x++;
	}
	while (y < 5)
	{
		if (tab[i][j] == tab[y][j] && y != i)
			return (0);
		y++;
	}
	return (1);
}
