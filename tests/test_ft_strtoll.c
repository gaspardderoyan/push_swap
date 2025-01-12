// test_ft_strtoll.c
#include "../unity/unity.h"
#include "../inc/project.h"

// ANSI escape codes for colors
#define COLOR_RED     "\x1b[31m"
#define COLOR_GREEN   "\x1b[32m"
#define COLOR_RESET   "\x1b[0m"

void setUp(void)
{
    // set stuff up here
}

void tearDown(void)
{
    // clean stuff up here
}

void test_strtoll(const char *input, int base, long long expected, int expected_errno) {
    long long result;
    int original_errno = errno;

    errno = 0;
    result = mini_strtoll(input, base);

    if (result == expected && errno == expected_errno) {
        printf(COLOR_GREEN "  Passed: " COLOR_RESET "Result = %lld, errno = %d\n", result, errno);
    } else {
        printf(COLOR_RED "  Failed: " COLOR_RESET);
		printf("Input: \"%s\", Base: %d\n", input, base);
        printf("Expected Result = %lld, Actual Result = %lld\n", expected, result);
        printf("Expected errno = %d, Actual errno = %d\n", expected_errno, errno);
		TEST_FAIL();
    }
    errno = original_errno;
}

int	main(void)
{
	UNITY_BEGIN();
    printf("Basic decimal conversion:\n");
    test_strtoll("12345", 10, 12345, 0);
    test_strtoll("+12345", 10, 12345, 0);
    test_strtoll("-12345", 10, -12345, 0);
    test_strtoll("   12345", 10, 12345, 0);
    test_strtoll("   +12345", 10, 12345, 0);
    test_strtoll("   -12345", 10, -12345, 0);
    
    printf("Basic octal conversion:\n");
    test_strtoll("010", 0, 8, 0);
    test_strtoll("010", 8, 8, 0);
    test_strtoll("  -010", 0, -8, 0);

    printf("Basic hexadecimal conversion:\n");
    test_strtoll("0x1A", 16, 26, 0);
    test_strtoll("0X1a", 16, 26, 0);
    test_strtoll("0x1A", 0, 26, 0);
    test_strtoll("   -0x1A", 16, -26, 0);
    test_strtoll("   -0x1a", 0, -26, 0);
    

    printf("Other bases conversion:\n");
    test_strtoll("101101", 2, 45, 0);
    test_strtoll("FF", 16, 255, 0);
    test_strtoll("ff", 16, 255, 0);
    test_strtoll("z", 36, 35, 0);
    test_strtoll("Z", 36, 35, 0);

	printf("Bases with trailing unaccepted characters:\n");
    test_strtoll("0108abcde", 8, 8, 0);
    

    printf("Invalid input:\n");
    test_strtoll("abc", 10, 0, EINVAL);
    test_strtoll("   ", 10, 0, EINVAL);
    test_strtoll("", 10, 0, EINVAL);
    test_strtoll("12ab", 10, 12, 0);
    test_strtoll("0xxyz", 16, 0, EINVAL);
    test_strtoll("0xxyz", 0, 0, EINVAL);

    printf("Invalid base:\n");
    test_strtoll("123", 1, 0, EINVAL);
    test_strtoll("123", 37, 0, EINVAL);
    test_strtoll("123", -1, 0, EINVAL);

    printf("Overflow and underflow:\n");
    test_strtoll("9223372036854775807", 10, LLONG_MAX, 0);  // LLONG_MAX
    test_strtoll("9223372036854775808", 10, LLONG_MAX, ERANGE);
    test_strtoll("-9223372036854775808", 10, LLONG_MIN, 0); // LLONG_MIN
    test_strtoll("-9223372036854775809", 10, LLONG_MIN, ERANGE);
	UNITY_END();
}
