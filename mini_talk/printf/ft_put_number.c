/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 18:45:47 by hthant            #+#    #+#             */
/*   Updated: 2024/06/24 19:27:16 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_number(int n);

int	ft_put_number(int n)
{
	int		length;
	char	*str;

	length = 0;
	str = ft_itoa(n);
	length = ft_put_str(str);
	free(str);
	return (length);
}
