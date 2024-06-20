SERVER_SRCS	= src/server.c
CLIENT_SRCS	= src/client.c
SERVER_BONUS_SRCS	= src/server_bonus.c
CLIENT_BONUS_SRCS	= src/client_bonus.c
HEADERS		= include/minitalk.h

CC			= cc -Wall -Werror -Wextra
CC_FLAGS	= -Llibft -lft

%.o: %.c ${HEADERS} libft/libft.a
			${CC} -c $< -o $@

all:		libft server client

bonus:		libft server client server_bonus client_bonus

libft:
			@make -C libft

server:		${SERVER_SRCS:.c=.o} libft
			${CC} ${SERVER_SRCS} ${CC_FLAGS} -o server

client:		${CLIENT_SRCS:.c=.o} libft
			${CC} ${CLIENT_SRCS} ${CC_FLAGS} -o client
			
server_bonus:		${SERVER_BONUS_SRCS:.c=.o} libft
			${CC} ${SERVER_BONUS_SRCS} ${CC_FLAGS} -o server_bonus

client_bonus:		${CLIENT_BONUS_SRCS:.c=.o} libft
			${CC} ${CLIENT_BONUS_SRCS} ${CC_FLAGS} -o client_bonus

clean:
			rm -rdf ${SERVER_SRCS:.c=.o} ${CLIENT_SRCS:.c=.o} ${SERVER_BONUS_SRCS:.c=.o} ${CLIENT_BONUS_SRCS:.c=.o}
			@make clean -C libft

fclean:		clean
			rm -rdf server client server_bonus client_bonus
			@make fclean -C libft

re:			fclean all

.PHONY:		all libft clean fclean re server client server_bonus client_bonus
