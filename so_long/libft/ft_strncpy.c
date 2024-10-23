/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messs <messs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:49:36 by messs             #+#    #+#             */
/*   Updated: 2024/10/23 20:53:23 by messs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strncpy(char *dest, const char *src, size_t n)
{
    size_t i = 0;

    // Copy up to n characters from src to dest
    while (i < n && src[i] != '\0')
    {
        dest[i] = src[i];
        i++;
    }

    // If the source string is shorter than n, pad the remaining characters in dest with '\0'
    while (i < n)
    {
        dest[i] = '\0';
        i++;
    }

    return dest; // Return the destination string
}
