/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hthant <hthant@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 18:53:23 by hthant            #+#    #+#             */
/*   Updated: 2025/09/03 09:08:43 by hthant           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter& other){
	(void) other;
} 

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other){
	(void) other;
	return(*this);
}

ScalarConverter::~ScalarConverter(){}

bool	isPseudoLiteral(const std::string &pLiteral)
{
	return( pLiteral == "nan" || pLiteral == "-inf" || pLiteral == "+inf" ||
		pLiteral == "nanf" || pLiteral == "-inff" || pLiteral == "+inff");
}

void	ScalarConverter::convert(const std::string& literal){
	if(literal.length() == 1 && isalpha(literal[0])){
		char c = literal[0];
		std::cout<<"char: '"<< c << "'" <<std::endl;
		std::cout<< "int: "<< static_cast<int>(c) <<std::endl;
		std::cout<<"float: "<<std::fixed<<std::setprecision(1)<<static_cast<float>(c) <<"f" <<std::endl;
		std::cout<<"double: "<<std::fixed<<std::setprecision(1)<<static_cast<double>(c)<<std::endl;
		return;
	}
	if(isPseudoLiteral(literal)){
		if(literal[literal.size() -1] == 'f'){
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << literal << std::endl;
			std::cout << "double: " << literal.substr(0 , literal.size() - 1) << std::endl; 
		}
		else{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			std::cout << "float: " << literal << "f" <<std::endl;
			std::cout << "double: " << literal << std::endl;
		}
		return;
	}

	char *end;
	errno = 0;
	long val = std::strtol(literal.c_str(), &end, 10);
	if (*end == '\0' && errno != ERANGE) {
		if (val >= 32 && val <= 126)
            		std::cout << "char: '" << static_cast<char>(val) << "'" << std::endl;
        	else if (val >= 0 && val <= 127)
			std::cout << "char: Non displayable" << std::endl;
        	else
        		std::cout << "char: impossible" << std::endl;

        	if (val >= std::numeric_limits<int>::min() && val <= std::numeric_limits<int>::max())
        		std::cout << "int: " << static_cast<int>(val) << std::endl;
        	else
           		 std::cout << "int: impossible" << std::endl;

        	std::cout << "float: " << std::fixed << std::setprecision(1)
                	<< static_cast<float>(val) << "f" << std::endl;
        	std::cout << "double: " << std::fixed << std::setprecision(1)
                	<< static_cast<double>(val) << std::endl;
        	return;
	}
	
	if (literal[literal.size() - 1] == 'f') {
    		errno = 0;
    		float fval = std::strtof(literal.c_str(), &end);
    		if (*end == 'f' && *(end + 1) == '\0' && errno != ERANGE) {
			std::string numPart(literal.begin(), literal.end() - 1);
			if (numPart.find('.') == std::string::npos) {
				std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
            			return;
        		}
			if (fval >= 32 && fval <= 126)
            			std::cout << "char: '" << static_cast<char>(fval) << "'" << std::endl;
        		else if (fval >= 0 && fval <= 127)
            			std::cout << "char: Non displayable" << std::endl;
        		else
            			std::cout << "char: impossible" << std::endl;

        		if (fval >= std::numeric_limits<int>::min() && fval <= std::numeric_limits<int>::max())
            			std::cout << "int: " << static_cast<int>(fval) << std::endl;
        		else
            			std::cout << "int: impossible" << std::endl;

        		std::cout << "float: " << std::fixed << std::setprecision(1) << fval << "f" << std::endl;
        		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(fval) << std::endl;
			return;
		}
	}

    // Try double conversion
	errno = 0;
    	double dval = std::strtod(literal.c_str(), &end);
    	if (*end == '\0' && errno != ERANGE) {
		if (dval >= 32 && dval <= 126)
			std::cout << "char: '" << static_cast<char>(dval) << "'" << std::endl;
	    	else if (dval >= 0 && dval <= 127)
			std::cout << "char: Non displayable" << std::endl;
	    	else
			std::cout << "char: impossible" << std::endl;
	    	if (dval >= std::numeric_limits<int>::min() && dval <= std::numeric_limits<int>::max())
			std::cout << "int: " << static_cast<int>(dval) << std::endl;
	    	else
		    	std::cout << "int: impossible" << std::endl;
	    	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(dval) << "f" << std::endl;
	    	std::cout << "double: "<< dval << std::endl;
		return;
	}
	std::cout << "char: impossible\nint: impossible\nfloat: impossible\ndouble: impossible\n";
}


// > ./convert 12345678
// char: impossible
// int: 12345678
// float: 12345678.0f
// double: 12345678.0
//  ~/s/CPP/M06/ex00 | main ?4                                                                                                                                                                              09:07:07
// > ./convert 123456789
// char: impossible
// int: 123456789
// float: 123456792.0f
// double: 123456789.0


