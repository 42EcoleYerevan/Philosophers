/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:10:05 by agladkov          #+#    #+#             */
/*   Updated: 2023/07/27 12:51:45 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		ft_atoi(char *str);
char	*ft_strchr(char c, char *str);
int		ft_number_validator(char *str);
int		ft_negative_validator(char *str);
int		ft_intmax_validator(char *str);
int		ft_is_empty(char *str);

int	is_valid_argv(int argc, char **argv)
{
	while (--argc > 0)
	{
		if (ft_is_empty(argv[argc]) || \
			ft_number_validator(argv[argc]) == 1 || \
			ft_negative_validator(argv[argc]) == 1 || \
			ft_intmax_validator(argv[argc]) == 1)
			return (1);
	}
	return (0);
}

int	ft_is_empty(char *str)
{
	if (!str || !*str)
		return (1);
	return (0);
}

int	ft_number_validator(char *str)
{
	char	*valchars;

	valchars = "1234567890";
	while (*str)
	{
		if (ft_strchr(*str, valchars) == NULL)
			return (1);
		str++;
	}
	return (0);
}

int	ft_negative_validator(char *str)
{
	while (*str && *str == ' ')
		str++;
	if (*str == '-')
		return (1);
	return (0);
}

int	ft_intmax_validator(char *str)
{
	int	num;

	num = 0;
	num = ft_atoi(str);
	if (num == -1)
		return (1);
	return (0);
}
