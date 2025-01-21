/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderoyqn <gderoyqn@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:17:59 by gderoyqn          #+#    #+#             */
/*   Updated: 2025/01/20 19:22:19 by gderoyqn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/project.h"

int	str_isall(char *s, int (*f)(int))
{
	while (*s)
	{
		if (f(*s) == 0)
			return (0);
		s++;
	}
	return (1);
}

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
    return min;
}


t_dlist *get_lst_max(t_dlist *lst)
{
    t_dlist *max;
    int current_val;

    max = NULL;
    while (lst)
    {
		if (max == NULL || (*(int *)lst->content > current_val))
		{
			max = lst;
			current_val = *(int *)lst->content;
		}
        lst = lst->next;
    }
    return max;
}

