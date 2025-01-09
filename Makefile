CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinc -Ilibft/inc
DEBUGFLAGS = -g3
TEST_CFLAGS = $(CFLAGS) -Iunity

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_DIR = src
OBJ_DIR = obj
TEST_DIR = tests
TEST_OBJ_DIR = $(OBJ_DIR)/tests
UNITY_DIR = unity

SRCS = double_lst.c \
	list_addition.c \
	list_manipulation.c \
	list_utils.c \
	algo.c

MAIN_SRC = main.c
MAIN_OBJ = $(OBJ_DIR)/$(MAIN_SRC:.c=.o)

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

NAME = push_swap

# List test source files explicitly without wildcards
TEST_SRCS = $(TEST_DIR)/test_update_mt.c \
			$(TEST_DIR)/test_dir_of_first.c
TEST_NAMES = test_update_mt test_dir_of_first
TEST_OBJS = $(addprefix $(TEST_OBJ_DIR)/, $(SRCS:.c=.o)) $(addprefix $(TEST_OBJ_DIR)/, $(notdir $(TEST_SRCS:.c=.o)))
TEST_EXES = $(addprefix $(TEST_DIR)/, $(TEST_NAMES))

.PHONY: all clean fclean re libft test test_

all: libft $(NAME)

# Build the main executable
$(NAME): $(MAIN_OBJ) $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(MAIN_OBJ) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

# Compile main.c
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c inc/project.h
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(DEBUGFLAGS) -c $< -o $@

# Compile object files for sources (without Unity include)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c inc/project.h
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(DEBUGFLAGS) -c $< -o $@

# Compile object files for tests (sources) (with Unity include)
$(TEST_OBJ_DIR)/%.o: $(SRC_DIR)/%.c inc/project.h
	@mkdir -p $(TEST_OBJ_DIR)
	$(CC) $(TEST_CFLAGS) $(DEBUGFLAGS) -c $< -o $@

# Compile object files for tests (tests) (with Unity include)
$(TEST_OBJ_DIR)/%.o: $(TEST_DIR)/%.c inc/project.h unity/unity.h
	@mkdir -p $(TEST_OBJ_DIR)
	$(CC) $(TEST_CFLAGS) $(DEBUGFLAGS) -c $< -o $@

# Build libft
libft:
	$(MAKE) -C $(LIBFT_DIR)

# Compile and run all tests
test: | libft $(TEST_EXES)
	@$(foreach test,$(TEST_EXES),./$(test) | sed '/^tests/d';)

# Build individual test executables
$(TEST_DIR)/%: $(TEST_OBJ_DIR)/%.o $(OBJS) $(LIBFT) $(UNITY_DIR)/unity.o
	$(CC) $(TEST_CFLAGS) $^ -L$(LIBFT_DIR) -lft -o $@

# Compile unity.c
$(UNITY_DIR)/unity.o: $(UNITY_DIR)/unity.c $(UNITY_DIR)/unity.h $(UNITY_DIR)/unity_internals.h
	$(CC) $(TEST_CFLAGS) -c $< -o $@

# Clean object files and libft
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

# Fully clean the project
fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)
	rm -f $(TEST_EXES)

# Rebuild the project
re: fclean all
