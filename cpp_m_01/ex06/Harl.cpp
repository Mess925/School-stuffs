/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 17:19:28 by hthant            #+#    #+#             */
/*   Updated: 2025/06/02 17:22:14 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug() {
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my";
    std::cout << "7XL-double-cheese-triple-pickle-";
    std::cout << "specialketchup burger. I really do!" << std::endl;
};

void Harl::info() {
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more";
    std::cout << " money. You didn't put enough bacon in my burger!";
    std::cout << " If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl::warning() {
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for ";
    std::cout << "free. I've been coming for years, whereas you";
    std::cout << " started working here just last month." << std::endl;
}

void Harl::error() {
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level)
{
    int complaintLevel = -1;

    if (level == "DEBUG") complaintLevel = 0;
    else if (level == "INFO") complaintLevel = 1;
    else if (level == "WARNING") complaintLevel = 2;
    else if (level == "ERROR") complaintLevel = 3;

    switch (complaintLevel) {
        case 0:
            debug();
        case 1:
            info();
        case 2:
            warning();
        case 3:
            error();
            break;
        default:
            std::cout << "[ ELSE ]" << std::endl;
            std::cout << "Invalid complaint level!" << std::endl;
    }
}