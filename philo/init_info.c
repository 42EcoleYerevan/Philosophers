#include "philo.h"

pthread_mutex_t *ft_init_forks(t_info *info)
{
	int	indx_fork;

	if (!info)
		return (NULL);
	info->forks = (pthread_mutex_t *)malloc( \
			sizeof(pthread_mutex_t) * info->number_of_philosophers);
	if (!info->forks)
		return (NULL);
	indx_fork = 0;
	while (indx_fork < info->number_of_philosophers)
	{
		pthread_mutex_init(&info->forks[indx_fork], NULL);
		indx_fork++;
	}
	return (info->forks);
}

t_info *ft_init_info(char **argv)
{

	t_info *info;
	struct timeval current_time;
	
	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return (NULL);
	info->number_of_philosophers = ft_atoi(argv[1]);
	info->number_of_times_each_philosopher_must_eat = ft_atoi(argv[2]);
	info->time_to_die = ft_atoi(argv[3]);
	info->time_to_eat = ft_atoi(argv[4]);
	info->time_to_sleep = ft_atoi(argv[5]);
	gettimeofday(&current_time, NULL);
	info->timestamp = current_time.tv_sec * 1000 + current_time.tv_usec / 1000;
	if (!info->number_of_times_each_philosopher_must_eat || \
			!info->number_of_philosophers || \
			!info->time_to_die || \
			!info->time_to_eat || \
			!info->time_to_sleep)
		return (NULL);
	pthread_mutex_init(&info->print, NULL);
	ft_init_forks(info);
	return (info);
}
