#include "../libft/inc/libft.h"
#include <errno.h>
#include <string.h>

int	ft_isspace(int c)
{
	unsigned char	cc;

	cc = (unsigned char)c;

	if ((cc >= 9 && cc <= 13) || cc == 32)
		return (1);
	return (0);
}

// strspn
int	base_index(char c, int base)
{
	int	i;
	char		base_chars[37] = "0123456789abcdefghijklmnopqrstuvwxyz";

	i = 0;
	while (base_chars[i] && i < base)
	{
		if (base_chars[i] == ft_tolower(c))
			return (i);
		i++;
	}
	return (-1);
}

int	base_validate(char c, int base)
{
	int	i;
	char		base_chars[37] = "0123456789abcdefghijklmnopqrstuvwxyz";

	i = 0;
	while (i < base)
	{
		if (base_chars[i] == ft_tolower(c))
			return (1);
		i++;
	}
	return (0);
}

void	skip_lead(const char **nptr, int *pola)
{
	while (ft_isspace(**nptr))
		(*nptr)++;
	if (**nptr == '-')
		*pola = -1;
	if (**nptr == '+' || **nptr == '-')
		(*nptr)++;
}

long long handle_overflow(char **endptr, const char *nptr, int over)
{
	errno = ERANGE;
	if (endptr)
		*endptr = (char *)nptr;
	if (over)
		return LLONG_MAX;
	return LLONG_MIN;
}

long long	ft_strtoll(const char *nptr, char **endptr, int base)
{
	int			pola;
	int			i;
	long long	n;
	long long	prev_n;
	const char	*c_nptr = nptr;

	pola = 1;
	n = 0;
	if (base < 2 || base > 36)
		return (errno = EINVAL, 0);
	skip_lead(&nptr, &pola);
	while (*nptr && ft_isalnum(*nptr))
	{
		i = base_index(*nptr, base);
		errno = 0;
		if (i < 0)
		{
			*endptr = (char* )nptr;
			if (nptr == c_nptr)
			{
				errno = EINVAL;
				return (0);
			}
			break;
		}
		prev_n = n;
		if (pola == 1 && (n < prev_n || (prev_n > 0 && n > LLONG_MAX - i)))
			return (handle_overflow(endptr, nptr, 1));
		if (pola == -1 && (n > prev_n || (prev_n < 0 && n < LLONG_MIN + i)))
			return (handle_overflow(endptr, nptr, 0));
		n += i;
		if (base_validate(*(nptr + 1), base))
			n *= base;
		nptr++;
	}
	return (n * pola);
}


void test_strtoll(const char *input, int base) {
    char *endptr_ft = NULL;
    char *endptr_std = NULL;
    long result_ft, result_std;
    int errno_ft = 0, errno_std = 0;

    // Test custom implementation
    errno = 0;
    result_ft = ft_strtoll(input, &endptr_ft, base);
    errno_ft = errno;
    // Test standard implementation
    errno = 0;
    result_std = strtoll(input, &endptr_std, base);
    errno_std = errno;

    // Print results
    printf("\nInput: '%s', Base: %d\n", input, base);
    printf("ft_strtoll:  Result: %ld, Endptr: '%s', Errno: %d\n",
           result_ft, endptr_ft ? endptr_ft : "(null)", errno_ft);
    printf("strtoll:     Result: %ld, Endptr: '%s', Errno: %d\n",
           result_std, endptr_std ? endptr_std : "(null)", errno_std);

    if (result_ft != result_std || (endptr_ft && strcmp(endptr_ft, endptr_std) != 0) || errno_ft != errno_std) {
        printf("[FAIL] Mismatch detected\n");
    } else {
        printf("[PASS] Match\n");
    }
}

int main(void) {
    // Test cases
    const char *inputs[] = {
        "123",            // Simple valid input
        "-123",           // Negative number
        "0",              // Zero
        "2147483647",     // INT_MAX
        "-2147483648",    // INT_MIN
        "9223372036854775807", // LONG_MAX
        "-9223372036854775808", // LONG_MIN
        "abcd",           // Invalid input
        "  42",           // Leading whitespace
        "42abc",          // Trailing invalid characters
        "",               // Empty string
        " ",              // String with only whitespace
        "+42",            // Explicit positive sign
        "-",              // Lone negative sign
        "+",              // Lone positive sign
        "999999999999999999999999", // Out of range
        "-999999999999999999999999" // Out of range negative
    };

    int bases[] = {10, 16}; // Decimal, Hexadecimal, Octal, and Auto-detect

    // Run tests
    for (int i = 0; i < sizeof(inputs) / sizeof(inputs[0]); i++) {
        for (int j = 0; j < sizeof(bases) / sizeof(bases[0]); j++) {
            test_strtoll(inputs[i], bases[j]);
        }
    }

    return 0;
}

