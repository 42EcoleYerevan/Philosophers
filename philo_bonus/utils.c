/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:07:30 by agladkov          #+#    #+#             */
/*   Updated: 2023/07/27 17:38:03 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	ft_get_time(void);

unsigned long	ft_get_current_time(void)
{
	static unsigned long	start;

	if (!start)
		start = ft_get_time();
	return (ft_get_time() - start);
}

unsigned long	ft_get_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

void	ft_message(t_philo *philo, char *message)
{
	unsigned long	time;

	if (!message)
		return ;
	sem_wait(philo->info->print_sem);
	if (philo->info->print)
	{
		time = ft_get_current_time() - philo->info->timestamp;
		printf("%lu %d %s\n", time, philo->id, message);
	}
	sem_post(philo->info->print_sem);
}

void	ft_usleep(int ms)
{
	unsigned long	start;

	start = ft_get_current_time();
	while (ft_get_current_time() - start < (unsigned long) ms)
		usleep(10);
}
