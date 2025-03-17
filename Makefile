### BINARIES ###
NAME = raymarch

### SOURCES AND OBJECTS ###
SRC =	*.cpp
OBJ = $(SRC:.cpp=.o)

### COMPILER AND FLAGS ###
CC = c++
FLAGS = -Wall -Wextra -Werror

### EXECUTABLE AND OBJECTS CREATION ###
$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

### PHONY TARGETS ###
all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re