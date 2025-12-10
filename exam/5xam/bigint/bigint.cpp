# include "bigint.hpp"
#include <cstddef>
#include <iterator>
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
	return (this->_val > b._val);
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

bigint bigint::operator+(const bigint& b){
	std::string firstval = this->_val;
	std::string secval = b.getVal();
	std::string result = "";

	int carry = 0;
	int firstIndex = firstval.length() - 1;
	int secondInex = secval.length() - 1;

	while (firstIndex >= 0 || secondInex  >= 0 || carry) {
		int firstDigit = firstIndex >= 0 ? firstval[firstIndex] - '0' : 0;
		int secondDigit = secondInex >= 0 ? secval[secondInex] - '0' : 0;
		
		int sum = firstDigit + secondDigit + carry;
		carry = sum / 10;
		result.insert(result.begin(), (sum % 10) + '0');

		firstIndex --;
		secondInex --;
	}
	return bigint(result);
}

bigint& bigint::operator++(){	
	*this = *this + bigint(1);
	return *this;
}

bigint bigint::operator++(int){
	bigint temp = *this;
	*this = *this + bigint(1);
	return temp;
}

bigint& bigint::operator+=(const bigint& b){
	*this = *this + b;
	return *this;
}

bigint bigint::operator<<(int n){
	if(this->_val == "0")
		return *this;
	std::string res = this->getVal();
	res = res + std::string(n, '0');
	return (bigint(res));
}

bigint bigint::operator>>(int n) {
    std::string res = this->getVal();

    if (res.length() <= (size_t)n)
        return bigint("0");

    res.erase(res.length() - n, n); 
    return bigint(res);
}

void bigint::removeLeadingZero(){
	if(this->_val.empty())
		this->_val = "0";
	int i = 0;
	while(i < (int)this->_val.length() - 1 && _val[i] == '0')
		++i;
	this->_val = this->_val.substr(i);
}


