/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Amateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 19:12:50 by hthant            #+#    #+#             */
/*   Updated: 2025/10/01 19:57:04 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>

class AMateria {
	protected:
		std::string _type;
	public:
		AMateria();
		AMateria(const AMateria& other);
		AMateria& operator=(const AMateria& other);
		virtual ~AMateria();

		AMateria(std::string const& type);
		std::string const & getType() const;

		virtual AMateria* clone() const =0;
		// virtual void use(ICharacter& target);
};

# endif
