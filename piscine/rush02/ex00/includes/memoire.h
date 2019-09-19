/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memoire.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 21:20:04 by jfeuilla          #+#    #+#             */
/*   Updated: 2019/09/15 21:20:06 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMOIRE_H
# define MEMOIRE_H

# include <stdlib.h>
# include "rush.h"

int		ft_parsefile(t_definition **dict, char *file);
void	ft_remspace(char *str);
void	ft_dictspace(t_definition *lex);
char	*ft_strcpy(char *dest, char *src);

#endif
