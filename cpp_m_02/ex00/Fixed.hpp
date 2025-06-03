/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:36:14 by hthant            #+#    #+#             */
/*   Updated: 2025/06/03 19:34:30 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <string>

class Fixed
{
private:
    int _value;
    static const int _ftactionalbits = 8;
public:
    Fixed();
    Fixed(const Fixed& other);
    Fixed& operator = (const Fixed& other);
    ~Fixed();
    int getRawBits( void ) const;
    void setRawBits( int const raw );
};

# endif