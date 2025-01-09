#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "../inc/project.h"

// ANSI escape codes for colors
#define RED_COLOR "\033[0;31m"
#define GREEN_COLOR "\033[0;32m"
#define RESET_COLOR "\033[0m"

// DECLARATIONS
bool test_failed;
void custom_assert_int(int expected, int actual, const char *test_name);

// ALL TESTS
void test_update_mt_first_chunk()
{
    t_stacks_mt mt = { .chunks_i = 0, .chunks_count = 4, .lst_size = 20 };
    update_mt(&mt);
    custom_assert_int(0, mt.lower_limit, "test_update_mt_first_chunk - lower_limit");
    custom_assert_int(4, mt.upper_limit, "test_update_mt_first_chunk - upper_limit");
}

void test_update_mt_mid_chunk()
{
    t_stacks_mt mt = { .chunks_i = 1, .chunks_count = 4, .lst_size = 20 };
    update_mt(&mt);
    custom_assert_int(5, mt.lower_limit, "test_update_mt_first_chunk - lower_limit");
    custom_assert_int(9, mt.upper_limit, "test_update_mt_first_chunk - upper_limit");
}

void test_update_mt_last_chunk()
{
    t_stacks_mt mt = { .chunks_i = 3, .chunks_count = 4, .lst_size = 20 };
    update_mt(&mt);
    custom_assert_int(15, mt.lower_limit, "test_update_mt_first_chunk - lower_limit");
    custom_assert_int(19, mt.upper_limit, "test_update_mt_first_chunk - upper_limit");
}

void test_update_mt_one_chunk()
{
    t_stacks_mt mt = { .chunks_i = 0, .chunks_count = 1, .lst_size = 20 };
    update_mt(&mt);
    custom_assert_int(0, mt.lower_limit, "test_update_mt_one_chunk - lower_limit");
    custom_assert_int(19, mt.upper_limit, "test_update_mt_one_chunk - upper_limit");
}

void test_update_mt_zero_chunk()
{
    t_stacks_mt mt = { .chunks_i = 0, .chunks_count = 0, .lst_size = 20 };
    update_mt(&mt);
    custom_assert_int(0, mt.lower_limit, "test_update_mt_zero_chunk - lower_limit");
    custom_assert_int(0, mt.upper_limit, "test_update_mt_zero_chunk - upper_limit");
}

void test_update_mt_zero_lst_size()
{
    t_stacks_mt mt = { .chunks_i = 0, .chunks_count = 4, .lst_size = 0 };
    update_mt(&mt);
    custom_assert_int(0, mt.lower_limit, "test_update_mt_zero_lst_size - lower_limit");
    custom_assert_int(0, mt.upper_limit, "test_update_mt_zero_lst_size - upper_limit");
}

void test_update_mt_uneven_chunk_start()
{
    t_stacks_mt mt = { .chunks_i = 0, .chunks_count = 4, .lst_size = 21 };
    update_mt(&mt);
    custom_assert_int(0, mt.lower_limit, "test_update_mt_uneven_chunk_start - lower_limit");
    custom_assert_int(4, mt.upper_limit, "test_update_mt_uneven_chunk_start - upper_limit");
}

void test_update_mt_uneven_chunk_end()
{
    t_stacks_mt mt = { .chunks_i = 3, .chunks_count = 4, .lst_size = 21 };
    update_mt(&mt);
    custom_assert_int(15, mt.lower_limit, "test_update_mt_uneven_chunk_start - lower_limit");
    custom_assert_int(20, mt.upper_limit, "test_update_mt_uneven_chunk_start - upper_limit");
	// last chunk is larger (6)
}

// TYPE BASED TEST FUNCTIONS
void custom_assert_int(int expected, int actual, const char *test_name) {
    if (expected != actual) {
        printf("%s%s: FAILED%s\n", RED_COLOR, test_name, RESET_COLOR);
        printf("%sExpected: %d, Actual: %d%s\n", RED_COLOR, expected, actual, RESET_COLOR);
        test_failed = true;
    }
}

// LIST OF TESTS
typedef struct {
    const char *name;
    void (*func)(void);
} test_func_t;

test_func_t all_tests[] = {
    {"test_update_mt_first_chunk", test_update_mt_first_chunk},
    {"test_update_mt_mid_chunk", test_update_mt_mid_chunk},
    {"test_update_mt_last_chunk", test_update_mt_last_chunk},
    {"test_update_mt_one_chunk", test_update_mt_one_chunk},
    {"test_update_mt_zero_chunk", test_update_mt_zero_chunk},
    {"test_update_mt_zero_lst_size", test_update_mt_zero_lst_size},
    {"test_update_mt_uneven_chunk_start", test_update_mt_uneven_chunk_start},
    {"test_update_mt_uneven_chunk_end", test_update_mt_uneven_chunk_end},
    {NULL, NULL}
};

// FUNCTION TO RUN TEST & PRINT SUCCESS
void run_test(test_func_t test) {
    // printf("Running: %s\n", test.name);
    test_failed = false;
    test.func();
    if (test_failed) {
        printf("%s%s: FAILED%s\n", RED_COLOR, test.name, RESET_COLOR);
    } else {
        printf("%s%s: PASSED%s\n", GREEN_COLOR, test.name, RESET_COLOR);
    }
}

int main()
{
    int passed_count = 0;
    int failed_count = 0;

    for (int i = 0; all_tests[i].name != NULL; i++)
	{
		run_test(all_tests[i]);
		if (test_failed)
			failed_count++;
		else
			passed_count++;
	}

    printf("\nSummary:\n");
    printf("Tests Passed: %s%d%s\n", GREEN_COLOR, passed_count, RESET_COLOR);
    printf("Tests Failed: %s%d%s\n", RED_COLOR, failed_count, RESET_COLOR);

    return failed_count > 0 ? 1 : 0;
}
