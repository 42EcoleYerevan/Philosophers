/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:52:31 by agladkov          #+#    #+#             */
/*   Updated: 2023/07/27 17:40:11 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		ft_died_from_starvation(t_philo *philo);
int		ft_eaten_enough(t_info *info);
void	ft_set_die(t_info *info);

void	*ft_checker(void *info)
{
	int		i;
	t_info	*_info;

	_info = (t_info *) info;
	i = 0;
	while (i < _info->number_of_philosophers)
	{
		if (ft_died_from_starvation(_info->philos + i) || \
			ft_eaten_enough(info))
			return (NULL);
		i++;
		if (i == _info->number_of_philosophers - 1)
			i = 0;
	}
	return (NULL);
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

int	ft_eaten_enough(t_info *info)
{
	int	i;

	i = 0;
	if (!info->number_of_times_each_philosopher_must_eat)
		return (0);
	while (i < info->number_of_philosophers)
	{
		sem_wait(info->philos[i].num_ate_sem);
		if (info->philos[i].num_ate < \
				info->number_of_times_each_philosopher_must_eat)
		{
			sem_post(info->philos[i].num_ate_sem);
			return (0);
		}
		sem_post(info->philos[i].num_ate_sem);
		i++;
	}
	ft_message(info->philos + i - 1, "died");
	ft_set_die(info);
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
