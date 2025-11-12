# ifndef BIGINT_HPP
# define BIGINT_HPP

# include <iostream>
# include <ostream>
# include <string>

class bigint {
	private:
		std::string _val;
	public:
		bigint();
		bigint(unsigned int n);
		bigint(std::string n);
		bigint(const bigint& other);
		bigint& operator=(const bigint& other);
		bigint& operator=(unsigned int n);
		bigint& operator=(std::string n);
		~bigint();

		std::string getVal() const ;
		bool operator>(const bigint& b);
		bool operator<(const bigint& b);
		bool operator==(const bigint& b);
		bool operator>=(const bigint& b);
		bool operator<=(const bigint& b);
		bool operator!=(const bigint& b);
};

std::ostream& operator<<(std::ostream& os, const bigint& b);

# endif
