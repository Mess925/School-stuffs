/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messs <messs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:39:19 by messs             #+#    #+#             */
/*   Updated: 2024/11/23 17:32:12 by messs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long get_current_time(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000 + tv.tv_usec / 1000); 
}

void check_death(t_philosopher *philo)
{
    long current_time = get_current_time();
    t_data *data = philo->data;
    long time_since_last_meal = current_time - philo->last_meal_time;

    if (time_since_last_meal >= data->time_to_die && !philo->dead)
    {
        philo->dead = 1;
        pthread_mutex_lock(&data->output);
        printf("%ld %d died\n", current_time, philo->id);
        pthread_mutex_unlock(&data->output);

        pthread_mutex_lock(&data->death);
    }
}

void print_status(t_philosopher *philo, char *status)
{
    long timestamp = get_current_time();
    
    pthread_mutex_lock(&philo->data->output); 
    printf("%ld %d %s\n", timestamp, philo->id, status);
    pthread_mutex_unlock(&philo->data->output);
}


int	ft_atoi(const char *nptr)
{
	int		i;
	int		j;
	char	sign;

	i = 0;
	j = 0;
	sign = '+';
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = '-';
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		j = (j * 10 + nptr[i]) - '0';
		i++;
	}
	if (sign == '-')
	{
		j = j * -1;
	}
	return (j);
}