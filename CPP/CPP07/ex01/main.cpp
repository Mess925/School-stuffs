/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 22:49:13 by hthant            #+#    #+#             */
/*   Updated: 2025/11/15 18:46:39 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
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
        std::cout << "== Const Array Test ==" << std::endl;
        const int constNums[] = {42, 1337, 9001};

        std::cout << "Printing const array: ";
        iter(constNums, 3, print<int>); // OK
        std::cout << "\n";

        // iter(constNums, 3, increment<int>); // should NOT compile — good test!!
        std::cout << "\n";
    }
    {
        std::cout << "== Double Test ==" << std::endl;

        double arr[] = {1.1, 2.2, 3.3};

        std::cout << "Before increment: ";
        iter(arr, 3, print<double>);
        std::cout << "\n";

        iter(arr, 3, increment<double>);

        std::cout << "After increment: ";
        iter(arr, 3, print<double>);
        std::cout << "\n\n";
    }
    {
        std::cout << "== Mixed Char Test ==" << std::endl;

        char mix[] = {'A', 'b', '0', '!', 'z'};

        std::cout << "Before: ";
        iter(mix, 5, print<char>);
        std::cout << "\n";

        iter(mix, 5, change);

        std::cout << "After: ";
        iter(mix, 5, print<char>);
        std::cout << "\n\n";
    }
    {
        std::cout << "== Empty Array Test ==" << std::endl;
        int empty[1];               // dummy allocation
        iter(empty, 0, print<int>); // Should print nothing, no crash
        std::cout << "\n\n";
    }
    {
        std::cout << "== Large Array Test ==" << std::endl;

        int big[20];
        for (int i = 0; i < 20; ++i)
            big[i] = i * 2;

        iter(big, 20, print<int>);
        std::cout << "\n\n";
    }
    {
        std::cout << "== Function Pointer Test ==" << std::endl;

        int a[] = {10, 20, 30};

        void (*fptr)(const int &) = print<int>;
        iter(a, 3, fptr);
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

        iter(chars, 5, change);

        std::cout << "After: ";
        iter(chars, 5, print<char>);
        std::cout << "\n";
    }

    return 0;
}
