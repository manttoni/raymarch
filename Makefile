### BINARIES ###
NAME = raymarch

### DIRECTORIES ###
SRC_DIR = sources
OBJ_DIR = obj

### SOURCES AND OBJECTS ###
SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(patsubst $(SRC_DIR)/%.cpp, $(OBJ_DIR)/%.o, $(SRC))

### COMPILER AND FLAGS ###
CC = c++
FLAGS = -Wall -Wextra -Werror -g

### EXECUTABLE AND OBJECTS CREATION ###
$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

### Ensure obj directory exists before compiling
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

### PHONY TARGETS ###
all: $(NAME)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
