/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_strs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderoyqn <gderoyqn@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 17:07:59 by gderoyqn          #+#    #+#             */
/*   Updated: 2025/03/12 17:08:18 by gderoyqn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

size_t	ft_count_strs(char **strs)
{
	size_t	i;

	i = 0;
	while (strs && strs[i])
		i++;
	return (i);
}
