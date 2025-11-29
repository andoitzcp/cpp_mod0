##
# Project Title
#
# @file
# @version 0.1

NAME=megaphone
CC=c++
CFLAGS=-Wall -Werror -Wextra

SRC=megaphone.cpp
OBJ=$(SRC:.cpp=.o)

all:$(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $@
	@echo "$(NAME) compiled"

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	@rm -f *.o
	@echo "object files cleaned"

fclean: clean
	@rm -f $(NAME)
	@echo "executable file, $(NAME), cleaned"

re: fclean all

.PHONY: all clean fclean re

# end
