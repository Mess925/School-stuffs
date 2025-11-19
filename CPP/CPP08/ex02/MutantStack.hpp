/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 12:12:06 by hthant            #+#    #+#             */
/*   Updated: 2025/09/11 17:57:55 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>
# include <deque>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
	public:
		MutantStack();
		MutantStack(const MutantStack& other);
		MutantStack& operator=(const MutantStack& other);
		~MutantStack();


		typedef typename Container::iterator iterator;
		typedef typename Container::const_iterator const_iterator;

		iterator	begin();
		iterator	end();
		const_iterator	begin() const;	
		const_iterator	end() const;
};

# include "MutantStack.tpp"

# endif
