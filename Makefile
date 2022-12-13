NAME := libft.a
SRCS := ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_printf.c \
		ft_printf_utils.c \
		get_next_line.c \
		get_next_line_utils.c

BONUS_SRCS := ft_lstadd_back_bonus.c \
			  ft_lstadd_front_bonus.c \
			  ft_lstclear_bonus.c \
			  ft_lstdelone_bonus.c \
			  ft_lstiter_bonus.c \
			  ft_lstlast_bonus.c \
			  ft_lstmap_bonus.c \
			  ft_lstnew_bonus.c \
			  ft_lstsize_bonus.c

all: $(NAME)

$(NAME): 
	cc -Wall -Werror -Wextra -c $(SRCS)
	ar -crs $(NAME) $(SRCS:.c=.o)

clean:
	rm -rf $(SRCS:.c=.o) $(BONUS_SRCS:.c=.o)

fclean: clean
	rm -rf $(NAME)

re: fclean $(NAME)

$(BONUS_SRCS:.c=.o):
	gcc -Wall -Werror -Wextra -c $(BONUS_SRCS)
	ar -urs $(NAME) $(BONUS_SRCS:.c=.o)

bonus: $(BONUS_SRCS:.c=.o)

.PHONY: all clean fclean re bonus
