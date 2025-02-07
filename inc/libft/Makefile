files =			ft_isalpha \
				ft_isdigit \
				ft_isalnum \
				ft_isascii \
				ft_isprint \
				ft_strlen \
				ft_memset \
				ft_bzero \
				ft_memcpy \
				ft_memmove \
				ft_strlcpy \
				ft_strlcat \
				ft_toupper \
				ft_tolower \
				ft_strchr \
				ft_strrchr \
				ft_strncmp \
				ft_memchr \
				ft_memcmp \
				ft_strnstr \
				ft_atoi \
				ft_substr \
				ft_strjoin \
				ft_strtrim \
				ft_split \
				ft_itoa \
				ft_strmapi \
				ft_striteri \
				ft_putchar_fd \
				ft_putstr_fd \
				ft_putendl_fd \
				ft_putnbr_fd \
				ft_strdup \
				ft_calloc 

bonus =			ft_lstnew_bonus \
				ft_lstadd_front_bonus \
				ft_lstsize_bonus \
				ft_lstlast_bonus \
				ft_lstadd_back_bonus \
				ft_lstdelone_bonus \
				ft_lstclear_bonus \
				ft_lstiter_bonus \
				ft_lstmap_bonus 

Compiler = cc
CmpFlags = -Wall -Werror -Wextra -g
CFILES = $(files:%=%.c)
BFILES = $(bonus:%=%.c)
OFILES = $(files:%=%.o)
BOFILES = $(bonus:%=%.o)
NAME = libft.a

#ar is the archive
#c gives warnings if archieve already exists
$(NAME): $(OFILES)
	ar rs $(NAME) $(OFILES)

bonus: $(OFILES) $(BOFILES)
	ar rs $(NAME) $(OFILES) $(BOFILES)

%.o: %.c
	$(Compiler) $(CmpFlags) -c $< -o $@

all: $(NAME) $(BFILES)

clean:
	rm -f $(OFILES) $(BOFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus