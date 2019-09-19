/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   librush.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/08 15:07:15 by jfeuilla          #+#    #+#             */
/*   Updated: 2019/09/08 15:24:03 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBRUSH_H
# define LIBRUSH_H
# include <unistd.h>
# include <stdlib.h>

void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	ft_zerotab(int tab[6][6]);
int		ft_checkarg(int ac, char **av);
int		ft_checkarg2(char **av);
void	ft_initab(int tab[6][6], char **av);
int		ft_checkrowleft(int tab[6][6], int line);
int		ft_checkrowright(int tab[6][6], int line);
int		ft_checkcolup(int tab[6][6], int i);
int		ft_checkcoldo(int tab[6][6], int i);
int		ft_checknbr(int tab[6][6], int pos);
void	ft_printtab(int tab[6][6]);
int		*ft_backtrack(int tab[6][6], int pos, int *x);
int		main(int ac, char **av);

#endif
