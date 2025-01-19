/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderoyqn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:02:01 by gderoyqn          #+#    #+#             */
/*   Updated: 2024/12/03 13:02:36 by gderoyqn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static unsigned int	ft_abs(int n)
{
	unsigned int	num;

	if (n == INT_MIN)
		num = (unsigned int)INT_MAX + 1;
	else if (n < 0)
		num = -n;
	else
		num = n;
	return (num);
}

static int	ft_nbr_len(int n)
{
	int				len;
	unsigned int	num;

	len = 0;
	if (n <= 0)
		len = 1;
	num = ft_abs(n);
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int					len;
	char				*res;
	unsigned int		num;

	len = ft_nbr_len(n);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	num = ft_abs(n);
	if (n == 0)
	{
		res[0] = '0';
		return (res);
	}
	while (num != 0)
	{
		res[--len] = (num % 10) + '0';
		num /= 10;
	}
	if (n < 0)
		res[--len] = '-';
	return (res);
}

/*
int	main(void)
{
	char	*res;
	res = ft_itoa(0);
	printf("res: %s\n", res);
    return 0;
}
*/
