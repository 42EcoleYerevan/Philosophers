#include "philo.h"
#include <stdio.h>

char *ft_strchr(char c, char *str)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	return (NULL);
}

int ft_number_validator(char *str)
{
	char *valchars;

	valchars = "-+1234567890";
	while (*str)
	{
		if (ft_strchr(*str, valchars) == NULL)
			return (1);
		str++;
	}
	return (0);
}

int ft_validate_argv(int argc, char **argv)
{
	while (--argc > 0)
	{
		if (ft_number_validator(argv[argc]) == 1)
			return (1);
	}
	return (0);
}

int main(int argc, char **argv)
{
	if (argc < 5)
		return (1);
	else
	{
		if (ft_validate_argv(argc, argv) == 1)
			return (1);
		printf("ok!\n");
	}
	return (0);
}
