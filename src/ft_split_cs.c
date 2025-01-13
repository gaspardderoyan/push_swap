#include "../inc/project.h"

static int	ft_count_subs_cs(char const *s, char *cs)
{
	int	count;
	int	in_sub;

	count = 0;
	in_sub = 0;
	while (*s)
	{
		if (ft_strchr(cs, *s))
			in_sub = 0;
		else
		{
			if (in_sub == 0)
			{
				count++;
				in_sub = 1;
			}
		}
		s++;
	}
	return (count);
}


char	**ft_split_cs(char const *s, char *cs)
{
	char	**arr;
	int		i;
	char	*start;

	if (!s)
		return (NULL);
	arr = (char **)malloc(sizeof(char *) * (ft_count_subs_cs(s, cs) + 1));
	if (!arr)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && ft_strchr(cs, *s))
			s++;
		if (*s == '\0')
			break ;
		start = (char *)s;
		while (*s && !ft_strchr(cs, *s))
			s++;
		arr[i++] = ft_substr(start, 0, s - start);
	}
	arr[i] = NULL;
	return (arr);
}
