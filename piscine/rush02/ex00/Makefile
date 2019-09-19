SRCS        = 	srcs/ft_cut.c\
			 	srcs/aff2.c\
				srcs/ft_trio.c\
				srcs/main.c\
				srcs/str.c\
				srcs/ft_check.c\
				srcs/ft_parse.c\
				srcs/memoire.c

OPTION      = -I includes/

NAME        = "rush-02"

OBJS        = ${SRCS:.c=.o}

CFLAGS      = -Wall -Wextra -Werror

all:        ${OBJS}
	    @gcc $(CFLAGS) ${OBJS} -o $(NAME)

.c.o:
	    @cc ${CFLAGS} ${OPTION} -c $< -o ${<:.c=.o}

${NAME}:    ${OBJS}

clean:
	    @rm -f ${OBJS}

fclean:     clean
	    @rm -f ${NAME}

re:         fclean all

.PHONY:     clean fclean all re
