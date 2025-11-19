#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>
#include <ostream>

class vect2
{
private:
	int first;
	int second;

public:
	vect2();
	vect2(int i, int j);
	vect2(const vect2 &other);
	vect2 &operator=(const vect2 &other);
	~vect2();

	// getter and setter
	int getfirst() const;
	int getsecond() const;
	void setfirst(int i);
	void setsecond(int j);

	//[] op overload
	int operator[](int i);
	const int operator[](int i) const;

	// * op
	vect2 &operator*(int i);
};

vect2 operator-(vect2 &v);
std::ostream &operator<<(std::ostream &os, const vect2 &v);

#endif
