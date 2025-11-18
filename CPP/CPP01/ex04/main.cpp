/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:05:55 by hthant            #+#    #+#             */
/*   Updated: 2025/06/02 16:03:23 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sed.hpp"
#include <iostream>
# include <stdio.h>

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cerr << "Usage: ./sed <filename> <s1> <s2>\n";
        return 1;
    }

    Sed sed(argv[1], argv[2], argv[3]);
    if (!sed.replace()) {
        return 1;
    }

    return 0;
}
