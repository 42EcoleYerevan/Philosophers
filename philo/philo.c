#include "philo.h"

void ft_print_info(t_info *info)
{
	printf("time_to_die: %d\n", info->time_to_die);
	printf("time_to_sleep: %d\n", info->time_to_sleep);
	printf("time_to_eat: %d\n", info->time_to_sleep);
	printf("timestamp: %d\n", info->timestamp);
	printf("number_of_philosophers: %d\n", info->number_of_philosophers);
	printf("number_of_times_each_philosopher_must_eat: %d\n", \
			info->number_of_times_each_philosopher_must_eat);
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
		if (!ft_init_philo(info))
			return (1);
	}
	return (0);
}
