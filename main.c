#include "../libft/inc/libft.h"

void    add_nbr_to_lst(t_list **lst, int n)
{
    int *new;
    new = (int *)malloc(sizeof(int));
    if (!new)
        return ;
    *new = n;
    ft_lstadd_back(lst, ft_lstnew(new));
}

void    lst_from_str(char *str, t_list **lst)
{
    int     cur_num;
    char    *cur_str;
    char    *start;

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
        cur_num = ft_atoi(cur_str); 
        free(cur_str);
        add_nbr_to_lst(lst, cur_num);
    }
}

void pnf_list(t_list *lst, int free_flag)
{
    t_list *current;

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
}

void swap_first(t_list **lst)
{
    void *temp;

    if (!lst || !*lst || !(*lst)->next)
        return ;
    temp = (*lst)->next->content;
    (*lst)->next->content = (*lst)->content;
    (*lst)->content = temp;
}

void    swap_first_both(t_list **a, t_list **b, void (f)(t_list**))
{
    f(a);
    f(b);
}

void    push_first(t_list **in, t_list **out)
{
    t_list *temp;

    if (!in || !*in || !(*in)->content)
        return ;
    temp = *in;
    *in = (*in)->next;
    temp->next = NULL;
    ft_lstadd_front(out, temp);
}

int main(int argc, char **argv)
{
    t_list *a;
    t_list *b;

    a = NULL;
    b = NULL;
    if (argc == 1)
        ft_putstr_fd("Error\n", 2);
    else if (argc == 2)
    {
        ft_putstr_fd(argv[1], 1);
        ft_putstr_fd("\n", 1);
        lst_from_str(argv[1], &a);
    }

    ft_putstr_fd("list a:\n", 1);
    // pnf_list(a, 0);
    ft_putstr_fd("\n", 1);
    // swap_first(&a);
    // ft_putstr_fd("pushing the first\n", 1);
    push_first(&a, &b);
    // ft_putstr_fd("list a:\n", 1);
    // pnf_list(a, 0);
    // ft_putstr_fd("list b:\n", 1);
    // pnf_list(b, 0);
    swap_first_both(&a, &b, &swap_first);
    ft_putstr_fd("pushing the first\n", 1);
    ft_putstr_fd("list a:\n", 1);
    pnf_list(a, 0);
    ft_putstr_fd("list b:\n", 1);
    pnf_list(b, 0);
    return (0);
}
