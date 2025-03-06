/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:21:39 by hthant            #+#    #+#             */
/*   Updated: 2025/03/06 17:31:10 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS
# define PHILO_BONUS

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <wait.h>
# include <sys/times.h>
# include <unistd.h>
# include <limits.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <semaphore.h>

typedef struct s_data
{
    int     nbr_philo;
    long     t_to_die;
    long    t_to_eat;
    long    t_to_sleep;
    int     nbr_t_to_eat;
    long    start_time;
    sem_t   *fork;
    sem_t   *print;
    sem_t   *death;
}   t_data;


# endif