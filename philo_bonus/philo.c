/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:36:21 by hthant            #+#    #+#             */
/*   Updated: 2025/03/06 17:42:06 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo_bonus.h"

int init_data(t_data *s_data)
{
    
}

int main(int ac, char **av)
{
    t_data  *data;
    if(ac < 5 || ac > 6 || init_data(data) == -1)
        return(printf("Invilid Input\n"), 1);
}