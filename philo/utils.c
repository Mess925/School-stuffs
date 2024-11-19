/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messs <messs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:39:19 by messs             #+#    #+#             */
/*   Updated: 2024/11/19 18:13:30 by messs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long get_current_time(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000 + tv.tv_usec / 1000); 
}

void print_state(t_philosopher *philo, const char *state)
{
    long timestamp = get_current_time();
    pthread_mutex_lock(&philo->data->print_mutex); 
    printf("%ld %d %s\n", timestamp, philo->id, state); 
    pthread_mutex_unlock(&philo->data->print_mutex);
}
void *check_death(void *arg)
{
    t_philosopher *philo = (t_philosopher *)arg;

    while (1) {
        if (philo->dead)
        {
            break;
        }
        long current_time = get_current_time();
        long time_since_last_meal = current_time - philo->last_meal_time;

        if (time_since_last_meal > philo->data->time_to_die)
        {
            philo->dead = 1;
            // print_state(philo, "died");
            break;
        }
        usleep(500);
    }
    return NULL;
}
