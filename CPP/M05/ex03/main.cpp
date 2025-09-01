/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 12:06:35 by hthant            #+#    #+#             */
/*   Updated: 2025/09/01 12:44:36 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Intern.hpp"

int main(){
	try {
		Bureaucrat b("b", 1);
		std::string	forms[4] = {"robotomy request", "shrubbery creation", "presidential pardon", "random form"};
		AForm*	validForms[4] = {NULL, NULL, NULL, NULL};
		Intern	i;
		for (int j = 0; j < 3; j++) {
			validForms[j] = i.makeForm(forms[j], "random target");
			if (validForms[j])
				validForms[j]->execute(b);
		}
	} catch (const std::exception& e) {
		std::cout << e.what() << " not ok" << std::endl;
	}
}
