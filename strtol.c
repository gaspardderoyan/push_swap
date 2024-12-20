#include "../libft/inc/libft.h"
#include <errno.h>
#include <stdbool.h>
#include <limits.h>

int ft_isspace(int c)
{
	unsigned char cc = (unsigned char)c;
	return ((cc >= 9 && cc <= 13) || cc == 32);
}

int base_index(char c, int radix)
{
	const char *base = "0123456789abcdefghijklmnopqrstuvwxyz";
	int index;

	index = 0;
	c = ft_tolower(c);
	while (base[index] && index < radix)
	{
		if (base[index] == c)
			return index;
		index++;
	}
	return -1;
}

int handle_overflow(int sign, long long *n, int digit, int radix)
{

	if (sign == 1 && *n > (LLONG_MAX - digit) / radix)
	{
		errno = ERANGE;
		*n = LLONG_MAX;
		return (true);
	}
	if (sign == -1 && -(*n) < (LLONG_MIN + digit) / radix)
	{
		errno = ERANGE;
		*n = LLONG_MIN;
		return (true);
	}
	return (false);
}

void skip_lead(const char **nptr, int *sign, int *radix)
{
	while (ft_isspace(**nptr))
		(*nptr)++;
	*sign = 1;
	if (**nptr == '-')
	{
		*sign = -1;
		(*nptr)++;
	}
	else if (**nptr == '+')
		(*nptr)++;
	if ((*radix == 0 || *radix == 16) && **nptr == '0'
		&& (ft_tolower(*(*nptr + 1)) == 'x'))
		{
			*nptr += 2;
			*radix = 16;
		}
	else if (*radix == 0 && **nptr == '0')
	{
		(*nptr)++;
		*radix = 8;
	}
	else if (*radix == 0)
		*radix = 10;

}


long long mini_strtoll(const char *nptr, char **endptr, int radix)
{
	int			sign;
	int			index;
	long long	n;

	sign = 1;
	n = 0;
	skip_lead(&nptr, &sign, &radix);
	if (base_index(*nptr, radix) == -1 || radix < 2 || radix > 36)
		return (errno = EINVAL, 0);
	while (*nptr && ft_isalnum(*nptr) && (base_index(*nptr, radix) > -1))
	{
		index = base_index(*nptr, radix);
		if (handle_overflow(sign, &n, index, radix))
			return (*endptr = (char *)nptr, n);
		n = n * radix + index;
		nptr++;
	}
	*endptr = (char *)nptr;
	return (n * sign);
}

void test_mini_strtoll(const char *str, int base, long long expected)
{
	char *endptr;
	endptr = NULL;
    errno = 0;
    long long result = mini_strtoll(str, &endptr, base);
    if (result == expected && ((errno == 0) || (expected == LLONG_MAX && errno == ERANGE) || (expected == LLONG_MIN && errno == ERANGE) || (expected == 0 && errno == EINVAL)))
    {
        printf("PASS: mini_strtoll(\"%s\", %d) = %lld\n", str, base, result);
    }
    else
    {
        printf("FAIL: mini_strtoll(\"%s\", %d) = %lld (Expected: %lld, errno: %d)\n", str, base, result, expected, errno);
    }
}

int main(void)
{
    // Valid conversions
    test_mini_strtoll("12345", 10, 12345);
    test_mini_strtoll("-12345", 10, -12345);
    test_mini_strtoll("7fffffff", 16, 2147483647);
    test_mini_strtoll("-80000000", 16, -2147483648);
    test_mini_strtoll("   +42", 10, 42);
    test_mini_strtoll("101010", 2, 42);
    test_mini_strtoll("2a", 16, 42);
    test_mini_strtoll("z", 36, 35);
    test_mini_strtoll("ZZ", 36, 1295); // 35*36 + 35 = 1295

    // Edge cases
    test_mini_strtoll("", 10, 0); // Invalid input
    test_mini_strtoll("   ", 10, 0); // Only spaces
    test_mini_strtoll("+", 10, 0); // Only plus sign
    test_mini_strtoll("-", 10, 0); // Only minus sign
    test_mini_strtoll("+-2", 10, 0); // Invalid sign
    test_mini_strtoll("123abc", 10, 123); // Stops at first non-digit
    test_mini_strtoll("abc123", 10, 0); // Invalid starting character

    // Invalid bases
    test_mini_strtoll("123", 1, 0); // Invalid base
    test_mini_strtoll("123", 37, 0); // Invalid base

    // Overflow cases
    test_mini_strtoll("9223372036854775807", 10, LLONG_MAX); // Max LLONG
    test_mini_strtoll("9223372036854775808", 10, LLONG_MAX); // Overflow
    test_mini_strtoll("-9223372036854775808", 10, LLONG_MIN); // Min LLONG
    test_mini_strtoll("-9223372036854775809", 10, LLONG_MIN); // Underflow

    // Base-specific edge cases
    test_mini_strtoll("0", 10, 0);
    test_mini_strtoll("0000123", 10, 123);
    test_mini_strtoll("1z", 36, 71); // 1*36 + 35 = 71
    test_mini_strtoll("G", 16, 0); // Invalid character for base 16

    return 0;
}

