/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 13:30:38 by hthant            #+#    #+#             */
/*   Updated: 2024/05/30 13:59:32 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_itoa(int n);

static	size_t	check_length(int number)
{
	size_t	length;

	length = 0;
	if (number < 0)
		length += 1;
	if (number == 0)
		return (1);
	while (number != 0)
	{
		number = number / 10;
		length++;
	}
	return (length);
}

char	*ft_itoa(int n)
{
	char			*str;
	unsigned int	length;
	unsigned int	number;

	length = check_length(n);
	str = (char *)malloc(sizeof(char) * length + 1);
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		number = -n;
	}
	else
		number = n;
	if (number == 0)
		str[0] = '0';
	str[length] = '\0';
	while (number != 0)
	{
		str[length - 1] = number % 10 + '0';
		number = number / 10;
		length --;
	}
	return (str);
}

// int main(void)
// {
//     char *i = ft_itoa(-2147483648);
//     printf("%s\n",i);
// }
