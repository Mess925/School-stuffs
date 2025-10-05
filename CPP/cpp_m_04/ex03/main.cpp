/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 20:37:05 by hthant            #+#    #+#             */
/*   Updated: 2025/10/05 17:24:30 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include "AMateria.hpp"
# include "IMateriaSource.hpp"
# include "MateriaSource.hpp"
# include "Ice.hpp"
# include "Character.hpp"
# include "Cure.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	ICharacter* me = new Character("me");
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	ICharacter* bob = new Character("bob");
	me->use(0, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
return 0;
}
