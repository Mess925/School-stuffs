/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 17:03:17 by hthant            #+#    #+#             */
/*   Updated: 2024/06/24 19:27:19 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_str(char *s);

int	ft_put_str(char *s)
{
	int	i;

	i = 0;
	if (!s)
		s = "(null)";
	while (s[i])
		ft_put_char(s[i++]);
	return (i);
}

// int	main(void)
// {
// 	printf("NULL is %d",ft_put_str(NULL));
// }
