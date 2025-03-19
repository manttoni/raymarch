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
FLAGS = -Wall -Wextra -Werror -g $(shell sdl2-config --cflags)
LDFLAGS = $(shell sdl2-config --libs)

### EXECUTABLE AND OBJECTS CREATION ###
$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

### Ensure obj directory exists before compiling
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(FLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

### PHONY TARGETS ###
all: $(NAME)

# Clean up object files and build directory
clean:
	rm -rf $(OBJ_DIR)

# Clean up all build artifacts, including the binary
fclean: clean
	rm -f $(NAME)

# Rebuild everything from scratch
re: fclean all

# Run the program after building
run: $(NAME)
	./$(NAME)

.PHONY: all clean fclean re run
