/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 12:51:47 by agladkov          #+#    #+#             */
/*   Updated: 2023/07/27 12:51:54 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	unsigned int	out;
	int				i;

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
	if (out == 2147483648)
		return (-1);
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
