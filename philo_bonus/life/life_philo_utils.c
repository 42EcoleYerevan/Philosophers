/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life_philo_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:57:30 by agladkov          #+#    #+#             */
/*   Updated: 2023/08/01 15:17:38 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_take_forks(t_philo *philo)
{
	sem_wait(philo->info->forks);
	ft_message(philo, TAKE_FORKS);
	sem_wait(philo->info->forks);
	ft_message(philo, TAKE_FORKS);
}

void	ft_put_forks(t_philo *philo)
{
	sem_post(philo->info->forks);
	sem_post(philo->info->forks);
}
