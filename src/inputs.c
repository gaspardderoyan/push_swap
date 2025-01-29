/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderoyqn <gderoyqn@student.42london.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 00:18:47 by gderoyqn          #+#    #+#             */
/*   Updated: 2025/01/22 10:38:33 by gderoyqn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/project.h"

/**
* Takes a dlist and a int, mallocs an int ptr, then add it to back of dlist
*/
void    add_nbr_to_lst(t_dlist **lst, int n)
{
	int *new;
	new = (int *)malloc(sizeof(int));
	if (!new)
		return ;
	*new = n;
	ft_dlstadd_back(lst, ft_dlstnew(new));
}

/**
* Takes a dlist and a int, and check if the int is already in the dlist
*
* If it is, sets errno = 2
*/
void	check_for_duplicate(t_dlist *lst, int n)
{
	while (lst)
	{
		if (lst->content)
		{
			if (*(int *)lst->content == n)
			{
				errno = 2;
				return ;
			}
		}
		lst = lst->next;
	}
}


/**
 * Takes in the string arr (ie. the split single arg),
 * as well as the mst (master) structure.
 *
 * For each string, use strtoll, then check for error/duplicates
 *
 * Else, adds the number to the list
*/
void    lst_from_str(char **str, t_mst *mst)
{
	long long	cur_num;
	char		**cpy;
	cpy = str;
	if (errno)
		return ;
	while (*cpy)
	{
		cur_num = mini_strtoll(*cpy, 10);
		check_for_duplicate(mst->a, cur_num);
		if (cur_num < INT_MIN || cur_num > INT_MAX)
			errno = ERANGE;
		if (errno)
			return ;
		add_nbr_to_lst(&mst->a, cur_num);
		(cpy)++;
	}
}

/**
 * Takes in ac & av,  as well as the mst (master) structure.
 *
 * For each arg, use strtoll, then check for error/duplicates
 *
 * Else, adds the number to the list
*/
void	lst_from_strs(int argc, char **argv, t_mst *mst)
{
	int			i;
	long long	cur_num;
	i = 1;
	while (i < argc)
	{
		cur_num = mini_strtoll(argv[i], 10);
		check_for_duplicate(mst->a, cur_num);
		if (cur_num < INT_MIN || cur_num > INT_MAX)
			errno = ERANGE;
		if (errno)
			return ;
		add_nbr_to_lst(&mst->a, cur_num);
		i++;
	}
}

/**
 * Takes in ac & av,  as well as the mst (master) structure.
 *
 * Creates a doubly linked list from the user input.
 *
 * If ac == 2, uses split_cs then lst_from_str.
 *
 * Else, use lst_from_strs.
*/
void lst_from_input(int ac, char **av, t_mst *mst)
{
	char **strs;
	if (ac == 2)
	{
		strs = ft_split_cs(av[1], "\t\n\v\f\r ");
		lst_from_str(strs, mst);
		ft_free_strs(strs);
	}
	else if (ac > 2)
		lst_from_strs(ac, av, mst);
}
