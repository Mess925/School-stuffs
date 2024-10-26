/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_helper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: messs <messs@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 01:29:25 by messs             #+#    #+#             */
/*   Updated: 2024/10/27 02:23:37 by messs            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int ft_count_char(const char *str, char c)
{
    int count;

    count = 0;
    while (*str)
    {
        if (*str == c)
            count++;
        str++;
    }
    return count;
}

void ft_count(int player_count, int exit_count ,int sheep)
{
    if (player_count != 1)
    {
        ft_putstr_fd("Error: There must be exactly 1 player in the map\n",1);
        return;
    }
    if (sheep <= 0)
    {
        ft_putstr_fd("Error: There must be at least 1 collectible in the map\n",1);
        return;
    }
    if (exit_count != 1)
    {
        ft_putstr_fd("Error: There must be exactly 1 exit in the map\n",1);
        return;
    }
}