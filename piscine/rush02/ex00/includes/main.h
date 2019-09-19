/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 21:19:32 by jfeuilla          #+#    #+#             */
/*   Updated: 2019/09/15 21:19:57 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "rush.h"
# include <unistd.h>

int		ft_checkarg(int ac, char **av);
int		ft_checkdata(t_data *p_data);
int		ft_init(t_data *p_data, char *filename);
void	ft_dest(t_data *p_data);

int		ft_struct(char *str, t_data *p_data);

void	ft_putstr(char *str);

#endif
