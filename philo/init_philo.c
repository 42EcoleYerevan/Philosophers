/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:56:17 by agladkov          #+#    #+#             */
/*   Updated: 2023/07/27 11:46:58 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*ft_malloc_philos(t_info *info);
void	ft_init_philo(t_info *info, int id);
void	ft_init_philos_loop(t_info *info);

t_philo	*ft_init_philos(t_info *info)
{
	if (!info)
		return (NULL);
	ft_malloc_philos(info);
	if (!info->philos)
		return (NULL);
	ft_init_philos_loop(info);
	return (info->philos);
}

t_philo	*ft_malloc_philos(t_info *info)
{
	info->philos = (t_philo *)malloc(\
			sizeof(t_philo) * info->number_of_philosophers);
	if (!info->philos)
		return (NULL);
	return (info->philos);
}

void	ft_init_philos_loop(t_info *info)
{
	int	idx_philo;

	idx_philo = 0;
	while (idx_philo < info->number_of_philosophers)
	{
		ft_init_philo(info, idx_philo);
		idx_philo++;
	}
}

void	ft_init_philo(t_info *info, int id)
{
	info->philos[id].id = id + 1;
	info->philos[id].info = info;
	info->philos[id].num_ate = 0;
	pthread_mutex_init(&info->philos[id].num_ate_mutex, NULL);
	info->philos[id].last_eat_time = info->timestamp;
	pthread_mutex_init(&info->philos[id].last_ate_mutex, NULL);
	info->philos[id].right_fork = &info->forks[id];
	info->philos[id].left_fork = \
		&info->forks[(id + 1) % info->number_of_philosophers];
	info->philos[id].info = info;
	info->philos[id].died = 0;
	pthread_mutex_init(&info->philos[id].die_mutex, NULL);
}
