/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:31:48 by hthant            #+#    #+#             */
/*   Updated: 2024/10/20 22:07:35 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *nptr);

long	ft_atoi(const char *nptr)
{
	long	i;
	long	j;
	char	sign;

	i = 0;
	j = 0;
	sign = '+';
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = '-';
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		j = (j * 10 + nptr[i]) - '0';
		i++;
	}
	if (sign == '-')
	{
		j = j * -1;
	}
	return (j);
}

// long    mainlong argc, char *argv[])
// {
//     if (argc == 2)
//     {
//         plongf("%d\n", ft_atoi(argv[1]));
//         plongf("%d\n", atoi(argv[1]));
//     }
//     char s[] = "       123";
//     plongf("%d\n", ft_atoi(s));
//     plongf("%d", atoi(s));
// }
