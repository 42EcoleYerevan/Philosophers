/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:04:20 by agladkov          #+#    #+#             */
/*   Updated: 2023/07/27 17:37:36 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_fork_philo(t_info *info);

void	ft_run(t_info *info)
{
	ft_fork_philo(info);
}

void ft_fork_philo(t_info *info)
{
	int i;

	i = 0;
	while (i < info->number_of_philosophers)
	{
		info->childs[i] = fork();
		if (info->childs[i] == 0)
			ft_life_philo(info->philos + i);
		i++;
	}
}
