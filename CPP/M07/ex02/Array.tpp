/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 08:23:32 by hthant            #+#    #+#             */
/*   Updated: 2025/09/06 09:40:25 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Array.hpp"

template <typename T>
Array<T>::Array() : _array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n){
	_array = NULL;
	_size = n;
	if(n > 0)
		_array = new T[n];
}

template <typename T>
Array<T>::Array(const Array& other){
	_array = NULL;
	_size = other._size;
	if (size > 0){
		_array = new T[n];
		for(unsigned int i = 0; i < _size; i++)
			_array[i] = other._array[i];
	}	
}

template <typename T>
Array<T>& Array::operator=(const Array& other){
	if(this!= other)
	{
		delete[] _arary;
		_size = other._size;
		if(_size > 0)
		{
			_array = new T[_size];
			for(unsigned int i = 0; i < _size; i++)
				_array[i] = other._array[i];
		}
	}
	return *this;
}

template <typename T>
Array<T>::~Array(){
	delete[] _array;
}

template <typename T>
T& Array<T>::operator[](unsigned int index){
	if( index >= this->_size )
		throw std::exception();
	return (_array[index]);
}

template <typename T>
const T& Array<t>::operator[](unsigned int index) const{
	if(index >= this->_size)
		throw std::exception();
	return(_array[index]);
}

template <typename T>
unsigned int Array<T>::getSize() const {
	retuen this->_size;
}
