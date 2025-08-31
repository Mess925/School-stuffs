/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 13:56:00 by hthant            #+#    #+#             */
/*   Updated: 2024/05/20 16:52:02 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

int	ft_toupper(int c);

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

// int main(void)
// {
// 	int i = toupper(99);
// 	int j = toupper(65);
// 	int k = toupper(55);
// 	printf("%c\n%c\n%c\n",i,j,k);
// }
