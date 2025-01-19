/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderoyqn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 16:57:58 by gderoyqn          #+#    #+#             */
/*   Updated: 2025/01/18 21:05:24 by gderoyqn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	max_len;
	char	*sub;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len)
		return (ft_strdup(""));
	max_len = s_len - start;
	if (len < max_len)
		max_len = len;
	sub = (char *)malloc(sizeof(char) * (max_len + 1));
	if (!sub)
		return (ft_strdup(""));
	ft_strlcpy(sub, &s[start], max_len + 1);
	return (sub);
}

/*
int	main(void)
{
	char *s;

	s = ft_substr("tripouille", 100, 1);
	printf("Dest --> %s\n", s);
	return (0);
}
*/
