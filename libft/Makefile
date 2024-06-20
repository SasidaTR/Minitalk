LIBC = ft_atoi.c ft_isprint.c ft_strlen.c ft_putchar_fd.c ft_substr.c

PRINTF = ft_putchar.c ft_putstr.c ft_putnbr.c ft_putnbr_u.c ft_puthex.c ft_puthex_upper.c ft_putptr.c ft_printf.c

SRC = ${LIBC} ${PRINTF}
OBJ = ${SRC:.c=.o}
NAME = libft.a
CFLAGS = -Wall -Werror -Wextra -I ./

.c.o:
		cc ${CFLAGS} -c $< -o $@

${NAME}: ${OBJ}
		ar -rcs ${NAME} ${OBJ}

all: ${NAME}

clean:	
		rm -rf ${OBJ}

fclean:	clean
		rm -rf ${NAME}

re: fclean all

.PHONY: all clean fclean re
