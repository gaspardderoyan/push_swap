/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderoyqn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 01:08:54 by gderoyqn          #+#    #+#             */
/*   Updated: 2024/12/14 01:08:55 by gderoyqn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	p_char(va_list *ptr, int *ccount)
{
	char	c;

	c = (char)va_arg(*ptr, int);
	write(1, &c, 1);
	(*ccount)++;
}

void	p_str(va_list *ptr, int *ccount)
{
	char	*str;
	int		len;

	str = va_arg(*ptr, char *);
	len = strlen_safe(str);
	*ccount += len;
	if (str)
		write(1, str, len);
	else
	{
		write(1, "(null)", 6);
		*ccount += 6;
	}
}

void	p_percent(int *ccount)
{
	write(1, "%", 1);
	(*ccount)++;
}

void	p_else(const char *str, int *ccount)
{
	write(1, str, 1);
	write(1, str + 1, 1);
	*ccount += 2;
}
