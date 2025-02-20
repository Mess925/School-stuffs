/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messs <messs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:40:28 by hthant            #+#    #+#             */
/*   Updated: 2025/02/20 12:03:55 by messs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long timestamp(void)
{
	struct timeval tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int init_data(int ac, char **av, t_data *data)
{
	int i;

	i = 0;
	data->num_philo = ft_atoi(av[1]);
	data->time_die = ft_atoi(av[2]);
	data->time_eat = ft_atoi(av[3]);
	data->time_sleep = ft_atoi(av[4]);
	if (ac == 6)
		data->max_meal = ft_atoi(av[5]);
	else
		data->max_meal = -1;
	if (data->num_philo == ERROR || data->time_die == ERROR || data->time_eat == ERROR || data->time_sleep == ERROR || (ac == 6 && data->max_meal == ERROR))
		return (printf("Error: Invalid input arguments.\n"), ERROR);
	data->start_time = timestamp();
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philo);
	if (!data->forks)
		return (printf("Malloc allocation failed\n"), ERROR);
	while (i < data->num_philo)
	{
		if (pthread_mutex_init(&data->forks[i], NULL) != 0)
			return (printf("Mutex initilization failed\n"), ERROR);
		i++;
	}
	if (pthread_mutex_init(&data->print_mtx, NULL) != 0)
		return (printf("Error: Failed to initialize print mutex\n"), ERROR);
	if (pthread_mutex_init(&data->state_mtx, NULL) != 0)
		return (printf("Error: Failed to initialize state mutex\n"), ERROR);
	return (SUCCESS);
}

int init_philo(t_philo *philo, t_data *data)
{
	int i;

	i = 0;
	while (i < data->num_philo)
	{
		philo[i].id = i;
		philo[i].total_meal = 0;
		philo[i].last_meal_eaten_time = data->start_time;
		philo[i].left_fork = &data->forks[i];
		philo[i].right_fork = &data->forks[(i + 1) % data->num_philo];
		if (pthread_mutex_init(&philo[i].meal_mutex, NULL) != 0)
		{
			printf("Error: Failed to initialize meal_mutex for philo %d\n", i);
			while (--i >= 0)
				pthread_mutex_destroy(&philo[i].meal_mutex);
			return (ERROR);
		}
		i++;
	}
	return (SUCCESS);
}

void destroy_mutex(t_data *data)
{
	int i;

	i = 0;
	while (i < data->num_philo)
		pthread_mutex_destroy(&data->forks[i++]);
	pthread_mutex_destroy(&data->print_mtx);
	pthread_mutex_destroy(&data->state_mtx);
}
void create_philo_threads(t_philo *philo)
{
}

int main(int ac, char **av)
{
	t_data *data;
	t_philo *philo;
	int i;

	i = 0;
	if (ac == 5 || ac == 6)
	{
		data = malloc(sizeof(t_data));
		if (!data)
			return (printf("Malloc allocation failed\n"), ERROR);
		if (init_data(ac, av, data) == SUCCESS)
		{
			philo = malloc(sizeof(t_philo) * data->num_philo);
			if (!philo)
			{
				printf("Malloc allocation failed\n");
				destroy_mutex(data);
				free(data);
				return (ERROR);
			}
			if (init_philo(philo, data) != SUCCESS)
			{
				destroy_mutex(data);
				free(philo);
				free(data);
				return (ERROR);
			}
			create_philo_threads(philo);
			destroy_mutex(data);
			free(philo);
		}
		else
		{
			free(data);
			return (ERROR);
		}
		free(data);
	}
	else
		return (printf("Invalid number of arguments\n"), ERROR);
	return (SUCCESS);
}
