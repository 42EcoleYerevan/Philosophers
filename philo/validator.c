/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:10:05 by agladkov          #+#    #+#             */
/*   Updated: 2023/07/26 19:10:07 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		ft_atoi(char *str);
char	*ft_strchr(char c, char *str);
int		ft_number_validator(char *str);

int	is_valid_argv(int argc, char **argv)
{
	while (--argc > 0)
	{
		if (ft_number_validator(argv[argc]) == 1)
			return (1);
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int	out;
	int	i;

	if (!str)
		return (0);
	out = 0;
	i = 0;
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i])
	{
		out = out * 10 + (str[i] - '0');
		i++;
	}
	return (out);
}

char	*ft_strchr(char c, char *str)
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
