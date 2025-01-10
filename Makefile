CC = cc
CFLAGS = -Wall -Wextra -Werror -Inc -Ilibft/inc
DEBUGFLAGS =

SRC_DIR = src
OBJ_DIR = obj
TEST_DIR = tests
TEST_OBJ_DIR = $(OBJ_DIR)/tests

UNITY_DIR = unity
UNITY = $(UNITY_DIR)/unity.o

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = double_lst.c \
	   list_addition.c \
	   list_manipulation.c \
	   list_utils.c \
	   algo.c
MAIN_SRC = main.c

# $(text:pattern=replacement)
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)
MAIN_OBJ = $(MAIN_SRC:%.c=$(OBJ_DIR)/%.o)

NAME = push_swap

TEST_SRCS = test_update_mt.c \
			test_dir_of_first.c

TEST_EXES = $(TEST_SRCS:%.c=$(TEST_DIR)/%)

.PHONY: all clean fclean libft re test test_%

################################################################################
# Main Build Targets
################################################################################

all: $(NAME)

# Build the main executable
$(NAME): $(MAIN_OBJ) $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(MAIN_OBJ) $(OBJS) -o $(NAME) -L$(LIBFT_DIR) -lft 

# Compile the object files for main sources
# TODO use if statement > -p
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR) # @ so not printed
	$(CC) $(CFLAGS) -c $< -o $@

################################################################################
# Test Build Targets
################################################################################

# Run all test executables and filter out Unity's header output
test: $(TEST_EXES)
	@for t in $^; do \
		$$t | sed '/^tests/d'; \
	done

# Pattern rule for individual test targets
test_%: $(TEST_OBJ_DIR)/test_%.o $(OBJS) $(LIBFT) $(UNITY)
	@$(CC) $(TEST_CFLAGS) $^ -o $(TEST_DIR)/$*
	@$(TEST_DIR)/$* | sed '/^tests/d'

# Build test executables
$(TEST_DIR)/%: $(TEST_OBJ_DIR)/%.o $(OBJS) $(LIBFT) $(UNITY)
	$(CC) $(TEST_CFLAGS) $^ -o $@

# Compile object file for test sources
$(TEST_OBJ_DIR)/%.o: $(TEST_DIR)/%.c
	@mkdir -p $(TEST_OBJ_DIR)
	$(CC) $(TEST_CFLAGS) $(DEBUGFLAGS) -c $< -o $@


# Compile Unity framework
$(UNITY): $(UNITY_DIR)/unity.c $(UNITY_DIR)/unity.h $(UNITY_DIR)/unity_internals.h
	$(CC) $(TEST_CFLAGS) -c $< -o $@

################################################################################
# Helper Targets (clean, fclean, re)
################################################################################

# Build libft
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Clean object files and libft's objs
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)

# + executables
fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME)


# Rebuild the project
re: fclean all

