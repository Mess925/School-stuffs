/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:01:25 by hthant            #+#    #+#             */
/*   Updated: 2024/05/30 17:38:10 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c);

int	ft_isalnum(int c)
{
	if ((c >= 48 && c <= 57) || (c >= 65 && c <= 90) || (c >= 97 && c <= 122))
		return (1);
	return (0);
}
/*
int	main(void)
{
	int	i;
	int	j;
	int	k;
	int	l;
	i = isalnum(48);
	j = isalnum(65);
	k = isalnum(97);
	l = isalnum(20);
	printf("%d%d%d%d",i,j,k,l);
}*/
