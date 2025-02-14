/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderoyqn <gderoyqn@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 17:41:59 by gderoyqn          #+#    #+#             */
/*   Updated: 2025/02/04 20:04:34 by gderoyqn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJECT_H
# define PROJECT_H
# define DUPLICATE_VALUE 1000
# ifndef ALGO
#  define ALGO "chunk"
# endif

# include "../libft/inc/libft.h"

typedef enum {
    MIN,
    MID,
    MAX
} Position;

typedef struct s_lst {
    int value;
    int index;
    struct s_lst *next;
    Position curr_pos;
    // current len of chunk being split?
} t_lst;

/**
 * Represents a chunk within a larger list for multi-chunks sorting.
 *
 * @var chunks_i The index of the current chunk being processed.
 * @var lower_limit The starting index of the current chunk within the list.
 * @var upper_limit The ending index of the current chunk within the list.
 * @var chunks_count The total number of chunks the list is divided into.
 * @var lst_size The total size of the list being sorted.
 */
typedef struct s_stack_mt
{
	int	chunks_i;
	int	lower_limit;
	int	upper_limit;
	int	chunks_count;
	int	lst_size;
}	t_stacks_mt;

/**
 * Master structure to hold the 2 stacks, the stacks metadata, and a 
 * list of the operations
 */
typedef struct s_mst
{
	t_dlist		*a;	
	t_dlist		*b;
	t_stacks_mt	mt;
	t_dlist		*l_ops;
}	t_mst;

/* Function Prototypes */

/* Addition Functions */
void	add_nbr_to_lst(t_dlist **lst, int n);
void	lst_from_str(char **str, t_mst *mst);
void	lst_from_strs(int argc, char **argv, t_mst *mst);
void	check_for_duplicate(t_dlist *lst, int n);
void	lst_from_input(int ac, char **av, t_mst *mst);

/* Manipulation Functions */
void	swap_first(t_dlist **lst, t_dlist **l_ops, char *op_name);
void	f_both(t_mst *mst, void (f)(t_dlist**), char *op_name);
void	push_first(t_dlist **in, t_dlist **out, t_dlist **l_ops, char *op_name);
void	rotate(t_dlist **lst, t_dlist **l_ops, char *op_name);
void	reverse(t_dlist **lst, t_dlist **l_ops, char *op_name);

/* Utility Functions */
t_dlist	*get_lst_min(t_dlist *lst, int index_mode);
t_dlist	*get_lst_max(t_dlist *lst);
void	list_indexing(t_mst *mst);
void	print_instructions(t_dlist *l_ops);
void	choose_algo(t_mst *mst);
t_dlist	*get_dlst_min_max_index(t_dlist *lst, bool max);

/* Algorithms */
void	iterative_min_sort(t_mst *mst);
void	dir_iterative_min_sort(t_mst *mst);
void	chunk_sort(t_mst *mst);
int		dir_of_first(t_dlist *lst, t_stacks_mt *mt);
void	update_stacks_mt(t_stacks_mt *mt);
int		get_min_dir(t_dlist *lst);

/* Small sorts */
void	sort_three(t_mst *mst);
void	sort_five(t_mst *mst);
t_dlist	*node_index_above(t_dlist *lst, int src_i);
t_dlist *smallest_index_above(t_dlist *lst, int src_i);

/* To delete */
void	pnf_list(t_dlist *lst, int free_flag);

#endif
