/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_philo_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:57:30 by agladkov          #+#    #+#             */
/*   Updated: 2023/07/26 18:57:31 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t	*ft_choose_fork(t_philo *philo, int order);

void	ft_take_forks(t_philo *philo)
{
	if (ft_is_died(philo))
	{
		pthread_mutex_unlock(ft_choose_fork(philo, 1));
		return ;
	}
	pthread_mutex_lock(ft_choose_fork(philo, 1));
	ft_message(philo, TAKE_FORKS);
	if (ft_is_died(philo))
	{
		pthread_mutex_unlock(ft_choose_fork(philo, 2));
		return ;
	}
	pthread_mutex_lock(ft_choose_fork(philo, 2));
	ft_message(philo, TAKE_FORKS);
}

void	ft_put_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

pthread_mutex_t	*ft_choose_fork(t_philo *philo, int order)
{
	if (philo->id % 2 == 0)
	{
		if (order % 2 == 0)
			return (philo->left_fork);
		return (philo->right_fork);
	}
	else
	{
		if (order % 2 == 0)
			return (philo->right_fork);
		return (philo->left_fork);
	}
}
