/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:59:43 by agladkov          #+#    #+#             */
/*   Updated: 2023/07/27 12:51:25 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_info	*info;

	if (argc < 5)
	{
		printf("Error\n");
		return (1);
	}
	else
	{
		if (is_valid_argv(argc, argv))
			return (1);
		info = ft_init_info(argv);
		if (!info)
			return (1);
		if (!ft_init_philos(info))
			return (1);
		ft_run(info);
	}
	return (0);
}
