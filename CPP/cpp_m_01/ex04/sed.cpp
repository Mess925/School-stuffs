/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sed.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:05:51 by hthant            #+#    #+#             */
/*   Updated: 2025/06/02 16:02:47 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "sed.hpp"

std::string Sed::_getFile()
{
    std::ifstream inputfile((_fileName).c_str());
    if(!inputfile)
    {
        std::cerr << "Error:: Cannot open file " <<_fileName << "\n";
        return "";
    }
    std::string content;
    std::string line;
    while (std::getline(inputfile, line)) {
        content += line + '\n';
    }
    return content;
}

std::string Sed::_contecntReplace(const std::string& file)
{
    if(_s1.empty())
        return file;
    std::string replaced;
    size_t position = 0;
    size_t start;;
    while ((start = file.find(_s1, position)) != std::string::npos)
    {
        replaced += file.substr(position, start - position);
        replaced += _s2;
        position = start + _s1.length();
    }
    replaced += file.substr(position);
    return replaced;
}

bool Sed::replace()
{
    std::string file = _getFile();
    if (file.empty() && !_s1.empty())
        return false;
    std::string newstring = _contecntReplace(file);
    std::ofstream outfile((_fileName + ".replace").c_str());
    if(!outfile)
    {
        std::cerr << "Error:: Cannot create outputfile." << std::endl;
        return false;
    }
    outfile << newstring;
    return true;
}