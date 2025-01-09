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
		TEST_FAIL();
	}
	else
		printf("%sPASS: %s%s\n", COLOR_GREEN, func_name, COLOR_RESET);
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

void test_update_mt_last_chunk()
{
    t_stacks_mt mt = { .chunks_i = 3, .chunks_count = 4, .lst_size = 20 };
    update_mt(&mt);
    assert_equals_and_print(15, mt.lower_limit ,19, mt.upper_limit, __func__);
}

void test_update_mt_one_chunk()
{
    t_stacks_mt mt = { .chunks_i = 0, .chunks_count = 1, .lst_size = 20 };
    update_mt(&mt);
    assert_equals_and_print(0, mt.lower_limit, 19, mt.upper_limit, __func__);
}

void test_update_mt_zero_chunk()
{
    t_stacks_mt mt = { .chunks_i = 0, .chunks_count = 0, .lst_size = 20 };
    update_mt(&mt);
    assert_equals_and_print(0, mt.lower_limit, 0, mt.upper_limit, __func__);
}

void test_update_mt_zero_lst_size()
{
    t_stacks_mt mt = { .chunks_i = 0, .chunks_count = 4, .lst_size = 0 };
    update_mt(&mt);
    assert_equals_and_print(0, mt.lower_limit, 0, mt.upper_limit, __func__);
}

void test_update_mt_uneven_chunk_start()
{
    t_stacks_mt mt = { .chunks_i = 0, .chunks_count = 4, .lst_size = 21 };
    update_mt(&mt);
    assert_equals_and_print(0, mt.lower_limit, 4, mt.upper_limit, __func__);
}

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
	RUN_TEST(test_update_mt_last_chunk);
	RUN_TEST(test_update_mt_one_chunk);
	RUN_TEST(test_update_mt_zero_chunk);
	RUN_TEST(test_update_mt_zero_lst_size);
	RUN_TEST(test_update_mt_uneven_chunk_start);
	RUN_TEST(test_update_mt_uneven_chunk_end);
	return (UNITY_END());
}
