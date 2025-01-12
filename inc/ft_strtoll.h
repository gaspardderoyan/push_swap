#ifndef STRTOLL_H
# define STRTOLL_H

typedef struct s_strtol_mt
{
	int			sign;
	int			index;
	int			empty;
	long long	n;
} t_strtol_mt;

long long	mini_strtoll(const char *nptr, int radix);

#endif
