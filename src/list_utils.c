/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderoyqn <gderoyqn@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:17:59 by gderoyqn          #+#    #+#             */
/*   Updated: 2025/01/18 18:25:58 by gderoyqn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/double_lst.h"
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

t_dlist *get_ntl(t_dlist *lst)
{
	t_dlist *cursor;

	if (lst == NULL || lst->next == NULL)
		return (NULL);
	cursor = ft_dlstlast(lst)->prev;
	if (cursor)
		return (cursor);
	return (NULL);
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

void    list_indexing(t_mst *mst, int chunks_count)
{
    int i;
    t_dlist *min_node;
    t_dlist *temp;

	mst->mt = malloc(sizeof(t_stacks_mt));
	mst->mt->chunks_i = 0;
	mst->mt->chunks_count = chunks_count;
	mst->mt->lst_size = ft_dlstsize(mst->a);
    temp = mst->a;
    while (temp)
    {
        temp->index = -1;
        temp = temp->next;
    }
    i = 0;
    while (i < mst->mt->lst_size)
    {
        min_node = get_lst_min(mst->a, true);
        min_node->index = i;
        i++;
    }
}

