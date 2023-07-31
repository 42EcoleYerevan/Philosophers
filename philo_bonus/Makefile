NAME=philo_bonus
SRCS=$(wildcard *.c)
OBJS_DIR=obj/
OBJS=$(SRCS:%.c=$(OBJS_DIR)%.o)
HEADER=./philo.h
CC=cc
CFLAGS= -Wall -Wextra -Werror
LIBS= -lpthread

all: $(NAME)

$(OBJS_DIR)%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	mkdir $(OBJS_DIR)

$(NAME): $(OBJS_DIR) $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(LIBS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
