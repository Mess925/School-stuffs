/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 04:01:31 by hthant            #+#    #+#             */
/*   Updated: 2025/05/30 04:27:32 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

int main()
{
    int n = 5;
    std::string name = "heap zombie";
    Zombie *horde = zombieHorde(n, name);
    if(horde)
    {
        for(int i = 0; i < n; i++)
            horde[i].announce();
        delete[] horde;
    }
    return (0);
}