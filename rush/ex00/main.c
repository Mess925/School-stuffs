/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 16:09:09 by hthant            #+#    #+#             */
/*   Updated: 2025/10/18 16:17:44 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.h"


int main(int argc, char**argv){
	if(argc != 2){
		ft_putstr("ERROR");
		return -1;
	}
	if(!check(argv[1]))
		return -1;
	int n = getN((ft_size(argv[1]) + 1)/2);
	int grid[n][n] = {{0}};
	int clue[n][n];
	solve(grid, clue, 0);

	return 0;
}

