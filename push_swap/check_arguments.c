/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 16:53:17 by hthant            #+#    #+#             */
/*   Updated: 2024/11/03 17:56:27 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	ft_duplicate(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_numbers(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
	{
		i++;
		if (!(ft_isdigit(str[1])))
			return (0);
	}
	while (str[i])
	{
		if (!(ft_isdigit(str[i])))
			return (0);
		i++;
	}
	return (1);
}

int	array_count(int ac, char **av)
{
	int		i;
	int		j;
	int		count;
	char	**temp;

	i = 1;
	count = 0;
	while (i < ac)
	{
		j = 0;
		temp = ft_split(av[i], ' ');
		if (!temp)
			return (0);
		while (temp[j])
		{
			count++;
			j++;
		}
		ft_free(temp);
		temp = NULL;
		i++;
	}
	return (count);
}

char	**ft_args(int ac, char **av)
{
	char	**args;
	char	**temp;

	temp = NULL;
	if (!array_count(ac, av))
		return (NULL);
	args = (char **)malloc(sizeof(char *) * (array_count(ac, av) + 1));
	if (!args)
		return (NULL);
	args = args_help(ac, av, args, temp);
	return (args);
}

int	ft_check_args(int argc, char **argv)
{
	int		i;
	char	**args;

	if (argc < 2)
		return (0);
	args = ft_args(argc, argv);
	i = -1;
	if (!args)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	while (args[++i])
	{
		if (!ft_check_numbers(args[i]) || ft_duplicate(ft_atoi(args[i]), args,
				i) || ft_atoi(args[i]) < -2147483648
			|| ft_atoi(args[i]) > 2147483647)
		{
			ft_putstr_fd("Error\n", 2);
			ft_free(args);
			return (0);
		}
	}
	ft_free(args);
	return (1);
}
