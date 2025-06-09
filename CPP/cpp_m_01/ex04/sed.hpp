/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 15:38:15 by hthant            #+#    #+#             */
/*   Updated: 2025/06/02 15:51:13 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SED_HPP
# define SED_HPP

# include <iostream>
# include <string>
# include <fstream>

class Sed
{
private:
    std::string _fileName;
    std::string _s1;
    std::string _s2;
    std::string _getFile();
    std::string _contecntReplace(const std::string& file);
public:
    Sed(const std::string& filename, const std::string& s1, const std::string& s2)
    {
        _fileName = filename;
        _s1 = s1;
        _s2 = s2;
    }
    bool replace();
};



# endif