
NAME	= libftprintf.a

LFLAGS	= ar rcs

SRC	= ./src/ft_printf.c 	./src/ft_printf_utils.c


OBJS	= ${SRC:%.c=%.o}

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
c		= -c

all:	${NAME}

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}




clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY:	all clean fclean re