/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:25:23 by hthant            #+#    #+#             */
/*   Updated: 2025/03/23 14:45:39 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>
#include <string>

int main(int argc, char** argv)
{
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    else
    {
        std::string result;
        for (int i = 1; i < argc; i++)
        {
            std::string word = argv[i];
            for (size_t j = 0; j < word.length(); j++)
                word[j] = std::toupper(word[j]);
            result += word;
        }
        std::cout << result << std::endl;
    }
    return 0;
}
