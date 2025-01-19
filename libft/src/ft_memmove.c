/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderoyqn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:13:05 by gderoyqn          #+#    #+#             */
/*   Updated: 2024/12/04 16:53:23 by gderoyqn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;

	if (!dest && !src)
		return (NULL);
	d = (char *)dest;
	s = (const char *)src;
	if (s < d && s + n - 1 >= d)
	{
		while (n > 0)
		{
			*(char *)(dest + n - 1) = *(const char *)(src + n - 1);
			n--;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}

/*
#include <stdio.h>
int main(void)
{
	char str1[] = "ABCDEFGH";
	char str2[] = "ABCDEFGH";
	printf("Destination starts after source, overlap\n");
	printf("%s\n", str1);
	ft_memmove(str1 + 4, str1 + 2, 3);
	printf("%s\n", str1);
	printf("Destination starts before source, safe overlap\n");
	printf("%s\n", str2);
	ft_memmove(str2, str2 + 4, 4);
	printf("%s\n", str2);
	return (0);
}
*/
