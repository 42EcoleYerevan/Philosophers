/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_philo_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:57:30 by agladkov          #+#    #+#             */
/*   Updated: 2023/07/31 17:35:53 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_take_forks(t_philo *philo)
{
	if (sem_wait(philo->info->forks) == -1)
	{
		philo->info->die_status = 1;
		return ;
	}
	ft_message(philo, TAKE_FORKS);
	if (sem_wait(philo->info->forks) == -1)
	{
		philo->info->die_status = 1;
		return ;
	}
	ft_message(philo, TAKE_FORKS);
}

void	ft_put_forks(t_philo *philo)
{
	sem_post(philo->info->forks);
	sem_post(philo->info->forks);
}
