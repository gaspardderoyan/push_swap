#include "../libft/inc/libft.h"
#include "double_lst.h"
#include <errno.h>

void    add_nbr_to_lst(t_dlist **lst, int n)
{
    int *new;
    new = (int *)malloc(sizeof(int));
    if (!new)
        return ;
    *new = n;
    ft_dlstadd_back(lst, ft_dlstnew(new));
}

void    lst_from_str(char *str, t_dlist **lst)
{
    int     cur_num;
    char    *cur_str;
    char    *start;
    char    *endptr;

    while (*str)
    {
        if (ft_isdigit(*str) == 0)
            str++;
        if (*str == '\0')
            break ;
        start = str;
        while (*str && ft_isdigit(*str))
            str++;
        cur_str = ft_substr(start, 0, str - start);
        errno = 0;
        cur_num = strtol(cur_str, &endptr, 10); 
        if (errno)
            printf("ERRIR") ;
        free(cur_str);
        add_nbr_to_lst(lst, cur_num);
    }
}

void pnf_list(t_dlist *lst, int free_flag)
{
    t_dlist *current;

    while (lst != NULL)
    {
        if (lst->content != NULL)
            printf("contents: %d\n", *(int *)lst->content);
        else
            printf("content is NULL\n");
        current = lst;
        lst = lst->next;
        if (free_flag)
        {
            free(current->content);
            free(current);
        }
    }
    printf("\n");
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
    if (argc == 1)
        ft_putstr_fd("Error\n", 2);
    else if (argc == 2)
        lst_from_str(argv[1], &a);
    if (errno)
    {
        printf("ERROR\n");
        return (0);
    }
    b = get_ntl(a);
    ft_putstr_fd("list b:\n", 1);
    pnf_list(b, 0);
    ft_putstr_fd("list a:\n", 1);
    pnf_list(a, 1);
    return (0);
}
