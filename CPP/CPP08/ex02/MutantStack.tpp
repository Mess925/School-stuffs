/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:57:49 by hthant            #+#    #+#             */
/*   Updated: 2025/09/11 17:58:11 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MUSTANTSTACK_TPP
# define MUSTANTSTACK_TPP

# include "MutantStack.hpp"

template<typename T, typename Container>
MutantStack<T, Container>::MutantStack() : std::stack<T, Container>()
{
}

template <typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack& other) : std::stack<T,Container>(other){
}

template<typename T, typename Container>
MutantStack<T, Container>& MutantStack<T, Container>::operator=(const MutantStack& other){
	if(this != other)
		std::stack<T,Container>::operator=(other);
	return *this;
}

template <typename T, typename Container>
MutantStack<T, Container>::~MutantStack (){}







template<typename T, typename Container>
typename Container::iterator MutantStack<T, Container>::begin()
{
    return this->c.begin();
}

template<typename T, typename Container>
typename Container::const_iterator MutantStack<T, Container>::begin() const
{
    return this->c.begin();
}

template<typename T, typename Container>
typename Container::iterator MutantStack<T, Container>::end()
{
    return this->c.end();
}

template<typename T, typename Container>
typename Container::const_iterator MutantStack<T, Container>::end() const
{
    return this->c.end();
}

#endif

