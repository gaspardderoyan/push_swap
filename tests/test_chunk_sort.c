#include "../unity/unity.h"
#include "../inc/project.h"
#include <stdio.h>

// ANSI escape codes for colors
#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_RESET   "\x1b[0m"

void setUp(void)
{
    // set stuff up here
}

void tearDown(void)
{
    // clean stuff up here
}

// TEST SINGLE STRING

void assert_correct_lst(int *expected, t_dlist *actual, int len, const char *func_name)
{
	int	i = 0;
	while (i < len && actual)
	{
		if (expected[i] != *(int *)actual->content)
		{
			printf("%sFAIL: %s%s\n", COLOR_RED, func_name, COLOR_RESET);
			printf("Index = %d,  Expected = %d, Actual = %d\n", i, expected[i] , *(int *)actual->content);
			TEST_FAIL();
			return ;
		}
		i++;
		actual = actual->next;
	}
	printf("%sPASS: %s%s\n", COLOR_GREEN, func_name, COLOR_RESET);
}

void	test_lst_from_str_normal(void)
{
	t_dlist	*lst = NULL;
	char	str[] = "1 2 3 4 5 6 7 8 9 10";
	int		arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int		len = sizeof(arr) / sizeof(arr[0]);

	lst_from_str(str, &lst);
	assert_correct_lst(arr, lst, len, __func__);
}

void	test_lst_from_str_invalid_char(void)
{
	t_dlist	*lst = NULL;
	char	str[] = "1 2 3 4 b";

	errno = 0;
	lst_from_str(str, &lst);
	if (errno != 1)
	{
		printf("%sFAIL: %s%s\n", COLOR_RED, __func__, COLOR_RESET);
		printf("Errno: %d ; Expected: %d\n", errno, 1);
		TEST_FAIL();
		return ;
	}
	printf("%sPASS: %s%s\n", COLOR_GREEN, __func__, COLOR_RESET);
}

void	test_lst_from_str_duplicate(void)
{
	t_dlist	*lst = NULL;
	char	str[] = "1 2 3 4 5 5 7 8 9 10"; // two 5
	int		expected_len = 5;

	errno = 0;
	lst_from_str(str, &lst);
	int		actual_len = ft_dlstsize(lst);
	if (actual_len == expected_len && errno == 2)
	{
		printf("%sPASS: %s%s\n", COLOR_GREEN, __func__, COLOR_RESET);
	}
	else
	{
		printf("%sFAIL: %s%s\n", COLOR_RED, __func__, COLOR_RESET);
		printf("Expected len: %d ; Actual: %d\n", expected_len, actual_len);
		printf("Expected errno: %d ; Actual: %d\n", 2, errno);
		TEST_FAIL();
	}
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_lst_from_str_normal);
	RUN_TEST(test_lst_from_str_invalid_char);
	RUN_TEST(test_lst_from_str_duplicate);
	UNITY_END();
}
