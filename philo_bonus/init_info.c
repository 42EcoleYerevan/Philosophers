/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:54:13 by agladkov          #+#    #+#             */
/*   Updated: 2023/07/27 19:13:01 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

sem_t	**ft_init_forks(t_info *info);
int		ft_init_childs(t_info *info);
int		ft_init_sems(t_info *info);

t_info	*ft_init_info(char **argv)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return (NULL);
	info->number_of_philosophers = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	info->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	if (!info->number_of_philosophers || \
			!info->time_to_die || \
			!info->time_to_eat || \
			!info->time_to_sleep)
		return (NULL);
	info->timestamp = ft_get_current_time();
	info->die_status = 0;
	if (ft_init_sems(info))
		return (NULL);
	if (ft_init_childs(info))
		return (NULL);
	return (info);
}

int	ft_init_sems(t_info *info)
{
	info->forks = sem_open("forks", info->number_of_philosophers);
	info->die_sem = sem_open("die_sem", 1);
	info->print_sem = sem_open("print_sem", 1);
	info->time_to_die_sem = sem_open("time_to_die", 1);
	info->time_to_die_sem = sem_open("time_to_eat", 1);
	return (0);
}

int	ft_init_childs(t_info *info)
{
	info->childs = (int *)malloc(sizeof(int) * info->number_of_philosophers);
	if (!info->childs)
		return (1);
	return (0);
}
