/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderoyqn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:35:37 by gderoyqn          #+#    #+#             */
/*   Updated: 2024/12/04 12:36:29 by gderoyqn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*cursor;

	if (lst == NULL)
		return (NULL);
	cursor = lst;
	while (cursor->next != NULL)
		cursor = cursor->next;
	return (cursor);
}

/*
int	main(void)
{
	t_list *head;
	t_list *cursor;
	int len;

	
	head = ft_lstnew("first");
	ft_lstadd_front(&head, ft_lstnew("second"));
	ft_lstadd_front(&head, ft_lstnew("third"));
	len = ft_lstsize(head);
	printf("len: %d\n", len);
	cursor = head;
	while (cursor != NULL)
	{
		printf("content: %s\n", (char *)cursor->content);
		cursor = cursor->next;
	}
	printf("last content: %s\n", (char *)ft_lstlast(head)->content);
	return (0);
}
*/
