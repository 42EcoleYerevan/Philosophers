#include "philo.h"

pthread_mutex_t	*ft_init_forks(t_info *info);
int				ft_init_forks_loop(t_info *info);

t_info *ft_init_info(char **argv)
{
	t_info			*info;
	
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
	info->print = 1;
	pthread_mutex_init(&info->print_mutex, NULL);
	pthread_mutex_init(&info->time_to_die_mutex, NULL);
	pthread_mutex_init(&info->time_to_eat_mutex, NULL);
	info->timestamp = ft_get_current_time();
	ft_init_forks(info);
	return (info);
}

pthread_mutex_t *ft_init_forks(t_info *info)
{
	if (!info)
		return (NULL);
	info->forks = (pthread_mutex_t *)malloc( \
			sizeof(pthread_mutex_t) * info->number_of_philosophers);
	if (!info->forks)
		return (NULL);
	if (ft_init_forks_loop(info) != 0)
		return (NULL);
	return (info->forks);
}

int	ft_init_forks_loop(t_info *info)
{
	int	indx_fork;

	indx_fork = 0;
	while (indx_fork < info->number_of_philosophers)
	{
		if (pthread_mutex_init(&info->forks[indx_fork], NULL) != 0)
			return (1);
		indx_fork++;
	}
	return (0);
}
