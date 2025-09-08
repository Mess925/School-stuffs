/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 22:49:13 by hthant            #+#    #+#             */
/*   Updated: 2025/09/08 15:07:22 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main() {
    {
        std::cout << "== Integer Test ==" << std::endl;
        int numbers[] = {1, 2, 3, 4, 5};

        std::cout << "Before increment: ";
        iter(numbers, 3, print<int>);
        std::cout << "\n";

        iter(numbers, 3, increment<int>);

        std::cout << "After increment: ";
        iter(numbers, 3, print<int>);
        std::cout << "\n\n";
    }

    {
        std::cout << "== String Test ==" << std::endl;
        std::string words[] = {"apple", "banana", "cherry"};

        iter(words, 2, print<std::string>);
        std::cout << "\n\n";
    }

    {
        std::cout << "== Char Test ==" << std::endl;
        char chars[] = {'h', 'E', 'L', 'l', 'o'};

        std::cout << "Before: ";
        iter(chars, 5, print<char>);
        std::cout << "\n";

        iter(chars, 5, change<char>);

        std::cout << "After: ";
        iter(chars, 5, print<char>);
        std::cout << "\n";
    }

    return 0;
}
