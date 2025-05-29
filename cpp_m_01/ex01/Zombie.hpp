/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 03:00:25 by hthant            #+#    #+#             */
/*   Updated: 2025/05/30 04:18:29 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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



