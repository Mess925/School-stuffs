# include "bigint.hpp"
# include <ostream>
# include <string>
# include <sstream>

bigint::bigint() : _val("0") {}

std::string toStr(unsigned int n){
	std::stringstream ss;
	std::string res;
	ss << n;
	ss >> res;
	return res;
}

bigint::bigint(unsigned int n)
{
	std::string num = toStr(n);
	this->_val = num;
}

bigint::bigint(std::string n)
{
	this->_val = n;
}

bigint::bigint(const bigint &other)
{
	this->_val = other._val;
}

bigint &bigint::operator=(const bigint &other)
{
	if (this != &other)
		this->_val = other._val;
	return *this;
}

bigint &bigint::operator=(unsigned int n)
{
	*this = bigint(n);
	return *this;
}

bigint::~bigint(){}

std::string bigint::getVal() const {
	return this->_val;
}

std::ostream& operator<<(std::ostream& os, const bigint& b){
	os << b.getVal() << std::endl;
	return os;
}

bool bigint::operator>(const bigint& b){
	return (this->_val < b._val);
}

bool bigint::operator<(const bigint& b){
	return (this->_val < b._val);
}

bool bigint::operator==(const bigint& b){
	return (this->_val == b._val);
}

bool bigint::operator>=(const bigint& b){
	return (this->_val >= b._val);
}

bool bigint::operator<=(const bigint& b){
	return (this->_val <= b._val);
}

bool bigint::operator!=(const bigint& b){
	return (this->_val != b._val);
}
