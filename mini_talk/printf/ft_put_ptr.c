/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:38:35 by hthant            #+#    #+#             */
/*   Updated: 2024/06/24 19:27:18 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_ptr(void *ptr);

int	ft_put_ptr(void *ptr)
{
	unsigned long long	p;
	unsigned int		print_char;

	if (!ptr)
		return (write(1, "(nil)", 5));
	p = (unsigned long long)ptr;
	print_char = 0;
	if (p == 0)
		print_char += ft_put_str("(nil)");
	print_char += ft_put_str("0x");
	print_char += ft_put_hexa(p, 'x');
	return (print_char);
}

// int	main(void)
// {
// 	int		i;
// 	int *	ptr;

// 	i = 10;

// 	ft_put_ptr(NULL);
// 	printf("\nprintf: %p\n",NULL);
// 	printf("%s","hi");
// }
