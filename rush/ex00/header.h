/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 16:18:42 by hthant            #+#    #+#             */
/*   Updated: 2025/10/19 10:53:19 by hthant           ###   ########.fr       */
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
void solve(int n, int grid[n][n], char *str);
void initgrid(int n, int grid[n][n], char *str);
void printgrid(int n,int grid[n][n]);

# endif
