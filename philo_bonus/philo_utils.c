/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:04:20 by agladkov          #+#    #+#             */
/*   Updated: 2023/07/31 18:34:34 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_run_process(t_info *info, int i);
void	ft_killer(t_info *info);

void	ft_run(t_info *info)
{
	int	i;
	int	status;

	i = 0;
	while (i < info->number_of_philosophers)
	{
		info->childs[i] = fork();
		if (info->childs[i] == 0)
		{
			ft_run_process(info, i);
			exit(0);
		}
		i++;
	}
	while (waitpid(-1, &status, 0) != -1)
	{
		if (status != 0)
			ft_message(info->philos + (status / 256 - 1), DIED);
		ft_killer(info);
		exit(1);
	}
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
}

void	ft_run_process(t_info *info, int i)
{
	pthread_t	checker;

	pthread_create(&checker, NULL, ft_checker, info->philos + i);
	ft_life_philo(info->philos + i);
	pthread_join(checker, NULL);
}
