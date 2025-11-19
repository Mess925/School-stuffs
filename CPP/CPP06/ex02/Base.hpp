/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 19:53:13 by hthant            #+#    #+#             */
/*   Updated: 2025/09/04 22:02:37 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BASE_HPP
# define BASE_HPP

# include <iostream>
# include <ctime>
# include <cstdlib>

class Base {
	public:
		virtual ~Base();
};

class A : public Base{};
class B : public Base{};
class C : public Base{};

Base* generate(void);
void identify(Base* p);
void identify(Base& p);

# endif
