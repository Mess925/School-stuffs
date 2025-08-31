/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/16 14:23:57 by hthant            #+#    #+#             */
/*   Updated: 2024/05/20 16:52:29 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>

int	ft_tolower(int c);

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

// int main(void)
// {
// 	int i = tolower(99);
// 	int j = tolower(65);
// 	int k = tolower(55);
// 	printf("%c\n%c\n%c\n",i,j,k);
// }
