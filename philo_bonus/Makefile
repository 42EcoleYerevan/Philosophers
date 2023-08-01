NAME=philo_bonus
SRCS=$(wildcard **/*.c)
OBJS_DIR=obj/
OBJS=$(SRCS:%.c=$(OBJS_DIR)%.o)
HEADER=./philo.h
HEADER_DIR=./
CC=cc
CFLAGS= -Wall -Wextra -Werror -I$(HEADER_DIR) #-fsanitize=address -g
LIBS= -lpthread

all: $(NAME)

$(OBJS_DIR)%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	$(shell mkdir -p $(dir $(OBJS)))

$(NAME): $(OBJS_DIR) $(OBJS) $(HEADER)
	$(CC) $(CFLAGS) $(LIBS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
