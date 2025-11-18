/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 10:55:22 by hthant            #+#    #+#             */
/*   Updated: 2025/09/17 17:17:44 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>

struct Data{
	std::string date;
	std::string value;
	size_t deli_pos;
	char deli;
};

class BitcoinExchange {
	private:
		std::map<std::string, double> _money;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		// bool validFile(const std::string& fileName);
		void processInputFile(const std::string& fileName);
		bool validLine(const std::string& line, Data& d, bool check);
		bool validDate(const std::string& date);
		bool validValue(const std::string& valueStr, bool check);

		bool loadData();
};


# endif

