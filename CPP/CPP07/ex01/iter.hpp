/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 22:42:41 by hthant            #+#    #+#             */
/*   Updated: 2025/11/15 18:43:21 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ITER_HPP
# define ITER_HPP

# include <iostream>
# include <string>

template <typename T, typename F>
void	iter(T* array, size_t length, F func){
	size_t i = 0;
	while(i < length){
		func(array[i]);
		i++;
	}		
}

# endif

template <typename Type>
void print(const Type& value) {
    std::cout << value << " ";
}

template <typename Type>
void increment(Type& value) {
    ++value;
}

void change(char& c) {
    if (std::islower(c))
        c = std::toupper(c);
    else
        c = std::tolower(c);
}

