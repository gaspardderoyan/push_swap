/* double_lst.h */
#ifndef DOUBLE_LST_H
# define DOUBLE_LST_H

#include <stdlib.h>

typedef struct s_dlist
{
    void    *content;
    struct s_dlist  *prev;
    struct s_dlist  *next;
} t_dlist;

t_dlist *ft_dlstnew(void *content);
void    ft_dlstadd_front(t_dlist **lst, t_dlist *new);
t_dlist	*ft_dlstlast(t_dlist *lst);
void	ft_dlstadd_back(t_dlist **lst, t_dlist *new);

#endif
