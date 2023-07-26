/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agladkov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 19:02:53 by agladkov          #+#    #+#             */
/*   Updated: 2023/07/26 19:02:56 by agladkov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <sys/time.h>
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>

# define TAKE_FORKS 	"has taken a fork"
# define EAT			"is eating"
# define SLEEP			"is sleeping"
# define THINK			"is thinking"
# define DIED			"died"

typedef struct s_info
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	int				print;
	int				die_status;
	unsigned long	timestamp;
	struct s_philo	*philos;
	pthread_t		checker;
	pthread_mutex_t	*forks;
	pthread_mutex_t	die_mutex;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	time_to_eat_mutex;
	pthread_mutex_t	time_to_die_mutex;
}	t_info;

typedef struct s_philo
{
	int				id;
	int				num_ate;
	int				last_eat_time;
	struct s_info	*info;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	num_ate_mutex;
	pthread_mutex_t	last_ate_mutex;
}	t_philo;

// validator
int				is_valid_argv(int argc, char **argv);
int				ft_atoi(char *str);

//init info
t_info			*ft_init_info(char **argv);

// init philo
t_philo			*ft_init_philos(t_info *info);

// life philo
void			*ft_life_philo(void *philo);

// life philo utils
void			ft_take_forks(t_philo *philo);
void			ft_put_forks(t_philo *philo);

// philo utils
void			ft_run(t_info *info);

// print info
void			ft_print_info(t_info *info);

// utils
unsigned long	ft_get_current_time(void);
void			ft_message(t_philo *philo, char *message);
void			ft_usleep(int ms);

// checker
void			*ft_checker(void *info);
int				ft_is_died(t_philo *philo);

// checker utils
int				ft_check_die(t_philo *philo);
void			ft_philo_mutex_lock(t_philo *philo);
void			ft_philo_mutex_unlock(t_philo *philo);

#endif
