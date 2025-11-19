/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 21:26:31 by hthant            #+#    #+#             */
/*   Updated: 2025/11/15 21:26:35 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Array.hpp>

template <typename T>
Array<T>::Array() : _array(NULL), _n(0) {}

template <typename T>
Array<T>::Array(unsigned int n)
{
    _n = n;
    _array = new T[_n];
}

template <typename T>
Array<T>::Array(const Array &other)
{
	_n = other._n;
	_array = new T[_n];
	for(unsigned int i = 0; i < _n ; i++){
		_array[i] = other._array[i];
	}
}

template <typename T>
Array<T>&Array<T>::operator=(const Array &other){
	if(this != &other){
		delete[] _array;
	_n = other._n;
	_array = new T[_n];
	for(unsigned int i = 0; i < _n ; i++){
		_array[i] = other._array[i];
	}}
	return *this;
}

template <typename T>
Array<T>::~Array(){
	delete[] _array;
}

template <typename T>
T& Array<T>::operator[](unsigned int n){
	if(n >= _n)
		throw std::out_of_range("OUT OF RANGE");
	return _array[n];
}

template <typename T>
const T& Array<T>::operator[](unsigned int n) const {
	if(n >= _n)
		throw std::out_of_range("OUT OF RANGE");
	return _array[n];
}

template <typename T>
unsigned int Array<T>::size() const{
	return _n;
}
