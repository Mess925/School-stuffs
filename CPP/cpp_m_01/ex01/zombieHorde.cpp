/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 04:01:28 by hthant            #+#    #+#             */
/*   Updated: 2025/05/30 04:21:30 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
    int n  = N;
    if (n <= 0)
        return NULL;
    Zombie *horde = new Zombie[n];
    for(int i = 0; i < n; i++)
        horde[i].setName(name);
    return (horde);
}