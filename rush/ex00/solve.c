/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 21:47:14 by hthant            #+#    #+#             */
/*   Updated: 2025/10/19 10:54:01 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.h"

void printgrid(int grid[], int n){
	int row, col;

	row = 0;
	char a = ' ';
	while(row < n){
		col = 0;
		while(col < n){
			char c= grid[row][col] + '0';
			write( 1,&c ,1 );
			write( 1, &a, 1 );
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}

void initgrid(int grid[], int n, char *str) {
	int row = 0;
	while (row < n) {
		int col = 0;
		while (col < n) {
			int index = row * n + col;
			if (str[index] == '1')
				grid[row][col] = n;
			else
				grid[row][col] = 0;
			col++;
		}
		row++;
	}
}



/*int solve(int grid[n][n]){
	
}*/
