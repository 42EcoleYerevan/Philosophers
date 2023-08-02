/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:04:20 by agladkov          #+#    #+#             */
/*   Updated: 2023/08/02 11:15:13 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_run_process(t_info *info, int i);
void	ft_killer(t_info *info);
void	ft_waiter(t_info *info);
void	ft_runner(t_info *info);

void	ft_run(t_info *info)
{
	ft_runner(info);
	ft_waiter(info);
}

void	ft_runner(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->number_of_philosophers)
	{
		info->childs[i] = fork();
		if (info->childs[i] == -1)
		{
			printf("Error (FORK)\n");
			exit(1);
		}
		if (info->childs[i] == 0)
			ft_run_process(info, i);
		i++;
	}
}

void	ft_waiter(t_info *info)
{
	int	status;

	while (waitpid(-1, &status, 0) != -1)
	{
		if (status)
		{
			ft_killer(info);
			exit(1);
		}
	}
	ft_killer(info);
	exit(0);
}

void	ft_killer(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->number_of_philosophers)
	{
		kill(info->childs[i], SIGKILL);
		i++;
	}
	ft_close_sem(info);
}

void	ft_run_process(t_info *info, int i)
{
	pthread_create(&info->philos[i].checker, NULL, \
			ft_checker, info->philos + i);
	ft_life_philo(info->philos + i);
	pthread_join(info->philos[i].checker, NULL);
	ft_close_sem(info);
	exit(0);
}
