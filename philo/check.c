/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:16:02 by hthant            #+#    #+#             */
/*   Updated: 2025/02/28 15:25:04 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_each_philo_dead(t_data *data, int i)
{
	long	last_eaten_by_philo;

	pthread_mutex_lock(&data->philo[i].meal_mutex);
	last_eaten_by_philo = get_time() - data->philo[i].last_meal_eaten_time;
	pthread_mutex_unlock(&data->philo[i].meal_mutex);
	if (last_eaten_by_philo > data->time_die)
	{
		pthread_mutex_lock(&data->state_mtx);
		data->check_death = 1;
		pthread_mutex_unlock(&data->state_mtx);
		if (data->num_philo != 1)
			printf("%ld %d died\n", \
				get_time() - data->start_time, data->philo[i].id);
		return (1);
	}
	return (0);
}

int	check_done_meal_count(t_data *data)
{
	int	i;
	int	meal_done;

	i = 0;
	meal_done = 1;
	while (i < data->num_philo)
	{
		pthread_mutex_lock(&data->philo[i].meal_mutex);
		if (data->max_meal == -1 || data->philo[i].total_meal < data->max_meal)
			meal_done = 0;
		pthread_mutex_unlock(&data->philo[i].meal_mutex);
		if (!meal_done)
			break ;
		i++;
	}
	return (meal_done);
}

void	*check_dead(void *args)
{
	t_data	*data;
	int		i;

	data = (t_data *)args;
	while (1 && data->num_philo != 1)
	{
		i = 0;
		while (i < data->num_philo)
		{
			if (check_each_philo_dead(data, i))
				return (NULL);
			i++;
		}
		pthread_mutex_lock(&data->state_mtx);
		if (check_done_meal_count(data) && data->max_meal != -1)
		{
			data->check_death = 1;
			pthread_mutex_unlock(&data->state_mtx);
		}
		pthread_mutex_unlock(&data->state_mtx);
		usleep(5000);
	}
	return (NULL);
}
