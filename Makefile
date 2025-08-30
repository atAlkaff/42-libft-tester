CC      = gcc
CFLAGS  = -Wall -Wextra -Werror -g
NAME    = run_tests

# Paths
LIBFT_DIR = ../libft
LIBFT     = $(LIBFT_DIR)/libft.a
INCLUDES  = -I$(LIBFT_DIR)

# Source discovery
SRC       = $(wildcard */*.c)
OBJ       = $(SRC:.c=.o)

# Linker flags
LDFLAGS   = -L$(LIBFT_DIR) -lft -lcriterion -lgcov

# Default target
all: $(NAME)

# Build libft if needed
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Compile each .c file into .o with include path
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Link everything
$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LDFLAGS)

# Clean object files
clean:
	rm -f $(OBJ)

# Full clean
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

