/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:56:17 by agladkov          #+#    #+#             */
/*   Updated: 2023/07/31 18:34:06 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_init_one_philo(t_info *info, int indx);
t_philo	*ft_malloc_philos(t_info *info);

int	ft_init_philo(t_info *info)
{
	int	indx;

	info->philos = ft_malloc_philos(info);
	if (!info->philos)
		return (1);
	indx = 0;
	while (indx < info->number_of_philosophers)
	{
		ft_init_one_philo(info, indx);
		indx++;
	}
	return (0);
}

t_philo	*ft_malloc_philos(t_info *info)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(sizeof(t_philo) * \
			info->number_of_philosophers);
	return (philo);
}

void	ft_init_one_philo(t_info *info, int indx)
{
	info->philos[indx].id = indx + 1;
	info->philos[indx].info = info;
	info->philos[indx].num_ate = 0;
	info->philos[indx].last_eat_time = ft_get_current_time();
	info->philos[indx].info = info;
}
