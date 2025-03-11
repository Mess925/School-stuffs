/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 15:10:39 by hthant            #+#    #+#             */
/*   Updated: 2025/03/11 17:06:22 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_error(t_data *data, int ac)
{
	if (data->num_philo <= 0 || data->time_die <= 0 || \
		data->time_eat <= 0 || data->time_sleep <= 0 || \
		(ac == 6 && data->max_meal <= 0))
		return (printf("Error: Invalid input arguments.\n"), ERROR);
	return (0);
}

int	mutex_init(t_data *data)
{
	int	i;

	i = 0;
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
	return (0);
}

int	init_data(int ac, char **av, t_data *data)
{
	data->num_philo = ft_atoi(av[1]);
	data->time_die = ft_atoi(av[2]);
	data->time_eat = ft_atoi(av[3]);
	data->time_sleep = ft_atoi(av[4]);
	data->check_death = 1;
	data->philo = NULL;
	if (ac == 6)
		data->max_meal = ft_atoi(av[5]);
	else
		data->max_meal = -1;
	if (check_error(data, ac) == ERROR)
		return (ERROR);
	data->start_time = get_time();
	data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philo);
	if (!data->forks)
		return (printf("Malloc allocation failed\n"), ERROR);
	if (mutex_init(data) == ERROR)
		return (ERROR);
	return (SUCCESS);
}

int	init_philo(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		philo[i].id = i;
		philo[i].data = data;
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
