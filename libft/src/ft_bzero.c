/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderoyqn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:58:31 by gderoyqn          #+#    #+#             */
/*   Updated: 2024/12/04 12:58:40 by gderoyqn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
		((unsigned char *)s)[i++] = 0;
}

/*
#include <stdio.h>
int	main(void)
{
	char str[] = "This is a test!";

	ft_bzero(str + 9, 2);
	printf("%s\n", str);
	printf("%s\n", str + 10);
	printf("%s\n", str + 11);
	return (0);
}
*/
