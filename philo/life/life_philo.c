/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:56:44 by agladkov          #+#    #+#             */
/*   Updated: 2023/08/02 12:10:33 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_eat(t_philo *philo);
void	ft_sleep(t_philo *philo);
void	ft_think(t_philo *philo);

void	*ft_life_philo(void *philo)
{
	t_philo	*_philo;

	_philo = (t_philo *)philo;
	if (_philo->info->number_of_philosophers == 1)
		ft_usleep(_philo->info->time_to_die + 2);
	while (1)
	{
		if (ft_is_died(_philo))
			return (NULL);
		ft_take_forks(_philo);
		if (ft_is_died(_philo))
			return (NULL);
		ft_eat(_philo);
		if (ft_is_died(_philo))
			return (NULL);
		ft_put_forks(_philo);
		if (ft_is_died(_philo))
			return (NULL);
		ft_sleep(_philo);
		if (ft_is_died(_philo))
			return (NULL);
		ft_think(_philo);
	}
	return (NULL);
}

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->last_ate_mutex);
	philo->last_eat_time = (int) ft_get_current_time();
	pthread_mutex_unlock(&philo->last_ate_mutex);
	pthread_mutex_lock(&philo->num_ate_mutex);
	philo->num_ate++;
	pthread_mutex_unlock(&philo->num_ate_mutex);
	ft_message(philo, EAT);
	ft_usleep(philo->info->time_to_eat);
}

void	ft_sleep(t_philo *philo)
{
	ft_message(philo, SLEEP);
	ft_usleep(philo->info->time_to_sleep);
}

void	ft_think(t_philo *philo)
{
	ft_message(philo, THINK);
}
