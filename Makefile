NAME_SERVER			= server
NAME_CLIENT			= client

PRINTF_DIR			= ./ft_printf
PRINTF_LIB			= $(PRINTF_DIR)/libftprintf.a

SRCS_SERVER			= server.c
SRCS_CLIENT			= client.c

OBJS_SERVER			= $(SRCS_SERVER:.c=.o)
OBJS_CLIENT			= $(SRCS_CLIENT:.c=.o)

CC					= cc
CFLAGS				= -Wall -Wextra -Werror

all:				$(PRINTF_LIB) $(NAME_SERVER) $(NAME_CLIENT)

$(PRINTF_LIB):
					make -C $(PRINTF_DIR)

$(NAME_SERVER): 	$(OBJS_SERVER) $(PRINTF_LIB)
						$(CC) $(CFLAGS) $(OBJS_SERVER) $(PRINTF_LIB) -I$(PRINTF_DIR) -o $(NAME_SERVER)

$(NAME_CLIENT): 	$(OBJS_CLIENT) $(PRINTF_LIB)
						$(CC) $(CFLAGS) $(OBJS_CLIENT) $(PRINTF_LIB) -I$(PRINTF_DIR) -o $(NAME_CLIENT)

clean:
					make clean -C $(PRINTF_DIR)
					rm -f $(OBJS_SERVER) $(OBJS_CLIENT)

fclean: 			clean
						make fclean -C $(PRINTF_DIR)
						rm -f $(NAME_SERVER) $(NAME_CLIENT)

re: 				fclean all

.PHONY: 			all clean fclean re
