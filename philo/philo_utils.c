/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:40:17 by hthant            #+#    #+#             */
/*   Updated: 2025/02/28 15:27:58 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutex(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->num_philo)
		pthread_mutex_destroy(&data->forks[i++]);
	pthread_mutex_destroy(&data->print_mtx);
	pthread_mutex_destroy(&data->state_mtx);
}

void	print_status(t_philo *philo, char *status)
{
	long	time;

	pthread_mutex_lock(&philo->data->print_mtx);
	pthread_mutex_lock(&philo->data->state_mtx);
	if (!philo->data->check_death)
	{
		time = get_time() - philo->data->start_time;
		printf("%ld %d %s\n", time, philo->id + 1, status);
	}
	pthread_mutex_unlock(&philo->data->state_mtx);
	pthread_mutex_unlock(&philo->data->print_mtx);
}

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

int	ft_atoi(const char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
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

int	should_stop(t_philo *philo)
{
	int	stop;

	pthread_mutex_lock(&philo->data->state_mtx);
	stop = (philo->data->check_death || \
			(philo->data->max_meal != -1 && \
				philo->total_meal >= philo->data->max_meal));
	pthread_mutex_unlock(&philo->data->state_mtx);
	return (stop);
}
