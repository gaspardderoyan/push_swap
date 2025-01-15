/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderoyqn <gderoyqn@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 23:27:21 by gderoyqn          #+#    #+#             */
/*   Updated: 2025/01/13 19:29:46 by gderoyqn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/project.h"
#include "../libft/inc/libft.h"


/*
 * Returns the position of the given character in the given base
 *
 * @param	c		the current character
 * @param	radix	the radix of the base (ie. 10 for deci)
 */
int	base_index(char c, int radix)
{
	const char	*base = "0123456789abcdefghijklmnopqrstuvwxyz";
	int			index;

	index = 0;
	c = ft_tolower(c);
	while (base[index] && index < radix)
	{
		if (base[index] == c)
			return (index);
		index++;
	}
	return (-1);
}

int	handle_overflow(int sign, long long *n, int digit, int radix)
{
	if (sign == 1 && *n > (LLONG_MAX - digit) / radix)
	{
		errno = ERANGE;
		*n = LLONG_MAX;
		return (true);
	}
	if (sign == -1 && -(*n) < (LLONG_MIN + digit) / radix)
	{
		errno = ERANGE;
		*n = LLONG_MIN;
		return (true);
	}
	return (false);
}

/*
 * @brief	Proccess an str for mini_strtoll
 *
 * Skips leading spaces, sets the sign, skips single '+' 
 *
 * Advances the pointer and sets the radix to deal with octal/hexa/deci
 *
 * @param	nptr	pointer to a str, supposed to contain the nbr
 * @param	sign	pointer to an int, to set the sign of nbr
 * @param	radix	pointer to an int, ie. 10 for decimal 
 */
void	skip_lead(const char **nptr, int *sign, int *radix)
{
	while (ft_isspace(**nptr))
		(*nptr)++;
	*sign = 1;
	if (**nptr == '-')
	{
		*sign = -1;
		(*nptr)++;
	}
	else if (**nptr == '+')
		(*nptr)++;
	if ((*radix == 0 || *radix == 16) && **nptr == '0'
		&& (ft_tolower(*(*nptr + 1)) == 'x'))
	{
		*nptr += 2;
		*radix = 16;
	}
	else if (*radix == 0 && **nptr == '0')
	{
		(*nptr)++;
		*radix = 8;
	}
	else if (*radix == 0)
		*radix = 10;
}


void	set_strtol_mt(t_strtol_mt *mt, int sign, int empty, long long n)
{
	mt->sign = sign;
	mt->empty = empty;
	mt->index = 0;
	mt->n = n;
}
/*
 * 
 * If radix is out of range, sets errno & returns 0
 */
long long	mini_strtoll(const char *nptr, int radix)
{
	t_strtol_mt mt;

	set_strtol_mt(&mt, 1, 1, 0);
	skip_lead(&nptr, &mt.sign, &radix);
	if (radix < 2 || radix > 36)
		return (errno = EINVAL, 0);
	while (*nptr && (base_index(*nptr, radix) > -1))
	{
		mt.empty = 0;
		mt.index = base_index(*nptr, radix);
		if (handle_overflow(mt.sign, &mt.n, mt.index, radix))
			return (mt.n);
		// TODO put this in handle overflow 
		if (mt.n <= LLONG_MAX / radix)
			mt.n = mt.n * radix + mt.index;
		nptr++;
	}

	// if (nptr)
	// 	errno = 10;
	if (mt.empty)
		return (errno = EINVAL, 0);
	return (mt.n * mt.sign);
}

