/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:56:17 by agladkov          #+#    #+#             */
/*   Updated: 2023/07/27 16:41:58 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*ft_malloc_philos(t_info *info);
int		ft_init_philo(t_info *info, int id);
int		ft_init_philos_loop(t_info *info);
int		ft_init_sems(t_philo *philo);

void ft_destroy_philos(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->number_of_philosophers)
	{
		free(info->philos + i);
		i++;
	}
	free(info->philos);
}

t_philo	*ft_init_philos(t_info *info)
{
	if (!info)
		return (NULL);
	ft_malloc_philos(info);
	if (!info->philos)
		return (NULL);
	if (ft_init_philos_loop(info))
	{
		ft_destroy_philos(info);
		return (NULL);
	}
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

int	ft_init_philos_loop(t_info *info)
{
	int	idx_philo;

	idx_philo = 0;
	while (idx_philo < info->number_of_philosophers)
	{
		if (ft_init_philo(info, idx_philo))
			return (1);
		idx_philo++;
	}
	return (0);
}

int	ft_init_philo(t_info *info, int id)
{
	info->philos[id].id = id + 1;
	info->philos[id].info = info;
	info->philos[id].num_ate = 0;
	info->philos[id].last_eat_time = info->timestamp;
	info->philos[id].info = info;
	info->philos[id].num_ate_sem = sem_open("num_ate_sem", 1);
	info->philos[id].last_ate_sem = sem_open("last_ate_sem", 1);
	if (!info->philos[id].num_ate_sem || \
		!info->philos[id].last_ate_sem)
		return (1);
	return (0);
}
