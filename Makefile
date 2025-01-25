SRCS = ./src/digit.c ./src/free.c ./src/list.c \
       ./src/main.c ./src/push_swap.c ./src/push.c \
       ./src/reverse_rotate.c ./src/rotate.c ./src/solo.c \
       ./src/sort.c ./src/string.c ./src/swap.c \
       ./src/utils.c ./src/utils2.c

BONUS_SRCS = ./src/digit.c ./src/free.c ./src/list.c \
       ./src/main.c ./src/push_swap.c ./src/push.c \
       ./src/reverse_rotate.c ./src/rotate.c ./src/solo.c \
       ./src/sort.c ./src/string.c ./src/swap.c \
       ./src/utils.c ./src/utils2.c \
       ./get_next_line/get_next_line_utils.c ./get_next_line/get_next_line.c \
       ./bonus/bonus_sort.c ./bonus/checker.c

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -g

NAME = push_swap
NAMEB = checker

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

$(NAMEB) : $(OBJSBONUS)
	$(CC) $(CFLAGS) $(OBJSBONUS) -o $(NAMEB)

all:        ascii $(NAME)

bonus:      ascii $(OBJS) $(BONUS_OBJS)

clean :
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean : clean
	$(RM) $(NAME) $(NAMEB)

re : fclean all

.PHONY: all clean fclean re bonus