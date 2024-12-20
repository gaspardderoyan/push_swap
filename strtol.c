#include "../libft/inc/libft.h"
#include <errno.h>
#include <limits.h>

int ft_isspace(int c)
{
	unsigned char cc = (unsigned char)c;
	return ((cc >= 9 && cc <= 13) || cc == 32);
}

int base_index(char c, int base)
{
	const char *base_chars = "0123456789abcdefghijklmnopqrstuvwxyz";
	int index;

	index = 0;
	c = ft_tolower(c);
	while (base_chars[index] && index < base)
	{
		if (base_chars[index] == c)
			return index;
		index++;
	}
	return -1;
}

void skip_lead(const char **nptr, int *sign)
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
	{
		(*nptr)++;
	}
}

long long handle_overflow(int sign)
{
	errno = ERANGE;
	if (sign == 1)
		return LLONG_MAX;
	else
		return LLONG_MIN;
}

long long mini_strtoll(const char *nptr, int base)
{
	int sign;
	long long n;
	int digit;

	n = 0;
	skip_lead(&nptr, &sign);
	if (!ft_isalnum(*nptr) || base < 2 || base > 36)
		return (errno = EINVAL, 0);
	while (*nptr && ft_isalnum(*nptr))
	{
		digit = base_index(*nptr, base);
		if (digit == -1)
			break;
		if (sign == 1)
			if (n > (LLONG_MAX - digit) / base)
				return handle_overflow(sign);
		if (sign == -1)
			if (-n < (LLONG_MIN + digit) / base)
				return handle_overflow(sign);
		n = n * base + digit;
		nptr++;
	}
	return n * sign;
}

void test_mini_strtoll(const char *str, int base, long long expected)
{
    errno = 0;
    long long result = mini_strtoll(str, base);
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

