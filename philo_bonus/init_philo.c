/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:56:17 by agladkov          #+#    #+#             */
/*   Updated: 2023/07/27 18:56:05 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*ft_malloc_philos(t_info *info);
void	ft_init_philo(t_info *info, int id);
void	ft_init_philos_loop(t_info *info);
int		ft_init_sems(t_philo *philo);

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
	info->philos[id].last_eat_time = info->timestamp;
	info->philos[id].info = info;
	info->philos[id].num_ate_sem = sem_open("num_ate_sem", 1);
	info->philos[id].last_ate_sem = sem_open("last_ate_sem", 1);
}
