/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 14:31:48 by hthant            #+#    #+#             */
/*   Updated: 2024/10/03 02:51:23 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr);

int	ft_atoi(const char *nptr)
{
	int		i;
	int		j;
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

// int    main(int argc, char *argv[])
// {
//     if (argc == 2)
//     {
//         printf("%d\n", ft_atoi(argv[1]));
//         printf("%d\n", atoi(argv[1]));
//     }
//     char s[] = "       123";
//     printf("%d\n", ft_atoi(s));
//     printf("%d", atoi(s));
// }
