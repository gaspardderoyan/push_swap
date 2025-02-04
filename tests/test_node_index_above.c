#include "../inc/project.h"
#include "libft.h"

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

int	main(void)
{
	t_mst mst;
	mst.a = dlst_from_arr((int[]){4, 1, 2, 3, 5}, 5);
	mst.b = NULL;
	mst.l_ops = NULL;
	list_indexing(&mst);
	push_first(&mst.a, &mst.b, &mst.l_ops, "pb");
	t_dlist *above = smallest_index_above(mst.a, 3);
	printf("Index: %d\n", above->index);
	printf("Num: %d\n", *(int *)above->content);
	ft_dlstfree(mst.a);
	ft_dlstfree(mst.b);
	ft_dlstfree(mst.l_ops);
}
