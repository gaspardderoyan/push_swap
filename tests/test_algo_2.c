#include "../unity/unity.h"
#include "../inc/project.h"

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
	TEST_ASSERT_EQUAL_INT(0, mt.lower_limit);
	TEST_ASSERT_EQUAL_INT(4, mt.upper_limit);
}

void test_update_mt_mid_chunk()
{
    t_stacks_mt mt = { .chunks_i = 1, .chunks_count = 4, .lst_size = 20 };
    update_mt(&mt);
    TEST_ASSERT_EQUAL_INT(5, mt.lower_limit);
    TEST_ASSERT_EQUAL_INT(9, mt.upper_limit);
}

void test_update_mt_last_chunk()
{
    t_stacks_mt mt = { .chunks_i = 3, .chunks_count = 4, .lst_size = 20 };
    update_mt(&mt);
    TEST_ASSERT_EQUAL_INT(15, mt.lower_limit);
    TEST_ASSERT_EQUAL_INT(19, mt.upper_limit);
}

void test_update_mt_one_chunk()
{
    t_stacks_mt mt = { .chunks_i = 0, .chunks_count = 1, .lst_size = 20 };
    update_mt(&mt);
    TEST_ASSERT_EQUAL_INT(0, mt.lower_limit);
    TEST_ASSERT_EQUAL_INT(19, mt.upper_limit);
}

void test_update_mt_zero_chunk()
{
    t_stacks_mt mt = { .chunks_i = 0, .chunks_count = 0, .lst_size = 20 };
    update_mt(&mt);
    TEST_ASSERT_EQUAL_INT(0, mt.lower_limit);
    TEST_ASSERT_EQUAL_INT(0, mt.upper_limit);
}

void test_update_mt_zero_lst_size()
{
    t_stacks_mt mt = { .chunks_i = 0, .chunks_count = 4, .lst_size = 0 };
    update_mt(&mt);
    TEST_ASSERT_EQUAL_INT(0, mt.lower_limit);
    TEST_ASSERT_EQUAL_INT(0, mt.upper_limit);
}

void test_update_mt_uneven_chunk_start()
{
    t_stacks_mt mt = { .chunks_i = 0, .chunks_count = 4, .lst_size = 21 };
    update_mt(&mt);
    TEST_ASSERT_EQUAL_INT(0, mt.lower_limit);
    TEST_ASSERT_EQUAL_INT(4, mt.upper_limit);
}

void test_update_mt_uneven_chunk_end()
{
    t_stacks_mt mt = { .chunks_i = 3, .chunks_count = 4, .lst_size = 21 };
    update_mt(&mt);
    TEST_ASSERT_EQUAL_INT(15, mt.lower_limit);
    TEST_ASSERT_EQUAL_INT(20, mt.upper_limit);
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
