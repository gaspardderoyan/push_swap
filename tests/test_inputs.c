#include "../unity/unity.h"
#include "../inc/project.h"

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

/* ************************************************************************** */
/*   SINGLE STRING                                                            */
/* ************************************************************************** */

void	test_lst_from_str_normal(void)
{
	t_dlist	*lst = NULL;
	char	*str = "1 2 3 4 5 6 7 8 9 10";
	int		arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int		len = sizeof(arr) / sizeof(arr[0]);

	lst_from_str(str, &lst);
	int i = 0;
	while (i < len && lst)
	{
		if (arr[i] != *(int *)lst->content)
		{
			printf("%sFAIL: %s%s\n", COLOR_RED, __func__, COLOR_RESET);
			printf("Index = %d,  Expected = %d, Actual = %d\n", i, arr[i] , *(int *)lst->content);
			TEST_FAIL();
			return ;
		}
		i++;
		lst = lst->next;
	}
	printf("%sPASS: %s%s\n", COLOR_GREEN, __func__, COLOR_RESET);
}

void	test_lst_from_str_invalid_char(void)
{
	t_dlist	*lst = NULL;
	char	*str = "1 2 3 4 b";

	errno = 0;
	int expected_errno = 1;
	lst_from_str(str, &lst);
	if (errno != expected_errno)
	{
		printf("%sFAIL: %s%s\n", COLOR_RED, __func__, COLOR_RESET);
		printf("Errno: %d ; Expected: %d\n", errno, expected_errno);
		TEST_FAIL();
		return ;
	}
	printf("%sPASS: %s%s\n", COLOR_GREEN, __func__, COLOR_RESET);
}

void	test_lst_from_str_consecutive_space(void)
{
	t_dlist	*lst = NULL;
	char	*str = "1 2  3 4 5";

	errno = 0;
	int expected_errno = 5;
	lst_from_str(str, &lst);
	if (errno != expected_errno)
	{
		printf("%sFAIL: %s%s\n", COLOR_RED, __func__, COLOR_RESET);
		printf("Errno: %d ; Expected: %d\n", errno, expected_errno);
		TEST_FAIL();
		return ;
	}
	printf("%sPASS: %s%s\n", COLOR_GREEN, __func__, COLOR_RESET);
}

void	test_lst_from_str_start_space(void)
{
	t_dlist	*lst = NULL;
	char	*str = " 1 2 3 4 5";

	errno = 0;
	int expected_errno = 3;
	lst_from_str(str, &lst);
	if (errno != expected_errno)
	{
		printf("%sFAIL: %s%s\n", COLOR_RED, __func__, COLOR_RESET);
		printf("Errno: %d ; Expected: %d\n", errno, expected_errno);
		TEST_FAIL();
		return ;
	}
	printf("%sPASS: %s%s\n", COLOR_GREEN, __func__, COLOR_RESET);
}

void	test_lst_from_str_end_space(void)
{
	t_dlist	*lst = NULL;
	char	*str = "1 2 3 4 5 ";

	errno = 0;
	int expected_errno = 4;
	lst_from_str(str, &lst);
	if (errno != expected_errno)
	{
		printf("%sFAIL: %s%s\n", COLOR_RED, __func__, COLOR_RESET);
		printf("Errno: %d ; Expected: %d\n", errno, expected_errno);
		TEST_FAIL();
		return ;
	}
	printf("%sPASS: %s%s\n", COLOR_GREEN, __func__, COLOR_RESET);
}

void	test_lst_from_str_duplicate(void)
{
	t_dlist	*lst = NULL;
	char	*str = "1 2 3 4 5 5 7 8 9 10"; // two 5
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


/* ************************************************************************** */
/*   MULTIPLE STRINGS                                                            */
/* ************************************************************************** */

void	test_lst_from_strs_normal(void)
{
	// TODO why does it work when duplicate number?
	char	*str[] = {"OOPS", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", NULL};
	int		arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int		len = 10;
	t_dlist	*lst = NULL;

	lst_from_strs(11, str, &lst);
	int i = 0;
	while (i < len && lst)
	{
		if (arr[i] != *(int *)lst->content)
		{
			printf("%sFAIL: %s%s\n", COLOR_RED, __func__, COLOR_RESET);
			printf("Index = %d,  Expected = %d, Actual = %d\n", i, arr[i] , *(int *)lst->content);
			TEST_FAIL();
			return ;
		}
		i++;
		lst = lst->next;
	}
	printf("%sPASS: %s%s\n", COLOR_GREEN, __func__, COLOR_RESET);
}


void	test_lst_from_strs_invalid_char(void)
{

	char	*str = "1 2 3 b 5 6 7 8 9 10";
	char	**strs = ft_split(str, ' ');
	t_dlist	*lst = NULL;

	errno = 0;
	int expected_errno = 1;
	lst_from_strs(10, strs, &lst);
	if (errno != 1)
	{
		printf("%sFAIL: %s%s\n", COLOR_RED, __func__, COLOR_RESET);
		printf("Errno: %d ; Expected: %d\n", errno, expected_errno);
		TEST_FAIL();
		return ;
	}
	printf("%sPASS: %s%s\n", COLOR_GREEN, __func__, COLOR_RESET);
}

// void	test_lst_from_strs_int_max(void)
// {
// 	char	*str = "1 2 3 2147483647 5 6";
// 	char	**strs = ft_split(str, ' ');
// 	t_dlist	*lst = NULL;
// 	int		arr[] = {1, 2, 3, 2147483647, 5, 6};
//
// 	int expected_errno = 0;
//
// }

// TODO check for int max, but not more

int	main(void)
{
	UNITY_BEGIN();
	printf("Testing: lst_from_str\n");
	RUN_TEST(test_lst_from_str_normal);
	RUN_TEST(test_lst_from_str_invalid_char);
	RUN_TEST(test_lst_from_str_duplicate);
	RUN_TEST(test_lst_from_str_consecutive_space);
	RUN_TEST(test_lst_from_str_start_space);
	RUN_TEST(test_lst_from_str_end_space);
	printf("Testing: lst_from_strs\n");
	RUN_TEST(test_lst_from_strs_normal);
	RUN_TEST(test_lst_from_strs_invalid_char);
	UNITY_END();
}
