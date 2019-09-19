/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: karmand <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 00:34:59 by karmand           #+#    #+#             */
/*   Updated: 2019/09/18 16:51:00 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void	d_init(t_data *data)
{
	data->size_b = SIZE_BUFF;
	data->nb_ligne = 0;
	data->size_l = 0;
	data->x_max = 0;
	data->y_max = 0;
	data->max = 0;
	data->j = 0;
	data->p = 1;
	data->i = SIZE_BUFF;
}
