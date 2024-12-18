#include "../libft/inc/libft.h"

void    lst_from_str(char *str, t_list **lst)
{
    int     cur_num;
    char    *cur_str;
    char    *start;

    while (*str)
    {
        if (ft_isdigit(*str) == 0)
            str++;
        else 
        {
            start = str;
            while (ft_isdigit(*str) && *str)
                str++;
            cur_str = ft_substr(start, 0, str - start); 
            cur_num = ft_atoi(cur_str);
            ft_lstadd_front(lst, ft_lstnew(&cur_num));
            printf("%i\n", *(int *)(*lst)->content);
            free(cur_str);
            str++;
        }
    }
}

void    print_node(void *n)
{
    printf("%i\n", *(int *)n);
}

int main(int argc, char **argv)
{
    t_list *a;

    if (argc == 1)
        ft_putstr_fd("Error\n", 2);
    else if (argc == 2)
    {
        ft_putstr_fd(argv[1], 1);
        ft_putstr_fd("\n", 1);
        lst_from_str(argv[1], &a);
        // ft_lstiter(a, &print_node);
    }

    return (0);
}
