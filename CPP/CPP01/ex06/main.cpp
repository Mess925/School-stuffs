/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:19:20 by hthant            #+#    #+#             */
/*   Updated: 2025/06/02 17:21:57 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
    Harl harl;

    if (argc != 2) {
        std::cout << "Error! ";
        std::cout << "Usage: ./harlFilter <complaint_level>" << std::endl;
        return 1;
    }
    harl.complain(argv[1]);

    return 0;
}