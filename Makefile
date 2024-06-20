CC = cc -Wall -Werror -Wextra
CC_FLAGS = -Llibft -lft

SERVER_SRC = src/server.c
CLIENT_SRC = src/client.c
SERVER_BONUS_SRC = src/server_bonus.c
CLIENT_BONUS_SRC = src/client_bonus.c
SERVER_OBJ = $(SERVER_SRC:.c=.o)
CLIENT_OBJ = $(CLIENT_SRC:.c=.o)
SERVER_BONUS_OBJ = $(SERVER_BONUS_SRC:.c=.o)
CLIENT_BONUS_OBJ = $(CLIENT_BONUS_SRC:.c=.o)

LIBFT = libft/libft.a

%.o: %.c
	${CC} -o $@ -c $<

all: libft server client

bonus: libft server client server_bonus client_bonus

libft: $(LIBFT)

$(LIBFT):
	@make -C libft

server: $(SERVER_OBJ) $(LIBFT)
	${CC} ${SERVER_OBJ} ${CC_FLAGS} -o server

client: $(CLIENT_OBJ) $(LIBFT)
	${CC} ${CLIENT_OBJ} ${CC_FLAGS} -o client

server_bonus: $(SERVER_BONUS_OBJ) $(LIBFT)
	${CC} ${SERVER_BONUS_OBJ} ${CC_FLAGS} -o server_bonus

client_bonus: $(CLIENT_BONUS_OBJ) $(LIBFT)
	${CC} ${CLIENT_BONUS_OBJ} ${CC_FLAGS} -o client_bonus

clean:
	rm -rdf ${SERVER_OBJ} ${CLIENT_OBJ} ${SERVER_BONUS_OBJ} ${CLIENT_BONUS_OBJ}
	@make clean -C libft

fclean: clean
	rm -rdf server client server_bonus client_bonus
	@make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
