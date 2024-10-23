/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messs <messs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 20:52:20 by messs             #+#    #+#             */
/*   Updated: 2024/10/23 20:53:22 by messs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char *ft_strndup(const char *s1, size_t n)
{
    char *dup;
    size_t len = 0;

    // Calculate the length of the string up to n characters
    while (s1[len] != '\0' && len < n)
    {
        len++;
    }

    // Allocate memory for the duplicate string (+1 for null terminator)
    dup = (char *)malloc(len + 1);
    if (!dup)
        return NULL; // Return NULL if memory allocation fails

    // Use ft_strncpy to copy the string
    ft_strncpy(dup, s1, len);
    dup[len] = '\0'; // Null-terminate the duplicated string

    return dup; // Return the duplicated string
}
