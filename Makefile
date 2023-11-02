NAME = functionlister

SRC = \
	main.c \
	utilities.c \
	list_functions_of.c \

OFILES = $(SRC:%.c=%.o)

FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OFILES)
	cc $(FLAGS) $(OFILES) -o $(NAME)

clean: 
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

%.o: %.c
	cc $(FLAGS) -c -o $@ $^

re: fclean all
