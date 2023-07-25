#include "philo.h"

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
