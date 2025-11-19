/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:08:45 by hthant            #+#    #+#             */
/*   Updated: 2025/09/03 16:59:06 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"
#include <iostream>

int main() {
    Data* original = new Data;
    original->i = 2;

    std::cout << "Original Data pointer: " << original << std::endl;
    std::cout << "Original Data value: " << original->i << std::endl;

    uintptr_t serialized = Serializer::serialize(original);
    std::cout << "Serialized value (uintptr_t): " << serialized << std::endl;

    Data* deserialized = Serializer::deserialize(serialized);
    std::cout << "Deserialized Data pointer: " << deserialized << std::endl;
    std::cout << "Deserialized Data value: " << deserialized->i << std::endl;

    delete original;
    return 0;
}
