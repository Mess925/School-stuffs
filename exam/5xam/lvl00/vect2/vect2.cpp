#include "vect2.hpp"

vect2::vect2() : first(0), second(0) {}

vect2::vect2(int i, int j) : first(i), second(j) {}

vect2::vect2(const vect2 &other)
{
	first = other.first;
	second = other.second;
}

vect2 &vect2::operator=(const vect2 &other)
{
	if (this != &other)
	{
		first = other.first;
		second = other.second;
	}
	return *this;
}

vect2::~vect2() {}

int vect2::operator[](int i)
{
	if (i >= 2 || i < 0)
		throw std::exception();
	if (i == 0)
		return first;
	if (i == 1)
		return second;
	return -1;
}

const int vect2::operator[](int i) const
{
	if (i >= 2 || i < 0)
		throw std::exception();
	if (i == 0)
		return first;
	if (i == 1)
		return second;
	return -1;
}

vect2 &vect2::operator*(int i)
{
	first = first * i;
	second = second * i;
	return *this;
}

int vect2::getfirst() const
{
	return this->first;
}

int vect2::getsecond() const
{
	return this->second;
}

void vect2::setfirst(int i)
{
	this->first = i;
}

void vect2::setsecond(int j)
{
	this->second = j;
}

vect2 operator-(vect2 &v)
{
	int i = v.getfirst() * -1;
	int j = v.getsecond() * -1;
	v.setfirst(i);
	v.setsecond(j);
	return v;
}

std::ostream &operator<<(std::ostream &os, const vect2 &v)
{
	std::cout << "{ " << v[0] << ", " << v[1] << " }" << std::endl;
	return os;
}
