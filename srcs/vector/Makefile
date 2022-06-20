CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

NAME = vector

SRC = main.cpp\

HEADER = vector.hpp

HEADER2 = iterator.hpp

HEADER3 = utils.hpp

HEADER4 = reverse_iterator.hpp

OBJS = $(patsubst %.cpp, %.o, $(SRC))

all:
	$(MAKE) $(NAME)

$(NAME): $(OBJS) $(HEADER) $(HEADER2) $(HEADER3) $(HEADER4)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
		@$(CC) $(FLAGS) -c $< -o $@
clean:
	@rm -f $(OBJS)

fclean:	clean
	@rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re