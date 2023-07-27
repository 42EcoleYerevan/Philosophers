/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:04:20 by agladkov          #+#    #+#             */
/*   Updated: 2023/07/27 19:11:26 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <pthread.h>

void	ft_fork_philo(t_info *info);
void	ft_init_threads(t_philo *philo);

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
		if (info->childs[i] == -1)
			exit(1);
		if (info->childs[i] == 0)
		{
			ft_init_threads(info->philos + i);
			exit(0);
		}
		i++;
	}
	while (wait(NULL) != -1);
	/* puts("leha"); */
}

void	ft_init_threads(t_philo *philo)
{
	pthread_create(&philo->thread, NULL, &ft_life_philo, philo);
	pthread_create(&philo->checker, NULL, &ft_checker, philo);
	pthread_join(philo->thread, NULL);
	pthread_join(philo->checker, NULL);
}
