#include "../inc/double_lst.h"
#include "../inc/project.h"

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
