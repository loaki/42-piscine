# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfeuilla <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/18 13:21:09 by jfeuilla          #+#    #+#              #
#    Updated: 2019/09/18 23:14:14 by karmand          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS  = aff.c\
		bsq.c\
		data.c\
		ft_algo.c\
		stdin.c\
		main.c

NAME  = bsq

OBJS  = ${SRCS:.c=.o}

CFLAGS  = -Wall -Wextra -Werror

.c.o:
	cc ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	gcc ${OBJS} -o ${NAME}

all:  ${NAME}

clean:
	rm -f ${OBJS}

fclean:  clean
	rm -f ${NAME}

re:   fclean all

.PHONY:  clean fclean all re
