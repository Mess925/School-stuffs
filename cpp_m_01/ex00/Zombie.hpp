/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 03:00:25 by hthant            #+#    #+#             */
/*   Updated: 2025/05/30 03:33:36 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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


