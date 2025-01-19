/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderoyqn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 15:25:47 by gderoyqn          #+#    #+#             */
/*   Updated: 2024/12/04 12:33:11 by gderoyqn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size == 0 || src == NULL || dest == NULL)
		return (ft_strlen(src));
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}

/*
#include <stdio.h>
int	main(void)
{
	char str1[] = "Hello";
	char str2[] = "Kitty";
	size_t s;
	printf("Before: %s\n", str1);
	s = ft_strlcpy(str1, str2, sizeof(str2) + 1);
	printf("After: %s\n", str1);
	printf("S= %zu\n", s);

}
*/
