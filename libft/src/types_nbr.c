/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderoyqn <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 01:09:28 by gderoyqn          #+#    #+#             */
/*   Updated: 2024/12/14 01:09:29 by gderoyqn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	p_ptr(va_list *ptr, int *ccount)
{
	uintptr_t	adr;	
	char		*str;
	int			len;

	adr = (uintptr_t)va_arg(*ptr, uintptr_t);
	if (!adr)
	{
		write(1, "(nil)", 5);
		*ccount += 5;
	}
	else
	{
		str = ft_itoa_base(adr, "0123456789abcdef");
		len = strlen_safe(str);
		*ccount += len + 2;
		write(1, "0x", 2);
		write(1, str, len);
		free(str);
	}
}

void	p_ubase(va_list *ptr, int *ccount, char *base)
{
	unsigned int	n;	
	char			*str;
	int				len;

	n = (unsigned int)va_arg(*ptr, unsigned int);
	str = ft_itoa_base(n, base);
	len = strlen_safe(str);
	*ccount += len;
	write(1, str, len);
	free(str);
}

void	p_int(va_list *ptr, int *ccount)
{
	char		*str;
	int			len;
	long long	n;

	n = va_arg(*ptr, int);
	if (n >= 0)
		str = ft_itoa_base(n, "0123456789");
	else
	{
		write(1, "-", 1);
		(*ccount)++;
		str = ft_itoa_base(-n, "0123456789");
	}
	len = strlen_safe(str);
	write(1, str, len);
	free(str);
	*ccount += len;
}
