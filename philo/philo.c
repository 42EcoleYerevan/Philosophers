#include "philo.h"

void ft_destroy(t_info *info)
{
	int i;

	pthread_mutex_destroy(&info->print_mutex);
	pthread_mutex_destroy(&info->time_to_die_mutex);
	pthread_mutex_destroy(&info->time_to_eat_mutex);
	pthread_mutex_destroy(&info->die_mutex);
	i = 0;
	while (i < info->number_of_philosophers)
	{
		pthread_mutex_destroy(&info->philos[i].last_ate_mutex);
		pthread_mutex_destroy(&info->philos[i].num_ate_mutex);
		i++;
	}
}

int main(int argc, char **argv)
{
	t_info *info;

	if (argc < 5)
		return (1);
	else
	{
		if (is_valid_argv(argc, argv))
			return (1);
		info = ft_init_info(argv);
		if (!info)
			return (1);
		if (!ft_init_philos(info))
			return (1);
		ft_run(info);
	}
	return (0);
}
