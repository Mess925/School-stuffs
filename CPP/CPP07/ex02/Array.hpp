/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 21:26:27 by hthant            #+#    #+#             */
/*   Updated: 2025/11/15 21:30:35 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <cstddef>
#include <iostream>
# include <exception>
# include <stdlib.h>

template <typename T>
class Array
{
private:
	T *_array;
	unsigned int _n;

public:
	Array();
	Array(unsigned int);
	Array(const Array &other);
	Array &operator=(const Array &other);
	~Array();

	T &operator[](unsigned int n);
	const T &operator[](unsigned int n) const;
	unsigned int size() const;
};

#include "Array.tpp"

#endif
