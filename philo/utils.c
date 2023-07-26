/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:07:30 by agladkov          #+#    #+#             */
/*   Updated: 2023/07/26 19:09:19 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	ft_get_time(void);

void	ft_print_info(t_info *info)
{
	printf("time_to_die: %d\n", info->time_to_die);
	printf("time_to_sleep: %d\n", info->time_to_sleep);
	printf("time_to_eat: %d\n", info->time_to_sleep);
	printf("timestamp: %lu\n", info->timestamp);
	printf("number_of_philosophers: %d\n", info->number_of_philosophers);
	printf("number_of_times_each_philosopher_must_eat: %d\n", \
			info->number_of_times_each_philosopher_must_eat);
}

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

	start = ft_get_current_time();
	while (ft_get_current_time() - start < (unsigned long) ms)
		usleep(10);
}
