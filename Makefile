CC      = gcc
CFLAGS  = -Wall -Wextra -Werror -g
NAME    = run_tests

# Paths
LIBFT_DIR = ../libft
LIBFT     = $(LIBFT_DIR)/libft.a
HEADERS   = -I$(LIBFT_DIR)

# Source discovery (all test .c files)
SRC       = $(wildcard */*.c)
OBJ       = $(SRC:.c=.o)

# Linker flags for Criterion (Linux: add -lgcov, macOS: no gcov needed)
LDFLAGS   = -L$(LIBFT_DIR) -lft -lcriterion -lgcov

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(HEADERS) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
