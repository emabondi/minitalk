NAME = server
NAME1 = client
SERVER_SRCS = server.c
CLIENT_SRCS = client.c client2.c
MYLIB = mylib/mylib.a
FLAGS = -Wall -Wextra -Werror

all: $(NAME) $(NAME1)

$(NAME): $(SERVER_SRCS)
		gcc $(FLAGS) $(SERVER_SRCS) -o server mylib/mylib.a

$(NAME1): $(CLIENT_SRCS)
		gcc $(FLAGS) $(CLIENT_SRCS) -o client mylib/mylib.a

re: clean all

clean:
		rm -f server
		rm -f client

fclean:	clean