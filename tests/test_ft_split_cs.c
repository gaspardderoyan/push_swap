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


void test_ft_split_cs_normal(void)
{
	char	*expected[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", NULL};
	char	**actual = ft_split_cs("1 2 3 4\t5 6 7 8 9 10", " \t");

	int i = 0;
	while (expected[i] && *actual)
	{
		if (ft_strlen(expected[i]) != ft_strlen(*actual))
		{
			printf("%sFAIL: %s%s\n", COLOR_RED, __func__, COLOR_RESET);
			printf("Expected len: %zu ; ", ft_strlen(expected[i]));
			printf("Actual len: %zu\n", ft_strlen(*actual));
			printf("Expected str: %s ; ", expected[i]);
			printf("Actual str: %s\n", *actual);
			TEST_FAIL();
			return ;
		}
		if (ft_strncmp(expected[i], *actual, ft_strlen(expected[i])))
		{
			printf("%sFAIL: %s%s\n", COLOR_RED, __func__, COLOR_RESET);
			printf("Expected str: %s ; ", expected[i]);
			printf("Actual str: %s\n", *actual);
			TEST_FAIL();
			return ;
		}
		i++;
		actual++;
	}
	printf("%sPASS: %s%s\n", COLOR_GREEN, __func__, COLOR_RESET);
}

void test_ft_split_cs_multi_spaces(void)
{
	char	*expected[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", NULL};
	char	**actual = ft_split_cs("1 2    3 4\t5 6 7 8 9 10", " \t");

	int i = 0;
	while (expected[i] && *actual)
	{
		if (ft_strlen(expected[i]) != ft_strlen(*actual))
		{
			printf("%sFAIL: %s%s\n", COLOR_RED, __func__, COLOR_RESET);
			printf("Expected len: %zu ; ", ft_strlen(expected[i]));
			printf("Actual len: %zu\n", ft_strlen(*actual));
			printf("Expected str: %s ; ", expected[i]);
			printf("Actual str: %s\n", *actual);
			TEST_FAIL();
			return ;
		}
		if (ft_strncmp(expected[i], *actual, ft_strlen(expected[i])))
		{
			printf("%sFAIL: %s%s\n", COLOR_RED, __func__, COLOR_RESET);
			printf("Expected str: %s ; ", expected[i]);
			printf("Actual str: %s\n", *actual);
			TEST_FAIL();
			return ;
		}
		i++;
		actual++;
	}
	printf("%sPASS: %s%s\n", COLOR_GREEN, __func__, COLOR_RESET);
}

int	main(void)
{
	UNITY_BEGIN();
	RUN_TEST(test_ft_split_cs_normal);
	RUN_TEST(test_ft_split_cs_multi_spaces);
	return (UNITY_END());
}
