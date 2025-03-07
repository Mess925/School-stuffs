/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:36:21 by hthant            #+#    #+#             */
/*   Updated: 2025/03/07 21:09:41 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo_bonus.h"

int init_data(t_data *data, int ac, char **av)
{
    data->nbr_philo = atol(av[1]);
    data->t_to_die = atol(av[2]);
    data->t_to_eat = atol(av[3]);
    data->t_to_sleep = atol(av[4]);
    if(ac == 6)
        data->nbr_t_to_eat = atol(av[5]);
    else
        data->nbr_t_to_eat = -1;
    
}

int main(int ac, char **av)
{
    t_data  *data;
    if(ac < 5 || ac > 6 || init_data(data, ac , av) == -1)
        return(printf("Invilid Input\n"), 1);
}