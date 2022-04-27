CHECKER_NAME		= checker
PUSH_SWAP_NAME		= push_swap

CC					= gcc
AR					= ar rc
RM					= rm -f

CFLAGS				= -Wall -Wextra -Werror

_CHECKER_SRCS		= checker.c parse.c checker_process.c list_sort.c commands.c \
					  error.c utils.c debug.c
CHECKER_SRCS		= $(addprefix srcs/, $(_CHECKER_SRCS))
CHECKER_OBJS		= $(CHECKER_SRCS:.c=.o)

_PUSH_SWAP_SRCS		= push_swap.c sort_two.c sort_three.c sort_more.c \
					  parse.c commands.c error.c list_sort.c utils.c \
					  steps.c debug.c apply.c
PUSH_SWAP_SRCS		= $(addprefix srcs/, $(_PUSH_SWAP_SRCS))
PUSH_SWAP_OBJS		= $(PUSH_SWAP_SRCS:.c=.o)

GREEN:="\033[1;32m"
PURPLE:="\033[1;95m"

all:				$(CHECKER_NAME) $(PUSH_SWAP_NAME)

%.o: %.c
					@$(CC) $(CFLAGS) -Iincludes -Ilibft -c $< -o $@

$(CHECKER_NAME):	$(CHECKER_OBJS)
					@make -C libft
					@$(CC) $(CHECKER_OBJS) -o $(CHECKER_NAME) -Llibft -lft
					@echo $(GREEN)"*** Checker is ready 🤙 ***\n"$(EOC)

$(PUSH_SWAP_NAME):	$(PUSH_SWAP_OBJS)
					@make -C libft
					@$(CC) $(PUSH_SWAP_OBJS) -o $(PUSH_SWAP_NAME) -Llibft -lft
					@echo $(GREEN)"*** Push_swap and Checkers is ready 🤙 ***\n"$(EOC)

clean:
					@$(RM) $(CHECKER_OBJS) $(PUSH_SWAP_OBJS)
					@echo $(PURPLE)"*** All *.o cleans🗑 ***\n"$(EOC)

fclean:				clean
					@$(RM) $(CHECKER_NAME) $(PUSH_SWAP_NAME)
					@echo $(PURPLE)"*** All removed🧻 ***\n"$(EOC)

liboc:			
					@make clean -C libft

libof:			
					@make fclean -C libft

norm:				
					norminette
					norminette -v

re:					fclean all

.PHONY: clean fclean re all liboc libof norm