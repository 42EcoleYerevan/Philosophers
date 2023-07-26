/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:53:32 by agladkov          #+#    #+#             */
/*   Updated: 2023/07/26 19:12:14 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_philo_mutex_lock(t_philo *philo)
{
	pthread_mutex_lock(&philo->last_ate_mutex);
	pthread_mutex_lock(&philo->num_ate_mutex);
}

void	ft_philo_mutex_unlock(t_philo *philo)
{
	pthread_mutex_unlock(&philo->num_ate_mutex);
	pthread_mutex_unlock(&philo->last_ate_mutex);
}

int	ft_is_died(t_philo *philo)
{
	pthread_mutex_lock(&philo->info->die_mutex);
	if (philo->info->die_status)
	{
		ft_put_forks(philo);
		pthread_mutex_unlock(&philo->info->die_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->info->die_mutex);
	return (0);
}
