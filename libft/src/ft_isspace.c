
#include "../inc/libft.h"

int	ft_isspace(int c)
{
	const unsigned char	cc = (unsigned char)c;

	return ((cc >= 9 && cc <= 13) || cc == 32);
}
