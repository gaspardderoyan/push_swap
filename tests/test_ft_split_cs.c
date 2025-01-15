#include "../inc/project.h"

// ANSI escape codes for colors
#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define RESET   "\x1b[0m"
#define BOLD "\033[1m"

void test_ft_split_cs_normal(void)
{
	char	*expected[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", NULL};
	char	**actual = ft_split_cs("1 2 3 4\t5 6 7 8 9 10", " \t");
	char	**cpy = actual;

	int i = 0;
	while (expected[i] && *actual)
	{
		if (ft_strlen(expected[i]) != ft_strlen(*actual))
		{
			printf("%sFAIL: %s%s\n", RED, __func__, RESET);
			printf("Expected len: %zu ; ", ft_strlen(expected[i]));
			printf("Actual len: %zu\n", ft_strlen(*actual));
			printf("Expected str: %s ; ", expected[i]);
			printf("Actual str: %s\n", *actual);
			ft_free_strs(cpy);
			return ;
		}
		if (ft_strncmp(expected[i], *actual, ft_strlen(expected[i])))
		{
			printf("%sFAIL: %s%s\n", RED, __func__, RESET);
			printf("Expected str: %s ; ", expected[i]);
			printf("Actual str: %s\n", *actual);
			ft_free_strs(cpy);
			return ;
		}
		i++;
		actual++;
	}
	printf("%sPASS: %s%s\n", GREEN, __func__, RESET);
	ft_free_strs(cpy);
}

void test_ft_split_cs_multi_spaces(void)
{
	char	*expected[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9", "10", NULL};
	char	**actual = ft_split_cs("1 2    3 4\t5 6 7 8 9 10", " \t");
	char	**cpy = actual;

	int i = 0;
	while (expected[i] && *actual)
	{
		if (ft_strlen(expected[i]) != ft_strlen(*actual))
		{
			printf("%sFAIL: %s%s\n", RED, __func__, RESET);
			printf("Expected len: %zu ; ", ft_strlen(expected[i]));
			printf("Actual len: %zu\n", ft_strlen(*actual));
			printf("Expected str: %s ; ", expected[i]);
			printf("Actual str: %s\n", *actual);
			ft_free_strs(cpy);
			return ;
		}
		if (ft_strncmp(expected[i], *actual, ft_strlen(expected[i])))
		{
			printf("%sFAIL: %s%s\n", RED, __func__, RESET);
			printf("Expected str: %s ; ", expected[i]);
			printf("Actual str: %s\n", *actual);
			ft_free_strs(cpy);
			return ;
		}
		i++;
		actual++;
	}
	ft_free_strs(cpy);
	printf("%sPASS: %s%s\n", GREEN, __func__, RESET);
}

int	main(void)
{
    printf(BOLD "\nFT_SPLIT_CS\n" RESET);
	test_ft_split_cs_normal();
	test_ft_split_cs_multi_spaces();
	return (0);
}
