/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messs <messs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:07:53 by messs             #+#    #+#             */
/*   Updated: 2024/11/19 17:48:14 by messs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
    t_data *data;
    t_philosopher *philosphers;
    int i;
    
    data = init_data(ac, av);
    philosphers = malloc(sizeof(t_philosopher)* data->num_philosophers);
    i = 0;
    while (i < data->num_philosophers)
    {
        philosphers[i].id = i +1;
        philosphers[i].data = data;
        pthread_create(&philosphers[i].thread, NULL, philo_task, &philosphers[i]);
        i++;
    }
    i = 0;
    while (i < data->num_philosophers)
    {
        pthread_join(philosphers[i].thread,NULL);
        i++;
    }

    free(philosphers);
    free(data->forks);
    free(data);
    return 0;
}