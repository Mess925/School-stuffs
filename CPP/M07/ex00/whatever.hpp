/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 22:16:59 by hthant            #+#    #+#             */
/*   Updated: 2025/09/08 14:24:43 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>

template <typename T>
void	swap(T type1, T type2){

	T temp;
	temp = type1;
	type1 = type2;
	type2 = temp;
}

template <typename T>
T min(T type1, T type2){
	if(type1 < type2)
		return type1;
	return type2;
}

template <typename T>
T max(T type1, T type2){
	if(type1 > type2)
		return type1;
	return type2;
}


# endif
