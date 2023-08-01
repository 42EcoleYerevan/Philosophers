/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:52:31 by agladkov          #+#    #+#             */
/*   Updated: 2023/08/01 14:48:15 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		ft_died_from_starvation(t_philo *philo);
int		ft_eaten_enough(t_philo *philo);

void	*ft_checker(void *_philo)
{
	t_philo	*philo;

	philo = (t_philo *)_philo;
	while (1)
	{
		if (ft_died_from_starvation(philo) || \
			ft_eaten_enough(philo))
			return (NULL);
	}
	return (NULL);
}

int	ft_died_from_starvation(t_philo *philo)
{
	sem_wait(philo->info->last_eat_time_sem);
	if (ft_get_current_time() - philo->last_eat_time > \
			(unsigned long)philo->info->time_to_die)
		exit(philo->id);
	sem_post(philo->info->last_eat_time_sem);
	return (0);
}

int	ft_eaten_enough(t_philo *philo)
{
	sem_wait(philo->info->num_ate_sem);
	if (philo->info->number_of_times_each_philosopher_must_eat && \
			philo->num_ate > \
			philo->info->number_of_times_each_philosopher_must_eat)
		exit(0);
	sem_post(philo->info->num_ate_sem);
	return (0);
}
