/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unumber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 18:46:34 by hthant            #+#    #+#             */
/*   Updated: 2024/06/24 19:27:19 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					ft_put_unumber(unsigned int n);

static unsigned int	check_length(unsigned int number)
{
	int	length;

	length = 0;
	if (number < 0)
		length++;
	if (number == 0)
		return (1);
	while (number != 0)
	{
		number = number / 10;
		length++;
	}
	return (length);
}

static char	*ft_unitoa(unsigned int n)
{
	char			*str;
	int				len;
	unsigned int	num;

	len = check_length(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (!str)
		return (0);
	if (n == 0)
		str[0] = '0';
	str[len] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		num = -n;
	}
	else
		num = n;
	while (num != 0)
	{
		str[len - 1] = (num % 10) + '0';
		num = num / 10;
		len--;
	}
	return (str);
}

int	ft_put_unumber(unsigned int n)
{
	int		length;
	char	*str;

	str = ft_unitoa(n);
	length = ft_put_str(str);
	free(str);
	return (length);
}
