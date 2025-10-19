/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 20:31:55 by hthant            #+#    #+#             */
/*   Updated: 2025/10/18 22:45:36 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.h"

void doNth(){
	return;
}

int check(char *str){
	int i = 0;
	int size = ft_size(str);
	if(size != 31 && size != 39 && size != 47 && size != 55 && size != 63 && size != 71){
		ft_putstr("ERROR");
		return 0;
	}
	while(str[i] != 0){
		if(str[i] >= 48 && str[i] <= 57)
			doNth();
		else{
			if(str[i] != ' ' ){
				ft_putstr("ERROR");
				return 0;
			}
			else{
				if(!(str[i + 1] >= 48 && str[i + 1] <= 57)){
					ft_putstr("ERRORA");
					return 0;
				}
			}
		}
		i++;
	}	
	return 1;
}

int ft_size(char *str){
	int i = 0;
	while(str[i] != '\0')
		i++;
	return i;
}

void ft_putstr(char* str){
	size_t i = ft_size(str);
	write(1, str, i);
	write(1, "\n", 1);
}

void ft_putchar(char c){
	write(1, &c, 1);
	write(1, "\n", 1);
}

int getN(int size){	
	int n = 0;
	if(size == 16)
		n = 4;
	else if (size ==  20)
		n = 5;
	else if(size == 24)
		n = 6;
	else if(size == 28)
		n = 7;
	else if(size == 32)
		n = 8;
	else if (size == 36)
		n = 9;
	else
		n = -1;
	return n;
}
