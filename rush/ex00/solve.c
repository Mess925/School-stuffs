/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 21:47:14 by hthant            #+#    #+#             */
/*   Updated: 2025/10/19 14:07:18 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void printgrid(int n, int grid[n][n])
{
    int row, col;

    row = 0;
    char a = ' ';
    while (row < n)
    {
        col = 0;
        while (col < n)
        {
            char c = grid[row][col] + '0';
            write(1, &c, 1);
            write(1, &a, 1);
            col++;
        }
        write(1, "\n", 1);
        row++;
    }
}

void initgrid(int n, int grid[n][n], char *str)
{
	int top[n], bottom[n], left[n], right[n];
	int i = 0, val;
	char *ptr = str;
	
	for (int j = 0; j < n; j++)
	{
        	while (*ptr == ' ')
			ptr++;
		top[j] = *ptr - '0';
		ptr++;
	}
	for (int j = 0; j < n; j++)
	{
        	while (*ptr == ' ')
			ptr++;
		bottom[j] = *ptr - '0';
		ptr++;
	}
	for (int j = 0; j < n; j++)
	{
		while (*ptr == ' ')
			ptr++;
		left[j] = *ptr - '0';
		ptr++;
	}
	for (int j = 0; j < n; j++)
	{
		while (*ptr == ' ')
			ptr++;
		right[j] = *ptr - '0';
		ptr++;
	}
	
	for (int row = 0; row < n; row++)
        	for (int col = 0; col < n; col++)
			grid[row][col] = 0;
	
	for (i = 0; i < n; i++)
	{
        	if (top[i] == n)
		{
			for (int row = 0; row < n; row++)
				grid[row][i] = row + 1;
		}
		else if (top[i] == 1)
		{
			grid[0][i] = n;
		}
		
		if (bottom[i] == n)
		{
			for (int row = 0; row < n; row++)
                		grid[n - 1 - row][i] = row + 1;
        	}
        	else if (bottom[i] == 1)
        	{
            		grid[n - 1][i] = n;
        	}

        	if (left[i] == n)
        	{
           		for (int col = 0; col < n; col++)
                		grid[i][col] = col + 1;
        	}
        	else if (left[i] == 1)
        	{
            		grid[i][0] = n;
        	}
		
        	if (right[i] == n)
        	{
            		for (int col = 0; col < n; col++)
                		grid[i][n - 1 - col] = col + 1;
        	}
        	else if (right[i] == 1)
        	{
            		grid[i][n - 1] = n;
        	}
	}
}


void solve(int n, int grid[n][n], char *str){
	int i =0;
	while( i < n){
		int j = 0;
		while(j < n){
			if(grid[i][j] == 0)
					//magic happen here;
			j++;
		}
		i++;
	}
	return;
}
