#include "../inc/project.h"

// ANSI escape codes for colors
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define RESET   "\x1b[0m"

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
	t_dlist *lst_cpy = lst;
	int i = 0;
	while (i < len && lst)
	{
		if (arr[i] != *(int *)lst->content)
		{
			printf("%sFAIL: %s%s\n", RED, __func__, RESET);
			printf("Index = %d,  Expected = %d, Actual = %d\n", i, arr[i] , *(int *)lst->content);
			ft_dlstfree(lst_cpy);
			return ;
		}
		i++;
		lst = lst->next;
	}
	printf("%sPASS: %s%s\n", GREEN, __func__, RESET);
	ft_dlstfree(lst_cpy);
}

void	test_lst_from_str_invalid_char(void)
{
	t_dlist	*lst = NULL;
	char	*str = "1 2 3 4 b";

	errno = 0;
	int expected_errno = 1;
	lst_from_str(str, &lst);
	t_dlist *lst_cpy = lst;
	if (errno != expected_errno)
	{
		printf("%sFAIL: %s%s\n", RED, __func__, RESET);
		printf("Errno: %d ; Expected: %d\n", errno, expected_errno);
		ft_dlstfree(lst_cpy);
		return ;
	}
	printf("%sPASS: %s%s\n", GREEN, __func__, RESET);
	ft_dlstfree(lst_cpy);
}

void	test_lst_from_str_consecutive_space(void)
{
	t_dlist	*lst = NULL;
	char	*str = "1 2  3 4 5";

	errno = 0;
	int expected_errno = 5;
	lst_from_str(str, &lst);
	t_dlist *lst_cpy = lst;
	if (errno != expected_errno)
	{
		printf("%sFAIL: %s%s\n", RED, __func__, RESET);
		printf("Errno: %d ; Expected: %d\n", errno, expected_errno);
		ft_dlstfree(lst_cpy);
		return ;
	}
	printf("%sPASS: %s%s\n", GREEN, __func__, RESET);
	ft_dlstfree(lst_cpy);
}

void	test_lst_from_str_start_space(void)
{
	t_dlist	*lst = NULL;
	char	*str = " 1 2 3 4 5";

	errno = 0;
	int expected_errno = 3;
	lst_from_str(str, &lst);
	t_dlist *lst_cpy = lst;
	if (errno != expected_errno)
	{
		printf("%sFAIL: %s%s\n", RED, __func__, RESET);
		printf("Errno: %d ; Expected: %d\n", errno, expected_errno);
		ft_dlstfree(lst_cpy);
		return ;
	}
	printf("%sPASS: %s%s\n", GREEN, __func__, RESET);
	ft_dlstfree(lst_cpy);
}

void	test_lst_from_str_end_space(void)
{
	t_dlist	*lst = NULL;
	char	*str = "1 2 3 4 5 ";

	errno = 0;
	int expected_errno = 4;
	lst_from_str(str, &lst);
	t_dlist *lst_cpy = lst;
	if (errno != expected_errno)
	{
		printf("%sFAIL: %s%s\n", RED, __func__, RESET);
		printf("Errno: %d ; Expected: %d\n", errno, expected_errno);
		ft_dlstfree(lst_cpy);
		return ;
	}
	printf("%sPASS: %s%s\n", GREEN, __func__, RESET);
	ft_dlstfree(lst_cpy);
}

void	test_lst_from_str_duplicate(void)
{
	t_dlist	*lst = NULL;
	char	*str = "1 2 3 4 5 5 7 8 9 10"; // two 5
	int		expected_len = 5;

	errno = 0;
	lst_from_str(str, &lst);
	t_dlist *lst_cpy = lst;
	int		actual_len = ft_dlstsize(lst);
	if (actual_len == expected_len && errno == 2)
	{
		printf("%sPASS: %s%s\n", GREEN, __func__, RESET);
		ft_dlstfree(lst_cpy);
	}
	else
{
		printf("%sFAIL: %s%s\n", RED, __func__, RESET);
		printf("Expected len: %d ; Actual: %d\n", expected_len, actual_len);
		printf("Expected errno: %d ; Actual: %d\n", 2, errno);
		ft_dlstfree(lst_cpy);
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
	t_dlist *lst_cpy = lst;
	int i = 0;
	while (i < len && lst)
	{
		if (arr[i] != *(int *)lst->content)
		{
			printf("%sFAIL: %s%s\n", RED, __func__, RESET);
			printf("Index = %d,  Expected = %d, Actual = %d\n", i, arr[i] , *(int *)lst->content);
			ft_dlstfree(lst_cpy);
			return ;
		}
		i++;
		lst = lst->next;
	}
	printf("%sPASS: %s%s\n", GREEN, __func__, RESET);
	ft_dlstfree(lst_cpy);
}


void	test_lst_from_strs_invalid_char(void)
{

	char	*str = "1 2 3 b 5 6 7 8 9 10";
	char	**strs = ft_split(str, ' ');
	t_dlist	*lst = NULL;

	errno = 0;
	int expected_errno = 1;
	lst_from_strs(10, strs, &lst);
	t_dlist *lst_cpy = lst;
	if (errno != 1)
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
	printf("\n\nTEST inputs\n\n");
	printf("Testing: lst_from_str\n");
	test_lst_from_str_normal();
	test_lst_from_str_invalid_char();
	test_lst_from_str_duplicate();
	test_lst_from_str_consecutive_space();
	test_lst_from_str_start_space();
	test_lst_from_str_end_space();
	printf("esting: lst_from_strs\n");
	test_lst_from_strs_normal();
	test_lst_from_strs_invalid_char();
}
