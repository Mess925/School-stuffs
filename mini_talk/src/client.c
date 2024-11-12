/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 21:54:51 by hthant            #+#    #+#             */
/*   Updated: 2024/10/29 16:24:14 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	chartobinary(int *array, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		array[7 - i] = (c >> i) & 1;
		i++;
	}
}

void	ft_sendchar(int pid, char c)
{
	int	bit[8];
	int	i;

	chartobinary(bit, c);
	i = 0;
	while (i < 8)
	{
		if (bit[i] == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			ft_sendchar(pid, argv[2][i]);
			i++;
		}
		ft_sendchar(pid, 10);
	}
	else
	{
		ft_printf("ERROR\n");
		return (1);
	}
	return (0);
}
