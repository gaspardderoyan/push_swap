/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderoyqn <gderoyqn@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 21:02:39 by gderoyqn          #+#    #+#             */
/*   Updated: 2025/01/19 21:06:30 by gderoyqn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/project.h"

int insertion_sort(t_dlist **a, t_dlist **b)
{
    int min;
    int operations;

    operations = 0;
    while (ft_dlstsize(*a) != 0)
    {
        min = *(int *)(get_lst_min(*a, false)->content);
        while (*(int *)(*a)->content != min)
        {
            rotate(a); 
            operations++;
        }
        push_first(a, b);
        operations++;
    }
    while (ft_dlstsize(*b) != 0)
    {
        push_first(b, a);
        operations++;
    }
    return (operations);
}


int	chunk_sort(t_dlist **a, t_dlist **b, t_stacks_mt *mt)
{
	int	operations;
	int	min;

	operations = 0;
	update_stacks_mt(mt);
	// Push everything to stack b, sorted into chunks
	while (mt->chunks_i < mt->chunks_count)
	{
		update_stacks_mt(mt);
		// Loop for each digit in the stack
		while (*a && dir_of_first(*a, mt))
		{
			ft_printf("first loop\n");
			if (dir_of_first(*a, mt)	== 1)
			{
				while (*a && (*a)->index > (mt->lst_size / mt->chunks_count))
				{
					rotate(a);
					ft_printf("inner loop 1\n");
					operations++;
				}
			}
			else 
			{
				while (*a && (*a)->index > (mt->chunks_i + 1) * (mt->lst_size / mt->chunks_count))
				{
					ft_printf("inner loop 2\n");
					reverse(a);
					operations++;
				}
			}
			if (*a)
			{
				push_first(a, b);
				operations++;
			}
		}
		mt->chunks_i++;
	}
	while (*b)
	{
		min = *(int *)(get_lst_min(*b, false)->content);
		ft_printf("min is = %d\n", min);
		// get min i within b
		// ie. is it faster to rb or rrb
		while (*(int *)(*b)->content != min)
		{
			rotate(b);
			operations++;
		}
		push_first(b, a);
		operations++;
	}
	return (operations);
}
