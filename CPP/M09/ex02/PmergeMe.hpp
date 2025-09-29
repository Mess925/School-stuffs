/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 11:24:39 by hthant            #+#    #+#             */
/*   Updated: 2025/09/22 14:40:36 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <string>
# include <bits/stdc++.h>

class Merge {
	private:
		std::vector<int> _vectorData;
		std::deque<int> _dequeData;
	public:
		Merge();
		Merge(const Merge& other);
		Merge& operator= (const Merge& other);
		~Merge();

		void program(int ac, char** av);
		void checkInput(int ac, char** av);
		void Display(const std::string& str, const std::vector<int>& data);
		void magic(std::vector<int>& data);
		// void magicD(const std::deque<int> & data);
};

# endif
