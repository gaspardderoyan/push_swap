/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderoyqn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:00:27 by gderoyqn          #+#    #+#             */
/*   Updated: 2024/12/04 13:00:32 by gderoyqn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*ptr;
	size_t	i;

	if (!dest && !src)
		return (NULL);
	i = 0;
	ptr = dest;
	while (i < n)
	{
		*(char *)dest = *(char *)src;
		dest++;
		src++;
		i++;
	}
	return (ptr);
}

/*
#include <stdio.h>
int	main(void)
{
	char str1[] = "Hello";
	char str2[] = "Kit";
	printf("Hello --> %s\n", str1);
	ft_memcpy(str1, str2, sizeof(str2));
	printf("Kitty --> %s\n", str1);
	printf("Kitty --> %s\n", str1 + 4);
	return (0);
}
*/
