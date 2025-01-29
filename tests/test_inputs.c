#include "../inc/project.h"
#include <string.h>

// ANSI escape codes for colors
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define RESET   "\x1b[0m"
#define BOLD "\033[1m"

/* ************************************************************************** */
/*   SINGLE STRING                                                            */
/* ************************************************************************** */

int		*arr_from_strs(char **strs)
{
	int	len = ft_count_strs(strs);
	int	*arr = malloc(sizeof(int) * len);
	if (!arr)
		return (NULL);
	for (int i = 0; i < len; i++)
		*(arr + i) = mini_strtoll(strs[i], 10);
	return (arr);
}

void	test_lst_from_str(char *name, char *str, int *arr)
{
	t_mst	mst = { .a = NULL, .b = NULL };
	char	**strs = ft_split_cs(str, "\t\n\v\f\r ");
	lst_from_str(strs, &mst);
	t_dlist	*head = mst.a;
	ft_free_strs(strs);
	int	i = 0;
	errno = 0;
	while (mst.a)
	{
		if (*(arr + i) != *(int *)mst.a->content)
		{
			printf("%sFAIL: %s%s\n", RED, name, RESET);
			printf("Index = %d,  Expected = %d, Actual = %d\n", i, *(arr + i), *(int *)mst.a->content);
			ft_dlstfree(head);
			return ;
		}
		if (errno)
		{
			printf("%sFAIL: %s%s\n", RED, name, RESET);
			printf("Errno = %d,  Expected = %d\n", errno, 0);
			ft_dlstfree(head);
			return ;
		}
		mst.a = mst.a->next;
		i++;
	}
	printf("%sPASS: %s%s\n", GREEN, name, RESET);
	ft_dlstfree(head);
}

void	test_lst_from_str_error(char *name, char *str, int expected_errno)
{
	t_mst	mst = { .a = NULL, .b = NULL };
	char	**strs = ft_split_cs(str, "\t\n\v\f\r ");

	errno = 0;
	lst_from_str(strs, &mst);
	ft_free_strs(strs);
	if (errno != expected_errno)
	{
		printf("%sFAIL: %s%s\n", RED, name, RESET);
		printf("Errno: %d ; Expected: %d\n", errno, expected_errno);
		ft_dlstfree(mst.a);
		return ;
	}
	printf("%sPASS: %s%s\n", GREEN, name, RESET);
	ft_dlstfree(mst.a);
}

void	test_lst_from_str_duplicate(void)
{
	char	*str = "1 2 3 4 5 5 7 8 9 10"; // two 5
	int		expected_len = 5;

	errno = 0;
	t_mst	mst;
	mst.a = NULL;
	char **strs = ft_split_cs(str, "\t\n\v\f\r ");
	lst_from_str(strs, &mst);
	t_dlist *lst_cpy = mst.a;
	int		actual_len = ft_dlstsize(mst.a);
	if (actual_len == expected_len && errno == DUPLICATE_VALUE)
	{
		printf("%sPASS: %s%s\n", GREEN, __func__, RESET);
		ft_dlstfree(lst_cpy);
		ft_free_strs(strs);
	}
	else
	{
		printf("%sFAIL: %s%s\n", RED, __func__, RESET);
		printf("Expected len: %d ; Actual: %d\n", expected_len, actual_len);
		printf("Expected errno: %d ; Actual: %d\n", DUPLICATE_VALUE, errno);
		ft_dlstfree(lst_cpy);
		ft_free_strs(strs);
	}
}


/* ************************************************************************** */
/*   MULTIPLE STRINGS                                                            */
/* ************************************************************************** */

void	test_lst_from_strs(char *name, char **strs, int *arr)
{
	t_mst	mst = { .a = NULL, .b = NULL};
	int ac = ft_count_strs(strs);
	ft_printf("ac = %d\n", ac);
	lst_from_strs(ac, strs, &mst);
	t_dlist	*head = mst.a;
	int	i = 1;
	errno = 0;
	// TODO this loop is never entered, mst.a seems null, but idk why;
	// printf("Index = %d,  Expected = %d, Actual = %d\n", i, *(arr + i), *(int *)(mst.a)->content);
	while (mst.a)
	{
		printf("Index = %d,  Expected = %d, Actual = %d\n", i, *(arr + i), *(int *)mst.a->content);
		if (*(arr + i + 3) != *(int *)mst.a->content)
		{
			printf("%sFAIL: %s%s\n", RED, name, RESET);
			printf("Index = %d,  Expected = %d, Actual = %d\n", i, *(arr + i), *(int *)mst.a->content);
			ft_dlstfree(head);
			return ;
		}
		if (errno)
		{
			printf("%sFAIL: %s%s\n", RED, name, RESET);
			printf("Errno = %d,  Expected = %d\n", errno, 0);
			ft_dlstfree(head);
			return ;
		}
		mst.a = mst.a->next;
		i++;
	}
	printf("%sPASS: %s%s\n", GREEN, name, RESET);
	ft_dlstfree(head);
}

void	test_lst_from_strs_normal(void)
{
	char	*str[] = {"OOPS", "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", NULL};
	int		arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int		len = 10;
	t_mst	mst;
	mst.a = NULL;

	lst_from_strs(11, str, &mst);
	t_dlist *lst_cpy = mst.a;
	int i = 0;
	while (i < len && mst.a)
	{
		if (arr[i] != *(int *)mst.a->content)
		{
			printf("%sFAIL: %s%s\n", RED, __func__, RESET);
			printf("Index = %d,  Expected = %d, Actual = %d\n", i, arr[i] , *(int *)mst.a->content);
			ft_dlstfree(lst_cpy);
			return ;
		}
		i++;
		mst.a = mst.a->next;
	}
	printf("%sPASS: %s%s\n", GREEN, __func__, RESET);
	ft_dlstfree(lst_cpy);
}


void	test_lst_from_strs_invalid_char(void)
{

	char	*str = "1 2 3 b 5 6 7 8 9 10";
	char	**strs = ft_split(str, ' ');

	t_mst	mst;
	mst.a = NULL;
	errno = 0;
	int expected_errno = 22;
	lst_from_strs(10, strs, &mst);
	t_dlist *lst_cpy = mst.a;
	if (errno != expected_errno)
	{
		printf("%sFAIL: %s%s\n", RED, __func__, RESET);
		printf("Errno: %d ; Expected: %d\n", errno, expected_errno);
		ft_free_strs(strs);
		ft_dlstfree(lst_cpy);
		return ;
	}
	printf("%sPASS: %s%s\n", GREEN, __func__, RESET);
	ft_free_strs(strs);
	ft_dlstfree(lst_cpy);
}

int	main(void)
{
    printf(BOLD "\nINPUTS\n" RESET);
    printf(BOLD "lst_from_str\n" RESET);
	test_lst_from_str(
		"normal",
		"1 2 3 4 5",
		(int []){1, 2, 3, 4, 5}
	);
	test_lst_from_str(
		"int_max/min",
		"1 2 3 2147483647 -2147483648 4",
		(int []){1, 2, 3, INT_MAX, INT_MIN, 4}
	);
	test_lst_from_str(
		"bunch of spaces/tabs/etc",
		"  1 2 3 4\t \r 5 ",
		(int []){1, 2, 3, 4, 5}
	);
	test_lst_from_str_error(
		"invalid char",
		"1 2 3 4 b 5",
		EINVAL
	);
	test_lst_from_str_error(
		"duplicate number",
		"1 2 3 4 4 6",
		DUPLICATE_VALUE
	);
	test_lst_from_str_error(
		"above int max",
		"1 2 3 21474836487 4",
		ERANGE
	);
	test_lst_from_str_error(
		"under int min",
		"1 2 3 -2147483649 4",
		ERANGE
	);
	printf(BOLD "lst_from_strs\n" RESET);
	char *strs[] = {"TEST", "1", "2", "3", "4", "5", NULL};
	test_lst_from_strs(
		"normal",
		strs,
		(int []){1, 2, 3, 4, 6}
	);
}
