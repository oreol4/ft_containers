CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

NAME = map

HEADER = pair.hpp Map.hpp\

SRC = main.cpp\

OBJS = $(patsubst %.cpp, %.o, $(SRC))

all:
	$(MAKE) $(NAME)

$(NAME): $(OBJS) $(HEADER)
	$(CC) -I./ $(FLAGS) -o $(NAME) $(OBJS)

$.o: %.cpp
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re