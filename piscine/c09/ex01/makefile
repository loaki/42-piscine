# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jfeuilla <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/12 21:26:30 by jfeuilla          #+#    #+#              #
#    Updated: 2019/09/13 10:54:24 by jfeuilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS  = srcs/ft_putchar.c\
		srcs/ft_swap.c\
		srcs/ft_putstr.c\
		srcs/ft_strlen.c\
		srcs/ft_strcmp.c

PATH_H  = includes/

OPTION  = -I ${PATH_H}

NAME  = libft.a

OBJS  = ${SRCS:.c=.o}

CFLAGS  = -Wall -Wextra -Werror

AR   = ar rc

.c.o:  
	cc ${CFLAGS} ${OPTION} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
	${AR} ${NAME} ${OBJS}

all:  ${NAME}

clean:
	rm -f ${OBJS}

fclean:  clean 
	rm -f ${NAME}

re:   fclean all

.PHONY:  clean fclean all re 
