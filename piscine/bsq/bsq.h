/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfeuilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 17:24:38 by jfeuilla          #+#    #+#             */
/*   Updated: 2019/09/19 00:22:20 by jfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# define SUCCESS 0
# define ERREUR_PARAM 1
# define ERREUR_SYMB 2
# define ERREUR_LIGNE 3
# define ERREUR_OPEN 4
# define ERREUR_MALLOC 5
# define TAMERE 6
# define SIZE_BUFF 4096
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct	s_data
{
	int				x_max;
	int				y_max;
	int				max;
	int				size_l;
	int				nb_ligne;
	char			symbole[3];
	int				*calcul;
	char			buffer[SIZE_BUFF];
	int				size_b;
	int				i;
	int				fd;
	unsigned int	*stock;
	int				j;
	unsigned int	p;
}				t_data;

int				ft_first_line(int fd, t_data *p_data);
int				ft_ligne_arg(int fd, t_data *p_data);
int				ft_first_ligne2(t_data *p_data);
void			d_init(t_data *p_data);
int				ft_bsq(char *filename);
void			ft_max(t_data *p_data, int b, int x, int y);
int				ft_algo(t_data *p_data, int y);
int				ft_lire_buffer(char *c, t_data *p_data);
int				ft_aff(t_data *p_data);

int  ft_first_ligne2in( t_data *p_data);
int  ft_ligne_argin(int fd, t_data *p_data);
void ft_stock(t_data *p_data, unsigned int a);
#endif
