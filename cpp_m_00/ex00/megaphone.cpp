/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 16:25:23 by hthant            #+#    #+#             */
/*   Updated: 2025/03/18 13:38:37 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        for (int i = 1; i < argc; i++) {
            for (int j = 0; argv[i][j] != '\0'; j++) {
                std::cout << (char) std::toupper(argv[i][j]);
            }
            if (i < argc - 1)
                std::cout << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}