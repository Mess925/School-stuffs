/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 20:43:44 by hthant            #+#    #+#             */
/*   Updated: 2025/10/05 17:22:52 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

#include "AMateria.hpp"
class AMateria;
class ICharacter{
	public:
		virtual ~ICharacter(){}
		virtual std::string const & getName() const = 0;
		virtual void equip(AMateria* m) = 0;
		virtual void unequip(int idx) = 0;
		virtual void use(int idx, ICharacter& taraget) = 0;
};


# endif
