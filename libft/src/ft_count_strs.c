#include "../inc/libft.h"

size_t	ft_count_strs(char **strs)
{
	size_t	i;

	i = 0;
	while (strs && strs[i])
		i++;
	return (i);
}
