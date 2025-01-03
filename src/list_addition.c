#include "../libft/inc/libft.h"
#include "../inc/double_lst.h"
#include "../inc/project.h"

void    add_nbr_to_lst(t_dlist **lst, int n)
{
	int *new;
	new = (int *)malloc(sizeof(int));
	if (!new)
		return ;
	*new = n;
	ft_dlstadd_back(lst, ft_dlstnew(new));
}

void	check_for_duplicate(t_dlist *lst, int n)
{
	while (lst)
	{
		if (*(int *)lst->content == n)
			errno = 2;
		lst = lst->next;
	}
}

void    lst_from_str(char *str, t_dlist **lst)
{
	int     cur_num;
	char    *cur_str;
	char    *start;

	while (*str)
	{
		if (*str == ' ')
			str++;
		if (ft_isdigit(*str) == 0) 
		{
			errno = 1;
			return ;
		}
		if (*str == '\0')
			break ;
		start = str;
		while (*str && ft_isdigit(*str))
			str++;
		cur_str = ft_substr(start, 0, str - start);
		errno = 0;
		cur_num = mini_strtoll(cur_str, 10); 
		check_for_duplicate(*lst, cur_num);
		free(cur_str);
		if (errno)
			return ;
		add_nbr_to_lst(lst, cur_num);
	}
}

void	lst_from_strs(int argc, char **argv, t_dlist **lst)
{
	int			i;
	long long	cur_num;

	i = 1;
	while (i < argc)
	{
		errno = 0; 
		if (!str_isall(argv[i], &ft_isdigit))
		{
			errno = 1;
			return ;
		}
		cur_num = mini_strtoll(argv[i], 10);
		check_for_duplicate(*lst, cur_num);
		if (errno)
			return ;
		add_nbr_to_lst(lst, cur_num);
		i++;
	}
}
