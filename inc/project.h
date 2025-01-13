#ifndef PROJECT_H
# define PROJECT_H

# include "../libft/inc/libft.h"
# include "../inc/double_lst.h"

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

typedef struct s_strtol_mt
{
	int			sign;
	int			index;
	int			empty;
	long long	n;
} t_strtol_mt;

// Function Prototypes

// Addition Functions
void    add_nbr_to_lst(t_dlist **lst, int n);
void    lst_from_str(char *str, t_dlist **lst);
void    lst_from_strs(int argc, char **argv, t_dlist **lst);
void    check_for_duplicate(t_dlist *lst, int n);

// Manipulation Functions
void    swap_first(t_dlist **lst);
void    f_both(t_dlist **a, t_dlist **b, void (f)(t_dlist**));
void    push_first(t_dlist **in, t_dlist **out);
void    rotate(t_dlist **lst);
void    reverse(t_dlist **lst);

// Utility Functions
int     str_isall(char *s, int (*f)(int));
void    pnf_list(t_dlist *lst, int free_flag);
t_dlist *get_ntl(t_dlist *lst);
t_dlist *get_lst_min(t_dlist *lst, int index_mode);
void    list_indexing(t_dlist **lst, int lst_len);

// Algorithms
int		insertion_sort(t_dlist **a, t_dlist **b);
int		chunk_sort(t_dlist **a, t_dlist **b, t_stacks_mt *mt);
int		dir_of_first(t_dlist *lst, t_stacks_mt *mt);
void	update_mt(t_stacks_mt *mt);

// Other
char	**ft_split_cs(char const *s, char *cs);
long long	mini_strtoll(const char *nptr, int radix);


#endif

