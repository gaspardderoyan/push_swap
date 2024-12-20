int	ft_isspace(int c)
{
	unsigned char	cc;

	cc = (unsigned char)c;

	if ((cc >= 9 && cc <= 13) || cc == 32)
		return (1);
	return (0);
}

int	base_validate(const char *base_chars, char c, int base)
{
	int	i;

	i = 0;
	while (i < base)
	{
		if (base_chars[i] == c)
			return (1);
		i++;
	}
	return (0);
}
