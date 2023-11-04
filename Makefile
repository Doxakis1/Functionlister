NAME = functionlister

SRC = \
	main.c \
	utilities.c \
	list_functions_of.c \

OFILES = $(SRC:%.c=%.o)

FLAGS = -Wall -Wextra -Werror

DEBUG_FLAGS = -g -fsanitize=address,undefined

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OFILES)
	cc $(FLAGS) $(OFILES) -o $(NAME)

clean: 
	rm -f $(OFILES)
debug: $(OFILES)
	cc $(FLAGS) $(DEBUG_FLAGS) $(OFILES) -o $(NAME)
fclean: clean
	rm -f $(NAME)

%.o: %.c
	cc $(FLAGS) -c -o $@ $^

re: fclean all
