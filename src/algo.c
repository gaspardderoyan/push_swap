/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderoyqn <gderoyqn@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 21:02:39 by gderoyqn          #+#    #+#             */
/*   Updated: 2025/01/20 16:53:04 by gderoyqn         ###   ########.fr       */
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
            rotate(a, &operations); 
        push_first(a, b, &operations);
    }
    while (ft_dlstsize(*b) != 0)
        push_first(b, a, &operations);
    return (operations);
}


