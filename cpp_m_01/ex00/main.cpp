/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 03:21:44 by hthant            #+#    #+#             */
/*   Updated: 2025/05/30 03:35:27 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Zombie.hpp"

int main(void)
{
    Zombie *zombie = newZombie("heap zombie");
    zombie->announce();
    delete zombie;

    randomChump("stack zombie");
    return (0);
}