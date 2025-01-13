#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include "../inc/project.h"

#define GREEN "\033[32m"
#define RED "\033[31m"
#define RESET "\033[0m"
#define BOLD "\033[1m"

void test_strtoll(const char *input, int base, long long expected, int expected_errno) {
    long long result;
    int original_errno = errno;

    errno = 0;
    printf("Testing input: \"%s\", base: %d\n", input, base);

    result = mini_strtoll(input, base);

    if (result == expected && errno == expected_errno) {
        printf(GREEN "  Passed: " RESET "Result = %lld, errno = %d\n", result, errno);
    } else {
        printf(RED "  Failed: " RESET);
        printf("Input: \"%s\", Base: %d\n", input, base);
        printf("  Expected Result = %lld, Actual Result = %lld\n", expected, result);
        printf("  Expected errno = %d, Actual errno = %d\n", expected_errno, errno);
    }
    errno = original_errno;
}

int main(void) {
    printf(BOLD "\nSTRTOLL\n" RESET);

    printf(BOLD "Basic decimal conversion:\n" RESET);
    test_strtoll("12345", 10, 12345, 0);
    test_strtoll("+12345", 10, 12345, 0);
    test_strtoll("-12345", 10, -12345, 0);
    test_strtoll("   12345", 10, 12345, 0);
    test_strtoll("   +12345", 10, 12345, 0);
    test_strtoll("   -12345", 10, -12345, 0);

    printf(BOLD "Basic octal conversion:\n" RESET);
    test_strtoll("010", 0, 8, 0);
    test_strtoll("010", 8, 8, 0);
    test_strtoll("  -010", 0, -8, 0);

    printf(BOLD "Basic hexadecimal conversion:\n" RESET);
    test_strtoll("0x1A", 16, 26, 0);
    test_strtoll("0X1a", 16, 26, 0);
    test_strtoll("0x1A", 0, 26, 0);
    test_strtoll("   -0x1A", 16, -26, 0);
    test_strtoll("   -0x1a", 0, -26, 0);

    printf(BOLD "Other bases conversion:\n" RESET);
    test_strtoll("101101", 2, 45, 0);
    test_strtoll("FF", 16, 255, 0);
    test_strtoll("ff", 16, 255, 0);
    test_strtoll("z", 36, 35, 0);
    test_strtoll("Z", 36, 35, 0);

    printf(BOLD "Bases with trailing unaccepted characters:\n" RESET);
    test_strtoll("0108abcde", 8, 8, 0);

    printf(BOLD "Invalid input:\n" RESET);
    test_strtoll("abc", 10, 0, EINVAL);
    test_strtoll("   ", 10, 0, EINVAL);
    test_strtoll("", 10, 0, EINVAL);

    printf(BOLD "Invalid base:\n" RESET);
    test_strtoll("123", 1, 0, EINVAL);
    test_strtoll("123", 37, 0, EINVAL);
    test_strtoll("123", -1, 0, EINVAL);

    printf(BOLD "Overflow and underflow:\n" RESET);
    test_strtoll("9223372036854775807", 10, LLONG_MAX, 0);  // LLONG_MAX
    test_strtoll("9223372036854775808", 10, LLONG_MAX, ERANGE);
    test_strtoll("-9223372036854775808", 10, LLONG_MIN, 0); // LLONG_MIN
    test_strtoll("-9223372036854775809", 10, LLONG_MIN, ERANGE);
	

    return 0;
}
