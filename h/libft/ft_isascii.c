/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:49:43 by hthant            #+#    #+#             */
/*   Updated: 2024/05/20 16:52:05 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_isascii(int c);

int	ft_isascii(int c)
{
	if (c >= 0 && c < 128)
	{
		return (1);
	}
	return (0);
}
/*
int main(void)
{
	int i = isascii(300);
	int j = isascii(23);
	printf("%d%d",i,j);
}
*/
