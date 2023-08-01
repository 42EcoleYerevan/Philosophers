/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:29:06 by agladkov          #+#    #+#             */
/*   Updated: 2023/07/31 18:30:06 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_zero_validator(char *str)
{
	if (ft_number_validator(str))
		return (1);
	if (ft_atoi(str) == 0)
		return (1);
	return (0);
}

int	ft_empty_validator(char *str)
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
