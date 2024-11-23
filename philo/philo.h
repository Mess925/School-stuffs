/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messs <messs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 18:37:18 by messs             #+#    #+#             */
/*   Updated: 2024/11/23 17:34:55 by messs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>

typedef struct s_data
{
    int num_philosophers;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int number_of_times_to_eat;
    pthread_mutex_t *forks;
    pthread_mutex_t death;
    pthread_mutex_t output;
}t_data;

typedef struct s_philosopher {
    int id; 
    long last_meal_time;
    int times_eaten; 
    int dead;
    pthread_t thread;
    t_data *data; 
} t_philosopher;


// philo_init.c
t_data *init_data(int argc, char **argv);
void *philo_task(void *arg);

// utils.c
long get_current_time(void);
void check_death(t_philosopher *philo);
int	ft_atoi(const char *nptr);
void print_status(t_philosopher *philo, char *state);
#endif