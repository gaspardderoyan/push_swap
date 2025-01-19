/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderoyqn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:35:03 by gderoyqn          #+#    #+#             */
/*   Updated: 2024/12/04 12:35:05 by gderoyqn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

/*
#include <stdio.h>
int	main(void)
{
	const char str[] = "Test";
	size_t i = 0;
	i = ft_strlen(str);
	printf("This should be 4 --> %zu\n", i);
	return (0);
}
*/
