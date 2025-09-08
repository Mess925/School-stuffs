/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 23:28:10 by hthant            #+#    #+#             */
/*   Updated: 2025/09/06 09:41:43 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <exception>
# include <cstdlib>

template <typename T>
class Array {
	private:
		T* _array;
		unsigned int _size;
	public:
		Array();
		Array(const Array& other);
		Array& operator=(const Array& other);
		~Array();
		Array(unsigned int n);

		T& operator[](unsigned int index);
		const T& operator[](unsigned int index) const;
		unsigned int getSize() const;
};

# endif
