$(NAME):
		gcc server.c -o server libft/libft.a
		gcc client.c -o client libft/libft.a

clean:
		rm -f server
		rm -f client
fclean:	clean