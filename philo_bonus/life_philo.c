/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:56:44 by agladkov          #+#    #+#             */
/*   Updated: 2023/07/27 19:16:08 by agladkov         ###   ########.fr       */
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
	while (1)
	{
		if (ft_is_died(_philo))
			exit(1);
		ft_take_forks(_philo);
		if (ft_is_died(_philo))
			exit(1);
		ft_eat(_philo);
		if (ft_is_died(_philo))
			exit(1);
		ft_put_forks(_philo);
		if (ft_is_died(_philo))
			exit(1);
		ft_sleep(_philo);
		if (ft_is_died(_philo))
			exit(1);
		ft_think(_philo);
	}
	exit(0);
}

void	ft_eat(t_philo *philo)
{
	sem_wait(philo->last_ate_sem);
	sem_wait(philo->num_ate_sem);
	philo->num_ate++;
	philo->last_eat_time = (int) ft_get_current_time();
	sem_post(philo->num_ate_sem);
	sem_post(philo->last_ate_sem);
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
