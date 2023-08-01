/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:10:05 by agladkov          #+#    #+#             */
/*   Updated: 2023/07/31 18:30:42 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_valid_argv(int argc, char **argv)
{
	while (--argc > 0)
	{
		if (ft_empty_validator(argv[argc]) || \
			ft_number_validator(argv[argc]) || \
			ft_negative_validator(argv[argc]) || \
			ft_intmax_validator(argv[argc]) || \
			ft_zero_validator(argv[argc]))
		{
			printf("Error\n");
			return (1);
		}
	}
	return (0);
}
