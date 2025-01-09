CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinc -Ilibft/inc
CFLAGS_TESTS = -Wall -Wextra -Werror -Iinc -Ilibft/inc -g3

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_DIR = src
OBJ_DIR = obj
TEST_DIR = tests

SRCS = double_lst.c \
	  list_addition.c \
	  list_manipulation.c \
	  list_utils.c \
	  algo.c \
	  program_logic.c \
	  main.c

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

TEST_SRCS = test_algo.c
TEST_OBJS = $(addprefix $(OBJ_DIR)/, $(TEST_SRCS:.c=.o))

NAME = push_swap
TEST_NAME = test_push_swap

.PHONY: all clean fclean re libft test

all: libft $(NAME)

# Build the main executable
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

# Compile object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c inc/project.h inc/program_logic.h
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -g3 -c $< -o $@

# Build libft
libft:
	$(MAKE) -C $(LIBFT_DIR)

# Compile tests' object files
$(OBJ_DIR)/%.o: $(TEST_DIR)/%.c inc/project.h
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS_TESTS) -c $< -o $@

# Build the test executable
$(TEST_NAME): $(TEST_OBJS) $(filter-out $(OBJ_DIR)/main.o, $(OBJS)) $(LIBFT)
	$(CC) $(CFLAGS_TESTS) $(TEST_OBJS) $(filter-out $(OBJ_DIR)/main.o, $(OBJS)) -L$(LIBFT_DIR) -lft -o $(TEST_NAME)

# Run all tests
test: $(TEST_NAME)
	./$(TEST_NAME) --all

# Run tests for a specific file (example for test_algo.c)
test_algo: $(TEST_NAME)
	./$(TEST_NAME) --file test_algo

# Run tests for a specific function (example for update_mt)
test_update_mt: $(TEST_NAME)
	./$(TEST_NAME) --function test_update_mt_

# Clean object files and libft
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

# Fully clean the project
fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)
	rm -f $(TEST_NAME)

# Rebuild the project
re: fclean all
