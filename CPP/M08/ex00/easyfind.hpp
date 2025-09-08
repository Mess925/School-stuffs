/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 23:17:08 by hthant            #+#    #+#             */
/*   Updated: 2025/09/09 00:01:09 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <exception>
# include <list>

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
