/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderoyqn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:14:24 by gderoyqn          #+#    #+#             */
/*   Updated: 2024/12/06 13:53:49 by gderoyqn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL)
		return ;
	(*del)(lst->content);
	free(lst);
}

/*
void	ft_free_node(void *content)
{
	free(content);
}

int	main(void)
{
	t_list *head;

	head = ft_lstnew(ft_strdup("first"));
	ft_lstadd_back(&head, ft_lstnew(ft_strdup("second")));
	ft_lstadd_back(&head, ft_lstnew(ft_strdup("third")));
	printf("last (before): %s\n", (char *)ft_lstlast(head)->content);
	ft_lstdelone(ft_lstlast(head), &ft_free_node);
	if (ft_lstlast(head)->content == NULL)
		printf("Content was NULL!\n");
	else
		printf("last (after): %s\n", (char *)ft_lstlast(head)->content);
}
*/
