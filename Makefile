NAME_SERVER			= server
NAME_CLIENT			= client

SRCS_SERVER			= server.c utils.c
SRCS_CLIENT			= client.c utils.c

OBJS_SERVER			= $(SRCS_SERVER:.c=.o)
OBJS_CLIENT			= $(SRCS_CLIENT:.c=.o)

CC					= cc
CFLAGS				= -Wall -Wextra -Werror

all:				$(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): 	$(OBJS_SERVER)
						$(CC) $(CFLAGS) $(OBJS_SERVER) -o $(NAME_SERVER)

$(NAME_CLIENT): 	$(OBJS_CLIENT) $(PRINTF_LIB)
						$(CC) $(CFLAGS) $(OBJS_CLIENT) -o $(NAME_CLIENT)

clean:
					rm -f $(OBJS_SERVER) $(OBJS_CLIENT)

fclean: 			clean
						rm -f $(NAME_SERVER) $(NAME_CLIENT)

re: 				fclean all

.PHONY: 			all clean fclean re
