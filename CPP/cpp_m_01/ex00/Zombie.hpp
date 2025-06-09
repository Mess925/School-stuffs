/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 03:00:25 by hthant            #+#    #+#             */
/*   Updated: 2025/05/30 14:52:31 by hthant           ###   ########.fr       */
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
    Zombie(std::string name)
    {
        _Name = name;
    }
    ~Zombie()
    {
        std::cout << _Name << " is destroyed." << std::endl;
    }
    void announce(void);
};
Zombie* newZombie (std::string name);
void randomChump(std::string name);

# endif

