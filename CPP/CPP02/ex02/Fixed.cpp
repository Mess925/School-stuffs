/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:37:48 by hthant            #+#    #+#             */
/*   Updated: 2025/06/03 22:57:38 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Fixed.hpp"
#include <exception>
#include <stdexcept>

Fixed::Fixed() {
    this->_fixedvalue = 0;
}

Fixed::Fixed(const Fixed& other) {
    *this = other;
}

Fixed &Fixed::operator=(const Fixed& other) {
    if (this != &other)
        this->_fixedvalue = other._fixedvalue;
    return *this;
}

Fixed::~Fixed() {}

Fixed::Fixed(const int value){
    this->_fixedvalue = value << _fractionalBits;
}

Fixed::Fixed(const float value){
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

bool Fixed::operator>(const Fixed& other) const{
    return this->_fixedvalue > other._fixedvalue;
}

bool Fixed::operator<(const Fixed& other) const{
    return this->_fixedvalue < other._fixedvalue;
}

bool Fixed::operator>=(const Fixed& other) const{
    return this->_fixedvalue >= other._fixedvalue;
}

bool Fixed::operator<=(const Fixed& other) const{
    return this->_fixedvalue <= other._fixedvalue;
}

bool Fixed::operator==(const Fixed& other) const{
    return this->_fixedvalue == other._fixedvalue;
}

bool Fixed::operator!=(const Fixed& other) const{
    return this->_fixedvalue != other._fixedvalue;
}

Fixed Fixed::operator+(const Fixed& other)const{
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other)const{
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other)const{
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other)const{
    if(other._fixedvalue == 0)
    {
	    throw std::runtime_error("Fixed point division by zero");
    }
    return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++(){
    this->_fixedvalue++;
    return *this;
}

Fixed& Fixed::operator--(){
    this->_fixedvalue--;
    return *this;
}

Fixed Fixed::operator++(int){
    Fixed  temp = *this;
    this->_fixedvalue++;
    return temp;
}

Fixed Fixed::operator--(int){
    Fixed  temp = *this;
    this->_fixedvalue--;
    return temp;
}

Fixed& Fixed::min(Fixed& a , Fixed& b)
{
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a , const Fixed& b)
{
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed&a , Fixed&b)
{
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a , const Fixed& b)
{
    return (a > b) ? a : b;
}
