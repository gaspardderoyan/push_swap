#include "../inc/project.h"

// ANSI escape codes for colors
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define RESET   "\x1b[0m"
#define BOLD	"\033[1m"

// Modified function to create a doubly linked list from an array
static t_dlist *dlst_from_arr(int *arr, size_t size)
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
	t_dlist *copy = lst;

	current = *(int *)lst->content;
	while (lst)
	{
		current = *(int *)lst->content;
		lst = lst->next;
		if (lst && *(int *)lst->content < current)
		{
			printf("%sFAIL: %s List isn't sorted ; %s Ops = %d\n", RED, name, RESET, ops);
			pnf_list(copy, 0);
			return ;
		}
	}
	printf("%sPASS: %s%s Ops = %d\n", GREEN, name, RESET, ops);
}

void	sort_and_check(char *name, int in[], size_t len, void (f)(t_mst*))
{
	t_mst mst;
	mst.a = dlst_from_arr(in, len);
	mst.b = NULL;
	mst.l_ops = NULL;
	int p_size = ft_dlstsize(mst.a);

	list_indexing(&mst);
	f(&mst);
	int n_size = ft_dlstsize(mst.a);
	int ops = ft_dlstsize(mst.l_ops);
	is_dlist_sorted(mst.a, name, ops);
	if (p_size != n_size)
		printf("FAIL: Incomplete list! Should have %d, has %d\n", p_size, n_size);
	// print_instructions(mst.l_ops);
	ft_dlstfree(mst.a);
	ft_dlstfree(mst.b);
	ft_dlstfree(mst.l_ops);
}

int	main(void)
{
    printf(BOLD "\nSORT THREE\n" RESET);
	sort_and_check("2, 1, 3", (int[]){2, 1, 3}, 3, &sort_three);
	sort_and_check("3, 2 ,1", (int[]){3, 2 ,1}, 3, &sort_three);
	sort_and_check("3, 1 ,2", (int[]){3, 1 ,2}, 3, &sort_three);
	sort_and_check("1 ,3, 2", (int[]){1 ,3, 2}, 3, &sort_three);
	sort_and_check("2 ,3, 1", (int[]){2 ,3, 1}, 3, &sort_three);
	sort_and_check("1 ,2, 3", (int[]){1 ,2, 3}, 3, &sort_three);
	printf(BOLD "\nSORT FOUR\n" RESET);
	sort_and_check("1, 3, 2, 4 - lower than min", (int[]){1, 3, 2, 4}, 4, &sort_five);
	sort_and_check("4, 1, 2, 3 - higher than max", (int[]){4, 1, 2, 3}, 4, &sort_five);
	sort_and_check("2, 1, 3, 4 - middle, above mid", (int[]){2, 1, 3, 4}, 4, &sort_five);
	sort_and_check("3, 1, 2, 4 - middle, under mid", (int[]){3, 1, 2, 4}, 4, &sort_five);
	sort_and_check("2, 4, 5, 3", (int[]){2, 4, 5, 3}, 4, &sort_five);
	sort_and_check("4, 5, 3, 1", (int[]){4, 5, 3, 1}, 4, &sort_five);
	sort_and_check("1, 4, 3, 2", (int[]){1, 4, 3, 2}, 4, &sort_five);
	printf(BOLD "\nSORT FIVE\n" RESET);
	sort_and_check("5, 4, 3, 2, 1", (int[]){5, 4, 3, 2, 1}, 5, &sort_five);
	sort_and_check("1, 2, 3, 4, 5", (int[]){1, 2, 3, 4, 5}, 5, &sort_five);
	sort_and_check("2, 1, 3, 4, 5", (int[]){2, 1, 3, 4, 5}, 5, &sort_five);
	sort_and_check("2, 1, 4, 3, 5", (int[]){2, 1, 4, 3, 5}, 5, &sort_five);
	sort_and_check("2, 1, 4, 5, 3", (int[]){2, 1, 4, 5, 3}, 5, &sort_five);
	sort_and_check("2, 1, 5, 3, 4", (int[]){2, 1, 5, 3, 4}, 5, &sort_five);
	sort_and_check("2, 1, 5, 4, 3", (int[]){2, 1, 5, 4, 3}, 5, &sort_five);
	sort_and_check("2, 3, 1, 4, 5", (int[]){2, 3, 1, 4, 5}, 5, &sort_five);
	sort_and_check("2, 3, 1, 5, 4", (int[]){2, 3, 1, 5, 4}, 5, &sort_five);
	sort_and_check("2, 3, 4, 1, 5", (int[]){2, 3, 4, 1, 5}, 5, &sort_five);
	sort_and_check("2, 3, 4, 5, 1", (int[]){2, 3, 4, 5, 1}, 5, &sort_five);
	sort_and_check("2, 3, 5, 1, 4", (int[]){2, 3, 5, 1, 4}, 5, &sort_five);
	sort_and_check("1, 3, 5, 4, 2", (int[]){1, 3, 5, 4, 2}, 5, &sort_five);
	sort_and_check("4, 2, 5, 3, 1", (int[]){4, 2, 5, 3, 1}, 5, &sort_five);
	sort_and_check("2, 4, 5, 3, 1", (int[]){2, 4, 5, 3, 1}, 5, &sort_five);
	sort_and_check("1, 5, 2, 4, 3", (int[]){1, 5, 2, 4, 3}, 5, &sort_five);
}
