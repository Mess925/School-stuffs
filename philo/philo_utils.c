/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/08 15:40:17 by hthant            #+#    #+#             */
/*   Updated: 2025/02/08 18:00:42 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
