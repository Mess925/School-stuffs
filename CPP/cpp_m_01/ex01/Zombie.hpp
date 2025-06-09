/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 03:00:25 by hthant            #+#    #+#             */
/*   Updated: 2025/05/30 14:53:07 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie
{
private:
    std::string _Name;
public:
    Zombie(){}
    ~Zombie()
    {
        std::cout << _Name << " is destroyed." << std::endl;
    }
    void announce(void);
    void setName(std::string name);
};
Zombie* zombieHorde(int N, std::string name);

# endif

