/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:52:31 by agladkov          #+#    #+#             */
/*   Updated: 2023/07/27 18:46:27 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		ft_died_from_starvation(t_philo *philo);
int		ft_eaten_enough(t_philo *philo);
void	ft_set_die(t_info *info);

void	*ft_checker(void *philo)
{
	t_philo *_philo;

	_philo = (t_philo *)philo;
	while (1)
	{
		if (ft_died_from_starvation(_philo) || \
			ft_eaten_enough(_philo))
		{
			ft_set_die(_philo->info);
			return (NULL);
		}
	}
}

int	ft_died_from_starvation(t_philo *philo)
{
	sem_wait(philo->last_ate_sem);
	if (ft_get_current_time() - philo->last_eat_time > \
			(unsigned long)philo->info->time_to_die)
	{
		ft_message(philo, "died");
		ft_set_die(philo->info);
		sem_post(philo->last_ate_sem);
		return (1);
	}
	sem_post(philo->last_ate_sem);
	return (0);
}

int	ft_eaten_enough(t_philo *philo)
{

	sem_wait(philo->num_ate_sem);
	if (philo->num_ate < \
			philo->info->number_of_times_each_philosopher_must_eat)
	{
		sem_post(philo->num_ate_sem);
		return (0);
	}
	sem_post(philo->num_ate_sem);
	return (1);
}

void	ft_set_die(t_info *info)
{
	sem_wait(info->print_sem);
	sem_wait(info->die_sem);
	info->print = 0;
	info->die_status = 1;
	sem_post(info->die_sem);
	sem_post(info->print_sem);
}
