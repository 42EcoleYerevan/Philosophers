#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
#include <sys/_pthread/_pthread_mutex_t.h>
# include <sys/time.h>
# include <stdio.h>
# include <pthread.h>

typedef struct s_info
{
	int number_of_philosophers;
	int	time_to_die;
	int time_to_eat;
	int time_to_sleep;
	int number_of_times_each_philosopher_must_eat;
	int	timestamp;
	struct s_philo *philos;
	pthread_mutex_t *forks;
	pthread_mutex_t print;
} t_info;

typedef struct s_philo
{
	int id;
	int last_eat_time;
	int num_ate;
	struct s_info *info;
	pthread_t thread;
	pthread_mutex_t *left_fork;
	pthread_mutex_t *right_fork;
	pthread_mutex_t num_ate_mmutex;
	pthread_mutex_t last_ate_mmutex;
} t_philo;

int		is_valid_argv(int argc, char **argv);
int		ft_atoi(char *str);
t_info	*ft_init_info(char **argv);
t_philo	*ft_init_philo(t_info *info);
void	*ft_thread(void *info);

#endif
