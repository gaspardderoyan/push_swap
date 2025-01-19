#include "../libft/inc/libft.h"
#include "../inc/double_lst.h"
#include "../inc/project.h"


int	main(int argc, char **argv)
{
	t_dlist *a;
	t_stacks_mt mt;

	a = NULL;
	errno = 0;
	if (argc == 1)
		return (ft_putstr_fd("Error\n", 2), 0);
	else if (argc == 2)
		lst_from_str(argv[1], &a);
	else
		lst_from_strs(argc, argv, &a);
	if (errno)
	{
		ft_printf("errno: %i\n", errno);
		pnf_list(a, 2);
		return (ft_putstr_fd("Error\n", 2), 0);
	}
	mt.lst_size = ft_dlstsize(a);
	mt.chunks_i = 0;
	mt.chunks_count = 5;

	ft_printf("\n\nlst_size: %i\n\n", mt.lst_size);
    list_indexing(&a, mt.lst_size);
	ft_printf("Before sorting: \n");
    pnf_list(a, 0);

	// int dir = direction_of_first(a, 2, 1);
	// ft_printf("Dir: %i\n", dir);

	t_dlist *b = NULL;
	int operations = chunk_sort(&a, &b, &mt);
	ft_printf("After sorting: \n");
	pnf_list(a, 0);
	ft_printf("Operations: %i\n", operations);

	// int dir = direction_of_first(a, 2, 0);
	// ft_printf("Dir: %i\n", dir);
	// t_dlist *b = NULL;
	// int		operations = 0;
	// operations = chunk_sort(&a, &b, 5);
	// ft_printf("Operations: %i\n", operations);
    return (0);
}
