#include "../inc/libft.h"

char	*strdup_safe(const char *s)
{
	size_t	len;
	char	*new;
	int		i;

	if (!s)
		return (NULL);
	len = strlen_safe(s);
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (s[i])
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
