# * Program name
NAME = repetitive_work

# * Compilation
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98 -g
CFLAGS += -fsanitize=address

# * Removal
RM = rm -rf

# * Includes
INCLUDES = -I ./inc/

# * Objects dir
OBJ_DIR = ./obj/

# * Sources files
CLAP_TRAP_DIR = ./src/
CLAP_TRAP_SRCS = 	ClapTrap.cpp \
					ScavTrap.cpp \
					FragTrap.cpp \
					main.cpp

SRCS = $(CLAP_TRAP_SRCS)

# * Object files
OBJS = $(addprefix $(OBJ_DIR), $(SRCS:.cpp=.o))

# ! RULES
$(OBJ_DIR)%.o: $(CLAP_TRAP_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	@echo "Compiling $(NAME)..."
	@$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $(NAME)

all: obj $(NAME)

obj:
	clear
	@mkdir -p $(OBJ_DIR)

clean:
	@echo "Removing object files..."
	@$(RM) $(OBJS)

fclean: clean
	@echo "Removing $(NAME)..."
	@$(RM) $(NAME)

re: fclean all
	@echo "Rebuilding $(NAME)"

run: all
	clear
	./$(NAME)

.PHONY: all obj clean fclean re

.DEFAULT_GOAL: all
