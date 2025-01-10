CC = cc
CFLAGS = -Wall -Wextra -Werror -Inc -Ilibft/inc
DEBUGFLAGS =

SRC_DIR = src
OBJ_DIR = obj
TEST_DIR = tests
TEST_OBJ_DIR = $(OBJ_DIR)/tests
UNITY_DIR = unity

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = double_lst.c \
	   list_addition.c \
	   list_manipulation.c \
	   list_utils.c \
	   algo.c

MAIN_SRC = main.c
# $(text:pattern=replacement)
# replaces .c by .o
MAIN_OBJ = $(MAIN_SRC:%.c=$(OBJ_DIR)/%.o)

# preprends 'obj/' to every .c file in SRCS (converted to .o)
# OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)

NAME = push_swap

TEST_SRCS = test_update_mt.c \
			test_dir_of_first.c
# TEST_OBJS = $(addprefix $(TEST_OBJ_DIR)/, $(TEST_SRCS:.c=.o))
# TEST_EXES = $(addprefix $(TEST_OBJ_DIR)/, $(TEST_SRCS:.c=))
TEST_EXES = $(TEST_SRCS:%.c=$(TEST_DIR)/%)

.PHONY: all clean fclean libft re

### MAIN ###

all: $(NAME)

# Build the main executable
$(NAME): $(MAIN_OBJ) $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(MAIN_OBJ) $(OBJS) -o $(NAME) -L$(LIBFT_DIR) -lft 

# Compile the object files for sources
# Static pattern rule
# Only applies to the file in OBJS (which are derived from SRCS) & MAIN_OBJ
# TODO look into $(@D)
# TODO use if statements instead of mkdir -p
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR) # @ so not printed
	$(CC) $(CFLAGS) -c $< -o $@

### TESTS ###

test: $(TEST_EXES)
	@for t in $^; do \
		$$t | sed '/^tests/d'; \
	done


# Test executables
$(TEST_DIR)/%: $(TEST_OBJ_DIR)/%.o $(OBJS) $(LIBFT) $(UNITY_DIR)/unity.o
	$(CC) $(TEST_CFLAGS) $^ -o $@

# $(TEST_EXES): $(TEST_OBJS) $(OBJS)
# 	$(CC) $(TEST_CFLAGS) $(@:$(TEST_DIR)/%=$(TEST_OBJ_DIR)/%.o) -o $@

# Compile object file for 
$(TEST_OBJ_DIR)/%.o: $(TEST_DIR)/%.c
	@mkdir -p $(TEST_OBJ_DIR)
	$(CC) $(TEST_CFLAGS) $(DEBUGFLAGS) -c $< -o $@

# Compile unity.c to unity.o
$(UNITY_DIR)/unity.o: $(UNITY_DIR)/unity.c $(UNITY_DIR)/unity.h $(UNITY_DIR)/unity_internals.h
	$(CC) $(TEST_CFLAGS) -c $< -o $@

### EXTRA ###

# Build libft
# -C to change to the libft dir, then runs 'make'
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
