/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:56:09 by hthant            #+#    #+#             */
/*   Updated: 2025/06/22 11:59:06 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    const int size = 4;
    Animal* animals[size];

    std::cout << "--- Creating Animals ---\n";
    for (int i = 0; i < size; ++i) {
        if (i < size / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << "\n--- Testing Deep Copy Constructor ---\n";
    Dog originalDog;
    originalDog.getBrain()->setIdea(0, "Chase the cat");

    Dog copyDog = originalDog;  // Copy constructor
    copyDog.getBrain()->setIdea(0, "Sleep on the couch");

    std::cout << "Original Dog Idea: " << originalDog.getBrain()->getIdea(0) << "\n";
    std::cout << "Copied Dog Idea:   " << copyDog.getBrain()->getIdea(0) << "\n";

    std::cout << "\n--- Testing Deep Copy Assignment ---\n";
    Dog assignedDog;
    assignedDog = originalDog;  // Copy assignment operator
    assignedDog.getBrain()->setIdea(0, "Dig a hole");

    std::cout << "Original Dog Idea:  " << originalDog.getBrain()->getIdea(0) << "\n";
    std::cout << "Assigned Dog Idea:  " << assignedDog.getBrain()->getIdea(0) << "\n";

    std::cout << "\n--- Cleaning up ---\n";
    for (int i = 0; i < size; ++i)
        delete animals[i];
    
    std::cout << "\n--- AFTER DELETING ARRAY ANIMALS ---\n";

    return 0;
}
