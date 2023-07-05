NAME=philo
SRCS=$(wildcard ./*.c)
OBJS=$(SRCS:%.c=%.o)
HEADER=./philo.h
CC=cc
CFLAGS= -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
