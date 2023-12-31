/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:53:32 by agladkov          #+#    #+#             */
/*   Updated: 2023/08/01 20:13:53 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_is_died(t_philo *philo)
{
	sem_wait(philo->info->die_sem);
	if (philo->info->die_status)
	{
		ft_put_forks(philo);
		sem_post(philo->info->die_sem);
		exit(1);
	}
	sem_post(philo->info->die_sem);
	return (0);
}
