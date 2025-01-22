#ifndef PROJECT_H
# define PROJECT_H

# include "../libft/inc/libft.h"

/**
 * Represents a chunk within a larger list for multi-chunks sorting.
 *
 * @var s_stack_mt::chunks_i The index of the current chunk being processed.
 * @var s_stack_mt::lower_limit The starting index of the current chunk within the list.
 * @var s_stack_mt::upper_limit The ending index of the current chunk within the list.
 * @var s_stack_mt::chunks_count The total number of chunks the list is divided into.
 * @var s_stack_mt::lst_size The total size of the list being sorted.
 */
typedef struct s_stack_mt
{
	int	chunks_i;
	int	lower_limit;
	int	upper_limit;
	int	chunks_count;
	int	lst_size;
} t_stacks_mt;

typedef struct s_mst
{
	t_dlist *a;	
	t_dlist *b;
	t_stacks_mt mt;
	int	ops;
} t_mst ;


// Function Prototypes

// Addition Functions
void    add_nbr_to_lst(t_dlist **lst, int n);
void    lst_from_str(char **str, t_mst *mst);
// void    lst_from_str(char *str, t_dlist **lst);
void	lst_from_strs(int argc, char **argv, t_mst *mst);
// void    lst_from_strs(int argc, char **argv, t_dlist **lst);
void    check_for_duplicate(t_dlist *lst, int n);
void lst_from_input(int ac, char **av, t_mst *mst);

// Manipulation Functions
void    swap_first(t_dlist **lst, int *ops);
void    f_both(t_dlist **a, t_dlist **b, void (f)(t_dlist**), int *ops);
void    push_first(t_dlist **in, t_dlist **out, int *ops);
void    rotate(t_dlist **lst, int *ops);
void    reverse(t_dlist **lst, int *ops);

// Utility Functions
int     str_isall(char *s, int (*f)(int));
t_dlist *get_lst_min(t_dlist *lst, int index_mode);
t_dlist	*get_lst_max(t_dlist *lst);
void    list_indexing(t_mst *mst, int chunks_count);

// Algorithms
void	iterative_min_sort(t_dlist **a, t_dlist **b, int *ops);
void	dir_iterative_min_sort(t_dlist **a, t_dlist **b, int *ops);
void	chunk_sort(t_dlist **a, t_dlist **b, t_stacks_mt *mt, int *ops);
int		dir_of_first(t_dlist *lst, t_stacks_mt *mt);
void	update_stacks_mt(t_stacks_mt *mt);
int		get_min_dir(t_dlist *lst);

// to delete
void	pnf_list(t_dlist *lst, int free_flag);

#endif

