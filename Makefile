NAME	= vector

SRC		= main_test.cpp

CC		= c++

CFLAGS	= -Wall -Wextra -Werror

FCFLAGS	= -Wall -Wextra -Werror -fsanitize=address

RM		= rm -rf

all:	$(NAME)

special: $(NAME2)

test:	re
	./vector

test2:	re2
	./vector

$(NAME): $(SRC)
	$(CC) $(FCFLAGS) $(SRC) -o $@

$(NAME2): $(SRC)
	$(CC) $(FCFLAGS) $(SRC) -o $@

clean:
	$(RM) $(NAME)

fclean: clean

re: fclean all

re2 :fclean special

.PHONY: all fclean clean re