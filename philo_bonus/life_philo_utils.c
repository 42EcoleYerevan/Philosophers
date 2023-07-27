#include "philo.h"

void ft_take_forks(t_philo *philo)
{
	sem_wait(philo->info->forks);
	ft_message(philo, TAKE_FORKS);
	sem_wait(philo->info->forks);
	ft_message(philo, TAKE_FORKS);
}

void	ft_put_forks(t_philo *philo)
{
	sem_post(philo->info->forks);
	sem_post(philo->info->forks);
}
