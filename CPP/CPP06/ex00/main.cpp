/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 20:28:43 by hthant            #+#    #+#             */
/*   Updated: 2025/09/02 19:34:19 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./convert <literal>" << std::endl;
        return 1;
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}

/* Test Cases
 *
 * For char test Cases
 * normal char from a to z
 * unprintable char like delte tab
 * out of char range
 *
 * For int test Cases
 * + and - int
 * 0 
 * int limit
 * out of int limit
 * 
 * For float test Cases
 * normal float with one "."
 * float with multiple "."
 * out of float range
 *
 * For double test Cases
 * normal double
 * double with "."
 * double limitout of double limit
*/
