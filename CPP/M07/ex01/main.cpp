/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 22:49:13 by hthant            #+#    #+#             */
/*   Updated: 2025/09/04 23:21:08 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

// Print function
template <typename Type>
void print(const Type& value) {
    std::cout << value << " ";
}

// Increment function
template <typename Type>
void increment(Type& value) {
    ++value;
}

// toUpp toLow function
template <typename Type>
void change(char& c) {
    if (std::islower(c))
        c = std::toupper(c);
    else
        c = std::tolower(c);
}

int main() {
    // Test 1: Integer array (modifying + printing)
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

    // Test 2: String array (printing only)
    {
        std::cout << "== String Test ==" << std::endl;
        std::string words[] = {"apple", "banana", "cherry"};

        iter(words, 2, print<std::string>);
        std::cout << "\n\n";
    }

    // Test 3: Char array (modifying + printing)
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
