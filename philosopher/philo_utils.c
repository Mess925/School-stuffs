/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:40:17 by hthant            #+#    #+#             */
/*   Updated: 2025/03/03 20:03:10 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
	{
		pthread_mutex_destroy(&data->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&data->print_mtx);
	pthread_mutex_destroy(&data->philo->meal_mutex);
	pthread_mutex_destroy(&data->state_mtx);
	free(data->forks);
}

void	print_status(t_philo *philo, char *status)
{
	long	time;

	pthread_mutex_lock(&philo->data->print_mtx);
	pthread_mutex_lock(&philo->data->state_mtx);
	if (philo->data->check_death)
	{
		time = get_time() - philo->data->start_time;
		printf("%ld %d %s\n", time, philo->id + 1, status);
	}
	pthread_mutex_unlock(&philo->data->state_mtx);
	pthread_mutex_unlock(&philo->data->print_mtx);
}

int	do_atoi(int i, const char *str)
{
	long	j;

	j = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		j = (j * 10) + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0')
	{
		printf("Invalid input: contains non-digit characters.\n");
		return (ERROR);
	}
	if (j > 2147483647)
	{
		printf("It is beyond the int limit.\n");
		return (ERROR);
	}
	return (j);
}

int	ft_atoi(const char *str)
{
	int		i;
	long	j;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
		{
			printf("It only allows positive integers.\n");
			return (ERROR);
		}
		i++;
	}
	j = do_atoi(i, str);
	return (j);
}
