/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderoyqn <gderoyqn@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:17:59 by gderoyqn          #+#    #+#             */
/*   Updated: 2025/01/29 20:10:08 by gderoyqn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/project.h"

/**
* Takes dlist as input, finds the min of the content nodes, returns the node
*
* If index_mode is set to true, it finds the minimum ONLY OUT OF the
* values which index's are not already set (ie. is currently -1)
*
* ie. if the index_mode is false OR the current index is -1, it processes the
* current node.
*
* However, if the index is already set (not -1) AND index_mode is true,
* it skips the value, ie. it will find the next min value to index.
*/
t_dlist *get_lst_min(t_dlist *lst, int index_mode)
{
    t_dlist *min;
    int current_val;

    min = NULL;
    while (lst)
    {
        if (lst->index == -1 || index_mode == false)
        {
            if (min == NULL || (*(int *)lst->content < current_val))
            {
                min = lst;
                current_val = *(int *)lst->content;
            }
        }
        lst = lst->next;
    }
    return (min);
}

void	print_instructions(t_dlist *l_ops)
{
	while (l_ops)
	{
		ft_printf("%s\n", (char *)l_ops->content);
		l_ops = l_ops->next;
	}
}

void	choose_algo(t_mst *mst)
{
	if (!ft_strncmp(ALGO, "chunk", 50))
		chunk_sort(mst);
	else if (!ft_strncmp(ALGO, "iterative_min", 50))
		iterative_min_sort(mst);
	else if (!ft_strncmp(ALGO, "dir_iterative_min", 50))
		dir_iterative_min_sort(mst);
}
