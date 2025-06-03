/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:37:48 by hthant            #+#    #+#             */
/*   Updated: 2025/06/03 21:13:48 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"

Fixed::Fixed() {
    std::cout << "Default constructor called" << std::endl;
    this->_fixedvalue = 0;
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called" << std::endl;
    *this = other;
}

Fixed &Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->_fixedvalue = other._fixedvalue;
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const int value){
    std::cout<<"Int constructor called"<< std::endl;
    this->_fixedvalue = value << _fractionalBits;
}

Fixed::Fixed(const float value){
    std::cout<<"Flaot constructor called"<<std::endl;
    this->_fixedvalue = roundf(value * (1 << _fractionalBits));
}

float Fixed::toFloat() const{
    return (float)this->_fixedvalue / (1 << _fractionalBits);
}

int Fixed::toInt() const{
    return this->_fixedvalue >> _fractionalBits;
}

std::ostream& operator<<(std::ostream& os, const Fixed& fixed) {
    os << fixed.toFloat();
    return os;
}