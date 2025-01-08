#ifndef PROJECT_H
# define PROJECT_H

# include "../libft/inc/libft.h"
# include "double_lst.h"

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
int	insertion_sort(t_dlist **a, t_dlist **b);
int	chunk_sort(t_dlist **a, t_dlist **b, int chunks_count);
int direction_of_first(t_dlist *a, int chunks_count, int chunks_i);

#endif

