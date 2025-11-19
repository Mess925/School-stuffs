#include "vect2.hpp"

int main()
{

	try
	{
		vect2 a;
		vect2 b(a);
		vect2 c(1, 2);
		vect2 d = c;
		std::cout << "vect2 a: " << a;
		std::cout << "vect2 b: " << b;
		std::cout << "vect2 c: " << c;
		std::cout << "vect2 d: " << d;
		std::cout << "vect2 d[1]: " << d[1] << std::endl;
		// std::cout << "vect2 d[-1]: " << d[-1] << std::endl ; //ERROR
		vect2 e(3, 3);
		e = -e;
		std::cout << "vect2 -e: " << e;
	}
	catch (const std::exception &e)
	{
		std::cerr << "ERROR" << std::endl;
	}
}
