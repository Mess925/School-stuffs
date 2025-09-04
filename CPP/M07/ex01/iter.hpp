/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 22:42:41 by hthant            #+#    #+#             */
/*   Updated: 2025/09/04 23:09:42 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T, typename F>
void	iter(T* array, size_t length, F func){
	size_t i = 0;
	while(i++ < length)
		func(array[i]);
}

# endif
