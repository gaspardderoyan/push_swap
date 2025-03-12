/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strdup_safe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderoyqn <gderoyqn@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:07:06 by gderoyqn          #+#    #+#             */
/*   Updated: 2025/03/12 17:07:08 by gderoyqn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*strdup_safe(const char *s)
{
	size_t	len;
	char	*new;
	int		i;

	if (!s)
		return (NULL);
	len = strlen_safe(s);
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
