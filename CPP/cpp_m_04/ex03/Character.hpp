/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 20:42:28 by hthant            #+#    #+#             */
/*   Updated: 2025/10/05 17:37:01 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include <string>

class Character: public ICharacter {
	private:
		std::string _name;
		AMateria *_inventory[4];
	public:
		Character();
		Character(const Character& other);
		Character& operator=(const Character& other);
		~Character();

		Character(std::string name);
		std::string const& getName() const;
		void equip (AMateria* m);
		void unequip(int idx);
		void use(int idx, ICharacter& target);	
		int availableIdx();
};

# endif
