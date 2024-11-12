/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 21:54:57 by hthant            #+#    #+#             */
/*   Updated: 2024/10/29 16:19:57 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	ft_binarytoarr(int sig)
{
	int			bit;
	static int	i = 0;
	static int	array[8];
	char		c;
	int			j;

	if (sig == SIGUSR1)
		bit = 0;
	else
		bit = 1;
	array[i++] = bit;
	if (i == 8)
	{
		c = 0;
		j = 0;
		while (j < i)
		{
			c = (c << 1) | array[j];
			j++;
		}
		ft_printf("%c", c);
		i = 0;
	}
}

int	main(int argc, char *argv[])
{
	int	pid;

	(void)argv;
	if (argc != 1)
	{
		ft_printf("ERROR\n");
		return (1);
	}
	pid = getpid();
	ft_printf("%d\n", pid);
	while (argc == 1)
	{
		signal(SIGUSR1, ft_binarytoarr);
		signal(SIGUSR2, ft_binarytoarr);
		pause();
	}
	return (0);
}
