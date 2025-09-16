/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/12 10:55:22 by hthant            #+#    #+#             */
/*   Updated: 2025/09/16 15:26:23 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <map>
# include <string>

struct InputData{
	std::string date;
	std::string value;
	size_t deli_pos;
};

class BitcoinExchange {
	private:
		std::map<std::string, double> _money;
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& other);
		BitcoinExchange& operator=(const BitcoinExchange& other);
		~BitcoinExchange();

		bool isValidFile(const std::string &fileName);
		bool validLine(const std::string& line);
		bool validDate(const std::string& date);
		bool validValue(const std::string& valueStr);
};

# endif
