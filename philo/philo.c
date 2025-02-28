/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:40:28 by hthant            #+#    #+#             */
/*   Updated: 2025/02/28 15:18:35 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_philo_threads(t_philo *philo, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		if (pthread_create(&philo[i].thread, NULL, philo_tasks, \
			(void *)&philo[i]) != 0)
			return (printf("Error: Failed to create philosopher thread\n"), ERROR);
		i++;
	}
	if (pthread_create(&data->vader, NULL, check_dead, data) != 0)
		return (printf("Error: Failed to create check dead thread\n"), ERROR);
	pthread_join(data->vader, NULL);
	i = 0;
	while (i < data->num_philo)
	{
		pthread_join(philo[i].thread, NULL);
		i++;
	}
	return (SUCCESS);
}

int	main(int ac, char **av)
{
	t_data	*data;
	t_philo	*philo;

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
			data->philo = philo;
			create_philo_threads(philo, data);
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
