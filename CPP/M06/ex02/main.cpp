/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 21:43:37 by hthant            #+#    #+#             */
/*   Updated: 2025/09/04 22:02:23 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Base.hpp"

int main(){
	Base* base = generate();
	
	std::cout << "Identify(Base*): ";
	identify(base);

	std::cout << "Identify(Base&): ";
	identify(*base);

	delete base;
	return 0;
}
