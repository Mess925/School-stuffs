/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messs <messs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:39:15 by messs             #+#    #+#             */
/*   Updated: 2024/11/19 18:18:13 by messs            ###   ########.fr       */
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

    data->num_philosophers = atoi(argv[1]);
    data->time_to_die = atoi(argv[2]);
    data->time_to_eat = atoi(argv[3]);
    data->time_to_sleep = atoi(argv[4]);
    if (argc == 6)
        data->number_of_times_to_eat = atoi(argv[5]);
    else
        data->number_of_times_to_eat = -1;

    data->forks = malloc(sizeof(pthread_mutex_t) * data->num_philosophers);
    while(i < data->num_philosophers)
    {
        pthread_mutex_init(&data->forks[i], NULL);
        i++;
    }
    pthread_mutex_init(&data->print_mutex, NULL);

    return data;
}
void *philo_task(void *arg)
{
    t_philosopher *philo = (t_philosopher *)arg;
    pthread_t death_thread;
    pthread_create(&death_thread, NULL, check_death, philo); 
    pthread_detach(death_thread);

    int meals_eaten = 0;
    while (meals_eaten < philo->data->number_of_times_to_eat || philo->data->number_of_times_to_eat == -1) {
        printf("%ld %d is thinking\n", get_current_time(), philo->id);

        // Try to take forks
        pthread_mutex_lock(&philo->data->forks[philo->id - 1]); // Left fork
        printf("%ld %d has taken a fork\n", get_current_time(), philo->id);

        pthread_mutex_lock(&philo->data->forks[philo->id % philo->data->num_philosophers]); // Right fork
        printf("%ld %d has taken a fork\n", get_current_time(), philo->id);

        // Eating
        philo->last_meal_time = get_current_time(); // Update last meal time
        printf("%ld %d is eating\n", get_current_time(), philo->id);
        usleep(philo->data->time_to_eat * 1000); // Simulate eating for 'time_to_eat'

        // Increment meals eaten
        meals_eaten++;

        // Put down forks
        pthread_mutex_unlock(&philo->data->forks[philo->id - 1]);
        pthread_mutex_unlock(&philo->data->forks[philo->id % philo->data->num_philosophers]);

        // Sleeping
        printf("%ld %d is sleeping\n", get_current_time(), philo->id);
        usleep(philo->data->time_to_sleep * 1000); // Simulate sleeping for 'time_to_sleep'
    }

    return NULL;
}



