# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gderoyqn <gderoyqn@student.42london.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/13 18:49:48 by gderoyqn          #+#    #+#              #
#    Updated: 2025/03/12 17:55:36 by gderoyqn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -Inc -Ilibft/inc
DEBUGFLAGS = -g3 -fsanitize=address -fsanitize=undefined -fsanitize=alignment

# Define the default algorithm
ALGO ?= "chunk"

# Compiler flags
CFLAGS += -D ALGO=\"$(ALGO)\"

SRC_DIR = src
OBJ_DIR = obj
TEST_DIR = tests
TEST_OBJ_DIR = $(OBJ_DIR)/tests

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = inputs.c \
	   operations.c \
	   utils.c \
	   algo_utils.c \
	   chunk_sort.c \
	   small_sort.c
MAIN_SRC = main.c

# $(text:pattern=replacement)
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o)
MAIN_OBJ = $(MAIN_SRC:%.c=$(OBJ_DIR)/%.o)

NAME = push_swap

TEST_SRCS = test_dir_of_first.c \
			test_ft_strtoll.c \
			test_ft_split_cs.c \
			test_update_mt.c \
			test_operations.c \
			test_iterative_min_sort.c \
			test_inputs.c \
			test_small_sort.c

TEST_EXES = $(TEST_SRCS:%.c=$(TEST_DIR)/%)

.PHONY: all clean fclean libft re test test_%

################################################################################
# Main Build Targets
################################################################################

all: $(NAME)

# Build the main executable
$(NAME): $(MAIN_OBJ) $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(MAIN_OBJ) $(OBJS) $(DEBUGFLAGS) -o $(NAME) -L$(LIBFT_DIR) -lft 

# Compile the object files for main sources
# TODO use if statement > -p
$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR) # @ so not printed
	$(CC) $(CFLAGS) $(DEBUGFLAGS) -c $< -o $@

################################################################################
# Test Build Targets
################################################################################

# Run all test executables and filter out Unity's header output
test: $(TEST_EXES)
	@for t in $^; do \
		$$t ; \
	done

# Pattern rule for individual test targets
test_%: $(TEST_OBJ_DIR)/test_%.o $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(DEBUGFLAGS) $^ -o $(TEST_DIR)/test_$*
	$(TEST_DIR)/test_$*

# Build test executables
$(TEST_DIR)/test_%: $(TEST_OBJ_DIR)/test_%.o $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(DEBUGFLAGS) $^ -o $@

.PRECIOUS: $(TEST_OBJ_DIR)/%.o

# Compile object file for test sources
$(TEST_OBJ_DIR)/test_%.o: $(TEST_DIR)/test_%.c
	@mkdir -p $(TEST_OBJ_DIR)
	$(CC) $(CFLAGS) $(DEBUGFLAGS) -c $< -o $@

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

# TODO clean test executables
# + executables
fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(NAME) $(TEST_EXES)

# Rebuild the project
re: fclean all
