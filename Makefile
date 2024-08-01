
SRCS	= main.c

SRCS	+= utils2.c init.c utils.c launcher.c

OBJS	= $(SRCS:.c=.o)

NAME	= philo

GCC	= gcc

FLAGS	= -Wall -Wextra -Werror -g #-fsanitize=thread

INCLUDE	= -lpthread

HEADER	= philo.h

GREEN  = \033[32;1m
RED    = \033[31;49;1m
RESET  = \033[0m

all:	$(NAME)

.PHONY:	clean fclean re bonus bench bclean

$(NAME): $(OBJS)
	$(GCC) $(INCLUDE) $(FLAGS) -o $(NAME) $(OBJS)
	@ echo "\n	🟢$(GREEN) $(NAME) created $(RESET)\n"

clean:
	rm -f $(OBJS) $(B_OBJS)
	@ echo "\n	🔴$(RED) Delete : objects $(RESET)\n"

fclean: clean
	rm -f $(NAME) $(BONUS)
	@ echo "	🔴$(RED) Delete : $(NAME) $(RESET)\n"

re: fclean all

%.o: %.c $(HEADER)
	$(GCC) $(FLAGS) -c $<  -o $(<:.c=.o)
