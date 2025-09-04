/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 21:55:32 by hthant            #+#    #+#             */
/*   Updated: 2025/09/04 22:02:05 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Base.hpp"

Base::~Base(){}

Base*	generate(){
	std::srand(std::time(NULL));
	int random = rand() % 3;
	switch (random) {
		case 0:
			return new A();
		case 1:
			return new B();
		default:
			return new C();
	}
}

void	identify(Base* p){
	if(dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout<<"B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "c" << std::endl;
	else
		std::cout << "ERROR" << std::endl;
}

void	identify(Base& p){
	try{
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	}catch (...){}
	try{
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	}catch (...){}
	try{
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	}catch (...){}
}

