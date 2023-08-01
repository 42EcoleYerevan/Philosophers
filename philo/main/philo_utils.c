/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:04:20 by agladkov          #+#    #+#             */
/*   Updated: 2023/07/27 14:16:08 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_create_philo_threads(t_info *info);
void	ft_join_philos(t_info *info);

void	ft_run(t_info *info)
{
	ft_create_philo_threads(info);
	ft_join_philos(info);
}

void	ft_create_philo_threads(t_info *info)
{
	int		i;
	t_philo	*philos;

	philos = info->philos;
	i = 0;
	while (i < info->number_of_philosophers)
	{
		pthread_create(&philos[i].thread, NULL, ft_life_philo, &philos[i]);
		i++;
	}
	pthread_create(&info->checker, NULL, ft_checker, info);
}

void	ft_join_philos(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->number_of_philosophers)
	{
		pthread_join(info->philos[i].thread, NULL);
		i++;
	}
	pthread_join(info->checker, NULL);
}
