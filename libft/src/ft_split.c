/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderoyqn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 18:16:59 by gderoyqn          #+#    #+#             */
/*   Updated: 2024/12/03 15:10:40 by gderoyqn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int	ft_count_subs(char const *s, char c)
{
	int	count;
	int	in_sub;

	count = 0;
	in_sub = 0;
	while (*s)
	{
		if (*s == c)
			in_sub = 0;
		else
		{
			if (in_sub == 0)
			{
				count++;
				in_sub = 1;
			}
		}
		s++;
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	char	*start;

	if (!s)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * (ft_count_subs(s, c) + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s == '\0')
			break ;
		start = (char *)s;
		while (*s && *s != c)
			s++;
		arr[i++] = ft_substr(start, 0, s - start);
	}
	arr[i] = NULL;
	return (arr);
}

/*
int	main(void)
{
	char	**res;
	int		i;

	res = ft_split("tripouille", 0);
	i = 0;
	while (res[i])
	{
		printf("Part %d:%s\n", i + 1, res[i]);
		i++;
	}
	return (0);
}
*/
