/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messs <messs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:39:15 by messs             #+#    #+#             */
/*   Updated: 2024/11/23 17:34:17 by messs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_data *init_data(int argc, char **argv)
{
    t_data *data;
    data = malloc(sizeof(t_data));
    if (!data)
        return NULL;
    int i;
    i = 0;

    data->num_philosophers = ft_atoi(argv[1]);
    data->time_to_die = ft_atoi(argv[2]);
    data->time_to_eat = ft_atoi(argv[3]);
    data->time_to_sleep = ft_atoi(argv[4]);
    if (argc == 6)
        data->number_of_times_to_eat = ft_atoi(argv[5]);
    else
        data->number_of_times_to_eat = -1;

    data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philosophers);
    while(i < data->num_philosophers)
    {
        pthread_mutex_init(&data->forks[i], NULL);
        i++;
    }
    pthread_mutex_init(&data->output, NULL);
    return data;
}

void *philo_task(void *arg)
{
    t_philosopher *philo = (t_philosopher *)arg;
    t_data *data = philo->data;
    
    // Initial thinking phase
    while (1)
    {
        // Thinking
        print_status(philo, "is thinking");
        usleep(100);  // Just to simulate thinking

        // Take forks
        pthread_mutex_lock(&data->forks[philo->id - 1]);
        print_status(philo, "has taken a fork");
        pthread_mutex_lock(&data->forks[philo->id % data->num_philosophers]);
        print_status(philo, "has taken a fork");

        // Eating
        print_status(philo, "is eating");
        philo->last_meal_time = get_current_time();
        usleep(data->time_to_eat * 1000);  // Eating for the required time

        // Release forks after eating
        pthread_mutex_unlock(&data->forks[philo->id - 1]);
        pthread_mutex_unlock(&data->forks[philo->id % data->num_philosophers]);

        // Sleeping
        print_status(philo, "is sleeping");
        usleep(data->time_to_sleep * 1000);  // Sleeping for the required time
    }

    return NULL;
}
