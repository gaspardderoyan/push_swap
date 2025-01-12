# Makefile

```makefile
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinc -Ilibft/inc

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC_DIR = src
OBJ_DIR = obj
TEST_DIR = tests

# TODO Maybe put main.c apart, so that no issue with tests?
SRCS = double_lst.c \
	  list_addition.c \
	  list_manipulation.c \
	  list_utils.c \
	  algo.c \
	  main.c

OBJS = $(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))

NAME = push_swap

.PHONY: all clean fclean re libft

all: libft $(NAME)

# Build the main executable
$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

# Compile object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c inc/project.h 
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -g3 -c $< -o $@

# Build libft
libft:
	$(MAKE) -C $(LIBFT_DIR)

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
```

# Dir struct

├── compile_commands.json
├── gen.py
├── inc
│   ├── double_lst.h
│   └── project.h
├── instructions.md
├── libft
│   ├── inc
│   ├── libft.a
│   ├── Makefile
│   ├── obj
│   └── src
├── Makefile
├── obj
│   ├── algo.o
│   ├── double_lst.o
│   ├── list_addition.o
│   ├── list_manipulation.o
│   ├── list_utils.o
│   └── main.o
├── src
│   ├── algo.c
│   ├── double_lst.c
│   ├── list_addition.c
│   ├── list_manipulation.c
│   ├── list_utils.c
│   └── main.c
├── tests
│   ├── test_dir_of_first.c
│   └── test_update_mt.c
└── unity
    ├── unity.c
    ├── unity.h
    └── unity_internals.h

10 directories, 25 files


# Example test file

```c
// tests/test_update_mt.c
#include "../unity/unity.h"
#include "../inc/project.h"
#include <stdio.h>

// ANSI escape codes for colors
#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_RESET   "\x1b[0m"

static void assert_equals_and_print(int expected_lower, int actual_lower, int expected_upper, int actual_upper, const char* func_name)
{
	if ((actual_lower) != (expected_lower) || (actual_upper) != (expected_upper))
	{
	printf("%sFAIL: %s%s\n", COLOR_RED, func_name, COLOR_RESET);
	printf("  lower_limit: Expected = %d, Actual = %d\n", (expected_lower), (actual_lower));
	printf("  upper_limit: Expected = %d, Actual = %d\n", (expected_upper), (actual_upper));
	}
	else
	{
		printf("%sPASS: %s%s\n", COLOR_GREEN, func_name, COLOR_RESET);
		TEST_FAIL();
	}
}

void setUp(void)
{
    // set stuff up here
}

void tearDown(void)
{
    // clean stuff up here
}

void	test_update_mt_first_chunk(void)
{
    t_stacks_mt mt = { .chunks_i = 0, .chunks_count = 4, .lst_size = 20 };
    update_mt(&mt);
	assert_equals_and_print(0, mt.lower_limit, 4, mt.upper_limit, __func__);
}

void test_update_mt_mid_chunk()
{
    t_stacks_mt mt = { .chunks_i = 1, .chunks_count = 4, .lst_size = 20 };
    update_mt(&mt);
    assert_equals_and_print(5, mt.lower_limit, 9, mt.upper_limit, __func__);
}

// other test functions

void test_update_mt_uneven_chunk_end()
{
    t_stacks_mt mt = { .chunks_i = 3, .chunks_count = 4, .lst_size = 21 };
    update_mt(&mt);
    assert_equals_and_print(15, mt.lower_limit, 20, mt.upper_limit, __func__);
	// last chunk is larger (6 instead of 5)
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_update_mt_first_chunk);
	RUN_TEST(test_update_mt_mid_chunk);
    // other test functions
	RUN_TEST(test_update_mt_uneven_chunk_end);
	return (UNITY_END());
}
```

# Query

> How would I change my Makefile so that I can use it to compile normally (eg. make or make all), but also compile all the tests and run them all (eg. make test), or compile and run just a specific test (eg make test_udpate_mt)?
- Be careful, as I have a main function in my `main.c` file, so it shouldn't be compiled together with any of the test files. However, the test files do need all the other sources (SRCS).
- What would be different ways to do this? Give me pros/cons/simplicity/complexity/recommandation
