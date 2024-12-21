#include "../libft/inc/libft.h"
#include "double_lst.h"

void    add_nbr_to_lst(t_dlist **lst, int n)
{
	int *new;
	new = (int *)malloc(sizeof(int));
	if (!new)
		return ;
	*new = n;
	ft_dlstadd_back(lst, ft_dlstnew(new));
}

int	str_isall(char *s, int (*f)(int))
{
	while (*s)
	{
		if (f(*s) == 0)
			return (0);
		s++;
	}
	return (1);
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

void pnf_list(t_dlist *lst, int free_flag)
{
	t_dlist *current;

	while (lst != NULL)
	{
		if (free_flag != 2)
		{
			if (lst->content != NULL)
				ft_printf("contents: %d\n", *(int *)lst->content);
			else
				ft_printf("content is NULL\n");
		}
		current = lst;
		lst = lst->next;
		if (free_flag)
		{
			free(current->content);
			free(current);
		}
	}
	ft_printf("\n");
}


void swap_first(t_dlist **lst)
{
	void *temp;

	if (!lst || !*lst || !(*lst)->next)
		return ;
	temp = (*lst)->next->content;
	(*lst)->next->content = (*lst)->content;
	(*lst)->content = temp;
}

void    f_both(t_dlist **a, t_dlist **b, void (f)(t_dlist**))
{
	f(a);
	f(b);
}

void    push_first(t_dlist **in, t_dlist **out)
{
	t_dlist *temp;

	if (!in || !*in || !(*in)->content)
		return ;

	temp = *in;
	*in = (*in)->next;
	temp->next = NULL;
	ft_dlstadd_front(out, temp);
}

void   rotate(t_dlist **lst)
{
	t_dlist *temp;

	temp = *lst;
	*lst = (*lst)->next;
	temp->next = NULL;
	ft_dlstadd_back(lst, temp);
}

t_dlist *get_ntl(t_dlist *lst)
{
	t_dlist *cursor;

	if (lst == NULL || lst->next == NULL)
		return (NULL);
	cursor = ft_dlstlast(lst)->prev;
	if (cursor)
		return (cursor);
	return (NULL);
}

void    reverse(t_dlist **lst)
{
	t_dlist *next_to_last;
	t_dlist *last;

	last = ft_dlstlast(*lst);
	next_to_last = get_ntl(*lst);
	next_to_last->next = NULL;
	last->next = *lst;
	*lst = last;
}

int main(int argc, char **argv)
{
	t_dlist *a;
	t_dlist *b;

	a = NULL;
	b = NULL;
	errno = 0;
	ft_printf("argc: %i\n", argc);
	if (argc == 1)
		return (ft_putstr_fd("Error\n", 2), 0);
	else if (argc == 2)
		lst_from_str(argv[1], &a);
	else
		lst_from_strs(argc, argv, &a);
	if (errno)
	{
		ft_printf("errno: %i\n", errno);
		pnf_list(a, 2);
		return (ft_putstr_fd("Error\n", 2), 0);
		return (0);
	}
	ft_putstr_fd("list a:\n", 1);
	pnf_list(a, 1);
	return (0);
}
