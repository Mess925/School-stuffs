/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:12:39 by hthant            #+#    #+#             */
/*   Updated: 2025/03/03 20:02:59 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	one_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	print_status(philo, "has taken a fork");
	usleep(philo->data->time_die * 1000 + 1000);
	print_status(philo, "died");
	pthread_mutex_unlock(philo->left_fork);
}

void	take_forks(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, "has taken a fork.");
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork.");
	}
	else
	{
		pthread_mutex_lock(philo->left_fork);
		print_status(philo, "has taken a fork.");
		pthread_mutex_lock(philo->right_fork);
		print_status(philo, "has taken a fork.");
	}
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal_eaten_time = get_time();
	philo->total_meal++;
	pthread_mutex_unlock(&philo->meal_mutex);
	print_status(philo, "is eating");
	usleep(philo->data->time_eat * 1000);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	sleep_and_think(t_philo *philo)
{
	print_status(philo, "is sleeping");
	usleep(philo->data->time_sleep * 1000);
	print_status(philo, "is thinking");
	usleep(2000);
}

void	*philo_tasks(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->data->num_philo == 1)
		one_philo(philo);
	else
	{
		if (philo->id % 2 == 0)
			usleep(1000);
		while (1)
		{
			pthread_mutex_lock(&philo->data->state_mtx);
			if (!philo->data->check_death || (philo->data->max_meal != -1 && \
				philo->total_meal >= philo->data->max_meal))
			{
				pthread_mutex_unlock(&philo->data->state_mtx);
				break ;
			}
			pthread_mutex_unlock(&philo->data->state_mtx);
			take_forks(philo);
			eat(philo);
			sleep_and_think(philo);
		}
	}
	return (NULL);
}
