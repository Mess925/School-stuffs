/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 19:55:28 by hthant            #+#    #+#             */
/*   Updated: 2025/06/10 14:37:55 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{
private:
    std::string ideas[100];
public:
    Brain();
    Brain(const Brain& other);
    Brain& operator=(const Brain& other);
    ~Brain();

    void setIdea(int index, const std::string& idea);
    std::string getIdea(int index) const;
};


# endif