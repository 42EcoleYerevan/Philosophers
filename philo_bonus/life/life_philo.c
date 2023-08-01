/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:56:44 by agladkov          #+#    #+#             */
/*   Updated: 2023/08/01 20:14:31 by agladkov         ###   ########.fr       */
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
		usleep(_philo->info->time_to_die * 1000);
	while (1)
	{
		ft_take_forks(_philo);
		ft_eat(_philo);
		ft_put_forks(_philo);
		ft_sleep(_philo);
		ft_think(_philo);
	}
	return (NULL);
}

void	ft_eat(t_philo *philo)
{
	sem_wait(philo->info->num_ate_sem);
	philo->num_ate++;
	sem_post(philo->info->num_ate_sem);
	sem_wait(philo->info->last_eat_time_sem);
	philo->last_eat_time = (int) ft_get_current_time();
	sem_post(philo->info->last_eat_time_sem);
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
