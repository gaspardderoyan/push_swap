/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderoyqn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 01:07:56 by gderoyqn          #+#    #+#             */
/*   Updated: 2024/12/14 01:08:20 by gderoyqn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

size_t	strlen_safe(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

static int	ft_nbrlen_base(unsigned long long n, int base)
{
	int				len;

	len = 0;
	if (n <= 0)
	{
		len = 1;
		n = -n;
	}
	while (n != 0)
	{
		n /= base;
		len++;
	}
	return (len);
}

char	*ft_itoa_base(unsigned long long n, char *base)
{
	int		base_len;
	int		len;
	char	*res;

	base_len = strlen_safe(base);
	len = ft_nbrlen_base(n, base_len);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	if (n == 0)
	{
		res[0] = '0';
		return (res);
	}
	while (n != 0)
	{
		res[--len] = *((n % base_len) + base);
		n /= base_len;
	}
	return (res);
}
