/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_hexa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:16:27 by hthant            #+#    #+#             */
/*   Updated: 2024/06/24 19:27:17 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_put_hexa(unsigned long long n, const char formet);

static int	ft_hex_length(unsigned long long n)
{
	unsigned int	length;

	length = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 16;
		length++;
	}
	return (length);
}

static void	ft_puthex_recursive(unsigned long long n, char formet)
{
	if (n >= 16)
	{
		ft_puthex_recursive(n / 16, formet);
		ft_puthex_recursive(n % 16, formet);
	}
	else
	{
		if (n <= 9)
			ft_put_char(n + '0');
		else
		{
			if (formet == 'x')
				ft_put_char((n - 10 + 'a'));
			if (formet == 'X')
				ft_put_char((n - 10 + 'A'));
		}
	}
}

int	ft_put_hexa(unsigned long long n, const char formet)
{
	ft_puthex_recursive(n, formet);
	return (ft_hex_length(n));
}
