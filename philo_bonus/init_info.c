/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 18:54:13 by agladkov          #+#    #+#             */
/*   Updated: 2023/07/31 17:35:45 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_init_values(t_info *info, char **argv);
static int	ft_init_sems(t_info *info);

t_info	*ft_init_info(char **argv)
{
	t_info	*info;

	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return (NULL);
	if (ft_init_values(info, argv))
		return (NULL);
	if (ft_init_sems(info))
		return (NULL);
	return (info);
}

static int	ft_init_values(t_info *info, char **argv)
{
	info->number_of_philosophers = ft_atoi(argv[1]);
	info->time_to_die = ft_atoi(argv[2]);
	info->time_to_eat = ft_atoi(argv[3]);
	info->time_to_sleep = ft_atoi(argv[4]);
	info->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	if (!info->number_of_philosophers || \
			!info->time_to_die || \
			!info->time_to_eat || \
			!info->time_to_sleep)
		return (1);
	info->print = 1;
	info->die_status = 0;
	return (0);
}

static int	ft_init_sems(t_info *info)
{
	if (!info->number_of_philosophers)
		return (1);;
	sem_unlink("die_sem");
	sem_unlink("print_sem");
	sem_unlink("last_eat_time_sem");
	sem_unlink("num_ate_sem");
	sem_unlink("forks");
	info->die_sem = sem_open("die_sem", O_CREAT, 0666, 1);
	info->print_sem = sem_open("print_sem", O_CREAT, 0666, 1);
	info->last_eat_time_sem = sem_open("last_eat_time_sem", O_CREAT, 0666, 1);
	info->num_ate_sem = sem_open("num_ate_sem", O_CREAT, 0666, 1);
	info->forks = sem_open("forks", O_CREAT, 0666, info->number_of_philosophers);
	if (info->die_sem == SEM_FAILED || \
		info->print_sem == SEM_FAILED|| \
		info->last_eat_time_sem == SEM_FAILED || \
		info->num_ate_sem == SEM_FAILED || \
		info->forks == SEM_FAILED)
		return (1);
	return (0);
}
