/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:09:09 by hthant            #+#    #+#             */
/*   Updated: 2025/09/03 16:51:27 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

# include <iostream>
# include <string>
# include <stdint.h>

struct Data{
	int i;
};

class Serializer {
	private:
		Serializer();
		Serializer(const Serializer& other);
		Serializer& operator= (const Serializer& other);
		~Serializer();
	public:
		static uintptr_t serialize(Data *ptr);
		static Data* deserialize(uintptr_t raw);
};

# endif
