NAME	= ft_container

SRC		= main.cpp

CC		= c++

CFLAGS	= -Wall -Wextra -Werror

FCFLAGS	= -Wall -Wextra -Werror -fsanitize=address

RM		= rm -rf

all:	$(NAME)

special: $(NAME2)

test:	re
	./ft_container

$(NAME): $(SRC)
	$(CC) $(FCFLAGS) $(SRC) -o $@

clean:
	$(RM) $(NAME)

fclean: clean

re: fclean all

.PHONY: all fclean clean re