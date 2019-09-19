# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfeuilla <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/13 18:07:20 by jfeuilla          #+#    #+#              #
#    Updated: 2019/09/13 18:23:18 by jfeuilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS  = ft_do_op.c

NAME  = "do-op"

OBJS  = ${SRCS:.c=.o}

CFLAGS  = -Wall -Wextra -Werror

all:  ${OBJS}
	@gcc ${CFLAGS} ${OBJS} -o ${NAME}

.c.o:
	@cc ${CFLAGS} ${OPTION} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}

clean:
	@rm -f ${OBJS}

fclean:  clean
	@rm -f ${NAME}

re:   fclean all

.PHONY:  clean fclean all re
