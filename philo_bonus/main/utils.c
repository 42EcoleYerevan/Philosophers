/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:07:30 by agladkov          #+#    #+#             */
/*   Updated: 2023/08/01 19:53:53 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static unsigned long	ft_get_time(void);

unsigned long	ft_get_current_time(void)
{
	static unsigned long	start;

	if (!start)
		start = ft_get_time();
	return (ft_get_time() - start);
}

static unsigned long	ft_get_time(void)
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
		time = ft_get_current_time();
		printf("%lu %d %s\n", time, philo->id, message);
	}
	sem_post(philo->info->print_sem);
}

void	ft_usleep(int ms)
{
	unsigned long	start;

	start = ft_get_time();
	usleep(ms * 950);
	while (ft_get_time() - start < (unsigned long) ms)
		usleep(10);
}

void	ft_close_sem(t_info *info)
{
	sem_close(info->die_sem);
	sem_close(info->print_sem);
	sem_close(info->num_ate_sem);
	sem_close(info->last_eat_time_sem);
	sem_unlink("die_sem");
	sem_unlink("print_sem");
	sem_unlink("num_ate_sem");
	sem_unlink("last_eat_time_sem");
}
