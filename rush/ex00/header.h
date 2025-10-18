/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 16:18:42 by hthant            #+#    #+#             */
/*   Updated: 2025/10/18 16:19:25 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdio.h>

int check(char *str);
int ft_size(char *str);
void ft_putstr(char *str);
void ft_putchar(char c);
int getN(int size);
int solve(int[n][n] grid, int[n][n]clue, int i);

# endif
