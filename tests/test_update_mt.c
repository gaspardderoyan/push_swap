// tests/test_update_mt.c
#include "../inc/project.h"
#include <stdio.h>

// ANSI escape codes for colors
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define RESET   "\x1b[0m"
#define BOLD "\033[1m"

static void assert_equals_and_print(int expected_lower, int actual_lower, int expected_upper, int actual_upper, const char* func_name)
{
	if ((actual_lower) != (expected_lower) || (actual_upper) != (expected_upper))
	{
		printf("%sFAIL: %s%s\n", RED, func_name, RESET);
		printf("  lower_limit: Expected = %d, Actual = %d\n", (expected_lower), (actual_lower));
		printf("  upper_limit: Expected = %d, Actual = %d\n", (expected_upper), (actual_upper));
	}
	else
		printf("%sPASS: %s%s\n", GREEN, func_name, RESET);
}


void	test_update_mt_first_chunk(void)
{
    t_stacks_mt mt = { .chunks_i = 0, .chunks_count = 4, .lst_size = 20 };
    update_stacks_mt(&mt);
	assert_equals_and_print(0, mt.lower_limit, 4, mt.upper_limit, __func__);
}

void test_update_mt_mid_chunk()
{
    t_stacks_mt mt = { .chunks_i = 1, .chunks_count = 4, .lst_size = 20 };
    update_stacks_mt(&mt);
    assert_equals_and_print(5, mt.lower_limit, 9, mt.upper_limit, __func__);
}

void test_update_mt_last_chunk()
{
    t_stacks_mt mt = { .chunks_i = 3, .chunks_count = 4, .lst_size = 20 };
    update_stacks_mt(&mt);
    assert_equals_and_print(15, mt.lower_limit ,19, mt.upper_limit, __func__);
}

void test_update_mt_one_chunk()
{
    t_stacks_mt mt = { .chunks_i = 0, .chunks_count = 1, .lst_size = 20 };
    update_stacks_mt(&mt);
    assert_equals_and_print(0, mt.lower_limit, 19, mt.upper_limit, __func__);
}

void test_update_mt_zero_chunk()
{
    t_stacks_mt mt = { .chunks_i = 0, .chunks_count = 0, .lst_size = 20 };
    update_stacks_mt(&mt);
    assert_equals_and_print(0, mt.lower_limit, 0, mt.upper_limit, __func__);
}

void test_update_mt_zero_lst_size()
{
    t_stacks_mt mt = { .chunks_i = 0, .chunks_count = 4, .lst_size = 0 };
    update_stacks_mt(&mt);
    assert_equals_and_print(0, mt.lower_limit, 0, mt.upper_limit, __func__);
}

void test_update_mt_uneven_chunk_start()
{
    t_stacks_mt mt = { .chunks_i = 0, .chunks_count = 4, .lst_size = 21 };
    update_stacks_mt(&mt);
    assert_equals_and_print(0, mt.lower_limit, 4, mt.upper_limit, __func__);
}

void test_update_mt_uneven_chunk_end()
{
    t_stacks_mt mt = { .chunks_i = 3, .chunks_count = 4, .lst_size = 21 };
    update_stacks_mt(&mt);
    assert_equals_and_print(15, mt.lower_limit, 20, mt.upper_limit, __func__);
	// last chunk is larger (6 instead of 5)
}

int	main(void)
{
    printf(BOLD "\nUPDATE_MT\n" RESET);
	test_update_mt_first_chunk();
	test_update_mt_mid_chunk();
	test_update_mt_last_chunk();
	test_update_mt_one_chunk();
	test_update_mt_zero_chunk();
	test_update_mt_zero_lst_size();
	test_update_mt_uneven_chunk_start();
	test_update_mt_uneven_chunk_end();
	return (0);
}
