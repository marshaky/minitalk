NAME			= libftprintf.a

LIBFT 			= libft/libft.a

SRCS 			=	ft_print_char.c ft_print_decimal.c ft_print_pointer.c \
					ft_print_hex.c ft_itoa_base.c ft_printf.c \
					ft_print_percent.c ft_putchar.c ft_print_string.c \
					ft_print_unsigned_decimal.c

OBJS 			=  ${SRCS:.c=.o}

CC 				= cc
RM 				= rm -rf
CFLAGS			= -Wall -Wextra -Werror
AR				= ar rcs

%.o: %.c		
				$(CC) $(CFLAGS) -c $< -o $@

all:			$(NAME)

$(NAME): 		$(OBJS)
					$(MAKE) -C ./libft
					cp ${LIBFT} $(NAME)
					${AR} $(NAME) $(OBJS)

clean:
				$(MAKE) clean -C ./libft
				${RM} $(OBJS)

fclean:			clean
					$(MAKE) fclean -C ./libft
					${RM} $(NAME)

re: 			fclean all

.PHONY:			all clean fclean re
