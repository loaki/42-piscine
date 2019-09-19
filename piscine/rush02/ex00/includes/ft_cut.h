/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cut.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 21:19:03 by jfeuilla          #+#    #+#             */
/*   Updated: 2019/09/15 21:19:06 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CUT_H
# define FT_CUT_H

# include "rush.h"
# include <stdlib.h>

int		ft_cut(t_nombre *nbr, t_data *p_data);
int		ft_splitnbr(t_nombre *nbr, t_data *p_data);
int		ft_trio(t_nombre *nbr, t_data *p_data);
int		ft_aff(t_nombre *display, t_data *p_data);

#endif
