CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++11

NAME = map

HEADER = utils/node.hpp\
	 utils/comp.hpp\
	 utils/pair.hpp\

SRC = main.cpp\

OBJS = $(patsubst %.cpp, %.o, $(SRC))

all:
	$(MAKE) $(NAME)

$(NAME): $(OBJS) $(HEADER)
	$(CC) $(HEADER) $(FLAGS) -o $(NAME) $(OBJS)

$.o: %.cpp
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
