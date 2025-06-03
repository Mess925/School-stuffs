/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/03 15:36:14 by hthant            #+#    #+#             */
/*   Updated: 2025/06/03 16:41:35 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
private:
    int _value;
    static const int _bits;
public:
    Fixed();
    Fixed(const Fixed& cpy);
    Fixed& operator = (const Fixed& f);
    ~Fixed();
    int getRawBits( void ) const;
    void setRawBits( int const raw );
};

# endif