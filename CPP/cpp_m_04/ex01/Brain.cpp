/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 14:38:08 by hthant            #+#    #+#             */
/*   Updated: 2025/06/10 15:05:45 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Brain.hpp"

Brain::Brain(){
    std::cout<<"Default Brain Constructor is creatd."<<std::endl;
}

Brain::Brain(const Brain& other){
    for (int i = 0; i < 100; ++i){
        this->ideas[i] = other.ideas[i];
    }
    std::cout<< "Copy Brain Constructor is created." <<std::endl;
}

Brain& Brain::operator=(const Brain& other){
    if(this != &other)
    {
        for (int i = 0; i < 100; ++i)
            this->ideas[i]= other.ideas[i];
    }
    std::cout << "Assignment Copy Constructor Brain is created." <<std::endl;
    return *this;
}

Brain::~Brain(){
    std::cout<<"Brain Destructor called."<<std::endl;
}

void Brain::setIdea(int index, const std::string& idea){
    if(index >= 0 && index <=99)
        ideas[index] = idea;
}

std::string Brain::getIdea(int index) const {
    if(index>=0 && index <= 99)
        return (ideas[index]);
    return ("");
}