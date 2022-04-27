NAME	=   libft.a
SRCS	=	ft_atoi.c \
			ft_bzero.c \
			ft_calloc.c \
			ft_isalnum.c \
			ft_isalpha.c \
			ft_isascii.c \
			ft_isdigit.c \
			ft_isprint.c \
			ft_itoa.c \
			ft_memccpy.c \
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
			ft_strjoin.c \
			ft_strlcat.c \
			ft_strlcpy.c \
			ft_strlen.c \
			ft_strncmp.c \
			ft_strnstr.c \
			ft_strrchr.c \
			ft_strtrim.c \
			ft_substr.c \
			ft_tolower.c \
			ft_toupper.c \
			ft_strmapi.c \
			ft_strcmp.c \
			ft_lstadd_back.c \
			ft_lstadd_front.c \
			ft_lstclear.c \
			ft_lstdelone.c \
			ft_lstiter.c \
			ft_lstlast.c \
			ft_lstmap.c \
			ft_lstnew.c \
			ft_lstsize.c \
			ft_lstpop_front.c \
			ft_lstpop_back.c \
			ft_lst_at.c \
			ft_lst_remove_if.c \
			ft_lst_to_array.c \
			get_next_line.c \
			get_next_line_utils.c \
			ft_bubble_sort.c
OBJS	= $(SRCS:.c=.o)
OBJS_B	= $(SRCS_B:.c=.o)
RM		= rm -f
LIBC	= ar -rcs
FLAGS	= -Wall -Wextra -Werror
INCS	= .
GREEN:="\033[1;32m"
RED:="\033[1;95m"

%.o: %.c Makefile libft.h
	@${CC} ${FLAGS} -c $< -o ${<:.c=.o} -I${INCS}

$(NAME): ${OBJS}
	@${LIBC} $(NAME) $(OBJS)
	@echo $(GREEN)"*** Libft is ready 🤙 ***\n"$(EOC)

all: @$(NAME)


bonus: $(NAME) $(OBJS_B)
	@${LIBC} $(NAME) $(OBJS_B)

fclean: clean
	@$(RM) $(NAME) $(bonus)
	@echo $(RED)"All libft removed 🧻"$(EOC)

clean:
	@$(RM) -f $(OBJS) $(OBJS_B)
	@echo $(RED)"All libft *.o cleans 🗑"$(EOC)

re: fclean all

.PHONY: all bonus clean fclean re .c.o