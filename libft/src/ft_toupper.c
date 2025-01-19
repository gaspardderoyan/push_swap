/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderoyqn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:03:35 by gderoyqn          #+#    #+#             */
/*   Updated: 2024/12/04 13:03:40 by gderoyqn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - ' ');
	return (c);
}

/*
#include <stdio.h>
int	main(void)
{
	char	c;
	c = 'a';
	printf("char: %c", ft_toupper(c));
	return (0);
}
*/
