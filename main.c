#include "../libft/inc/libft.h"

void    add_nbr_to_lst(t_list **lst, int n)
{
    int *new;
    new = (int *)malloc(sizeof(int));
    if (!new)
        return ;
    *new = n;
    ft_lstadd_front(lst, ft_lstnew(new));
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


void print_list(t_list *lst)
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
        free(current->content);
        free(current);
    }
}



int main(int argc, char **argv)
{
    t_list *a;

    a = NULL;
    if (argc == 1)
        ft_putstr_fd("Error\n", 2);
    else if (argc == 2)
    {
        ft_putstr_fd(argv[1], 1);
        ft_putstr_fd("\n", 1);
        lst_from_str(argv[1], &a);
        print_list(a);
    }

    return (0);
}
