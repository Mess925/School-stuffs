/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 23:17:08 by hthant            #+#    #+#             */
/*   Updated: 2025/09/11 17:41:54 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <exception>

template <typename T>
void	easyfind(T& numbs, int n){
	typename T :: iterator it = std::find(numbs.begin(), numbs.end(), n);
	if(it != numbs.end()){
		std::cout << "Found the element "<< n <<std::endl;
	}
	else
		throw std::exception();

}

# endif
