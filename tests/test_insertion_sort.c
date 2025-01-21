#include "../inc/project.h"

// ANSI escape codes for colors
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define RESET   "\x1b[0m"
#define BOLD	"\033[1m"

// Macro to calculate the size of the array and call the function
#define DLIST_FROM_ARR(arr) _dlst_from_arr(arr, sizeof(arr) / sizeof((arr)[0]))

// Modified function to create a doubly linked list from an array
static t_dlist *_dlst_from_arr(int *arr, size_t size)
{
    t_dlist *new = NULL;
    if (arr == NULL)
	{
        return NULL; // Handle null array input
    }
    for (size_t i = 0; i < size; i++)
	{
        add_nbr_to_lst(&new, arr[i]);
    }
    return new;
}

void	is_dlist_sorted(t_dlist *lst, char *name, int ops)
{
	int	current;

	current = *(int *)lst->content;
	while (lst)
	{
		current = *(int *)lst->content;
		lst = lst->next;
		if (lst && *(int *)lst->content < current)
		{
			printf(RED "\n  Failed: " RESET);
			printf("  Current = %d, ", *(int *)lst->content);
			printf("Previous = %d\n", current);
			return ;
		}
	}
	printf("%sPASS: %s%s Ops = %d\n", GREEN, name, RESET, ops);
}

void	sort_and_check(char *name, int in[], size_t len, void (f)(t_dlist**, t_dlist**, int*))
{
	t_dlist	*a = _dlst_from_arr(in, len);
	t_dlist	*b = NULL;
	int		ops = 0;

	f(&a, &b, &ops);
	is_dlist_sorted(a, name, ops);
	ft_dlstfree(a);
	ft_dlstfree(b);
}

int	main(void)
{
    printf(BOLD "\nINSERTION SORT\n" RESET);
	sort_and_check("10 elements (rand):", (int[]){7, 10, 5, 9, 1, 0, 4, 8, 3, 2}, 10, &insertion_sort);
	sort_and_check("5 elements (worst):", (int[]){5,4,3,2,1}, 5, &insertion_sort);
	sort_and_check("5 elements (best):", (int[]){1,2,3,4,5}, 5, &insertion_sort);
	sort_and_check("2 elements (worst):", (int[]){2, 1}, 2, &insertion_sort);
	sort_and_check("2 elements (best):", (int[]){1, 2}, 2, &insertion_sort);
	sort_and_check("1 element:", (int[]){1}, 1, &insertion_sort);
    printf(BOLD "\nDIR INSERTION SORT\n" RESET);
	sort_and_check("10 elements (rand):", (int[]){7, 10, 5, 9, 1, 0, 4, 8, 3, 2}, 10, &dir_insertion_sort);
	sort_and_check("5 elements (worst):", (int[]){5,4,3,2,1}, 5, &dir_insertion_sort);
	sort_and_check("5 elements (best):", (int[]){1,2,3,4,5}, 5, &dir_insertion_sort);
	sort_and_check("2 elements (worst):", (int[]){2, 1}, 2, &dir_insertion_sort);
	sort_and_check("2 elements (best):", (int[]){1, 2}, 2, &dir_insertion_sort);
}
