SERVER_SRCS	= src/server.c
CLIENT_SRCS	= src/client.c
SERVER_BONUS_SRCS	= src/server_bonus.c
CLIENT_BONUS_SRCS	= src/client_bonus.c
HEADERS		= include/minitalk.h

CC			= cc
CFLAGS		= -Wall -Werror -Wextra -Iinclude
LDFLAGS		= -Llibft -lft

OBJS		= ${SERVER_SRCS:.c=.o} ${CLIENT_SRCS:.c=.o}
BONUS_OBJS	= ${SERVER_BONUS_SRCS:.c=.o} ${CLIENT_BONUS_SRCS:.c=.o}

%.o: %.c ${HEADERS} libft/libft.a
			${CC} ${CFLAGS} -c $< -o $@

all:		libft server client

bonus:		libft server_bonus client_bonus

libft:
			@make -C libft

server:		src/server.o
			${CC} ${CFLAGS} $< ${LDFLAGS} -o $@

client:		src/client.o
			${CC} ${CFLAGS} $< ${LDFLAGS} -o $@

server_bonus:	src/server_bonus.o
			${CC} ${CFLAGS} $< ${LDFLAGS} -o $@

client_bonus:	src/client_bonus.o
			${CC} ${CFLAGS} $< ${LDFLAGS} -o $@

clean:
			rm -rdf ${OBJS} ${BONUS_OBJS}
			@make clean -C libft

fclean:		clean
			rm -rdf server client server_bonus client_bonus
			@make fclean -C libft

re:			fclean all

.PHONY:		all libft clean fclean re server client server_bonus client_bonus
