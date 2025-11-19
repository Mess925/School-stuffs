/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 15:08:59 by hthant            #+#    #+#             */
/*   Updated: 2025/09/03 17:00:28 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Serialization.hpp"

Serializer::Serializer(){}

Serializer::Serializer(const Serializer& other){
	(void)other;
}

Serializer& Serializer::operator=(const Serializer& other){
	(void)other;
	return *this;
}

Serializer::~Serializer(){};

uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}
