/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:39:54 by hthant            #+#    #+#             */
/*   Updated: 2025/02/28 15:32:58 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <errno.h>
# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

# define SUCCESS 0
# define ERROR -1

typedef struct s_philo	t_philo;

typedef struct s_data
{
	int				num_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				max_meal;
	long			start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mtx;
	pthread_mutex_t	state_mtx;
	pthread_t		vader;
	int				check_death;
	t_philo			*philo;
}	t_data;

typedef struct s_philo
{
	int				id;
	int				total_meal;
	long			last_meal_eaten_time;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	meal_mutex;
	t_data			*data;
}	t_philo;

int		ft_atoi(const char *str);
long	get_time(void);
int		init_data(int ac, char **av, t_data *data);
void	print_status(t_philo *philo, char *status);
void	destroy_mutex(t_data *data);
int		should_stop(t_philo *philo);
int		init_data(int ac, char **av, t_data *data);
int		init_philo(t_philo *philo, t_data *data);
void	*philo_tasks(void *arg);
void	*check_dead(void *args);

#endif
