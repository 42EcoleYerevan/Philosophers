/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:07:30 by agladkov          #+#    #+#             */
/*   Updated: 2023/07/27 12:09:21 by agladkov         ###   ########.fr       */
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
	pthread_mutex_lock(&philo->info->print_mutex);
	if (philo->info->print)
	{
		time = ft_get_current_time() - philo->info->timestamp;
		printf("%lu %d %s\n", time, philo->id, message);
	}
	pthread_mutex_unlock(&philo->info->print_mutex);
}

void	ft_usleep(int ms)
{
	unsigned long	start;

	start = ft_get_time();
	usleep(ms * 950);
	while (ft_get_time() - start < (unsigned long) ms)
		usleep(10);
}
