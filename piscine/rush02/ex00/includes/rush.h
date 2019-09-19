/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/15 21:20:13 by jfeuilla          #+#    #+#             */
/*   Updated: 2019/09/15 21:20:16 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_H
# define RUSH_H

# define ERREUR_CONVERT 4
# define ERREUR_ARG 3
# define ERREUR_DICT 2
# define ERREUR_MALLOC 1
# define SUCCESS 0
# define STR_SIZE 2048

typedef struct		s_nombre
{
	char	*str;
	int		size;
}					t_nombre;

typedef struct		s_definition
{
	char dgt[STR_SIZE];
	char str[STR_SIZE];
}					t_definition;

typedef struct		s_data
{
	t_definition	*lex;
	char			*str;
}					t_data;

#endif
