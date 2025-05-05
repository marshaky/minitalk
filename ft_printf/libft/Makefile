NAME			= libft.a

SRC				=	ft_strdup.c ft_atoi.c ft_strlcat.c \
					ft_striteri.c ft_bzero.c \
					ft_strjoin.c ft_calloc.c \
					ft_isalnum.c ft_memchr.c ft_strlcpy.c \
					ft_isalpha.c ft_memcmp.c ft_strlen.c \
					ft_isascii.c ft_memcpy.c ft_strmapi.c \
					ft_isdigit.c ft_memmove.c ft_strncmp.c \
					ft_isprint.c ft_memset.c ft_strnstr.c \
					ft_itoa.c ft_putchar_fd.c ft_strrchr.c \
					ft_putendl_fd.c ft_strtrim.c \
					ft_putnbr_fd.c ft_substr.c \
					ft_putstr_fd.c ft_tolower.c ft_split.c \
					ft_toupper.c ft_strchr.c

OBJS			= $(SRC:.c=.o)

BONUS			=	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
					ft_lstdelone.c ft_lstiter.c ft_lstlast.c \
					ft_lstmap.c ft_lstnew.c ft_lstsize.c

BONUS_OBJS		= $(BONUS:.c=.o)

HEADER			= libft.h
AR				= ar rcs
RM				= rm -rf
CC				= cc
CFLAGS			= -Wall -Wextra -Werror

%.o: %.c		
			$(CC) $(CFLAGS) -c $< -o $@

all:			$(NAME)

$(NAME):		$(OBJS)
					$(AR) $(NAME) $(OBJS)

clean:
					$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
					$(RM) $(NAME)

re:				fclean all

bonus:			$(OBJS) $(BONUS_OBJS)
					$(AR) $(NAME) $(OBJS) $(BONUS_OBJS)

.PHONY:			all clean fclean re bonus
