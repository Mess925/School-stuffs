/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 16:56:09 by hthant            #+#    #+#             */
/*   Updated: 2025/06/11 22:26:58 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"


int main() {
    std::cout << "=== Basic Instantiation ===" << std::endl;
    Cat cat;
    Dog dog;

    std::cout << "\n=== Polymorphism Test ===" << std::endl;
    Animal* animals[2];
    animals[0] = new Cat();
    animals[1] = new Dog();

    for (int i = 0; i < 2; ++i) {
        std::cout << animals[i]->getType() << " makes sound: ";
        animals[i]->makeSound();
    }

    std::cout << "\n=== Destructor Cleanup ===" << std::endl;
    for (int i = 0; i < 2; ++i) {
        delete animals[i];
    }

    std::cout << "\n=== Copy Constructor Test ===" << std::endl;
    Cat originalCat;
    Cat copiedCat(originalCat);

    Dog originalDog;
    Dog copiedDog(originalDog);

    std::cout << "\n=== Assignment Operator Test ===" << std::endl;
    Cat assignedCat;
    assignedCat = cat;

    Dog assignedDog;
    assignedDog = dog;

    std::cout << "\n=== Abstract Base Class Test (Compilation should fail if uncommented) ===" << std::endl;
    // Animal testAnimal; // ❌ Uncommenting this line should cause a compiler error (abstract class)

    return 0;
}