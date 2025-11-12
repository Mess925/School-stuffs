# include "bigint.hpp"
int main(){
	bigint a;
	bigint b(0);
	bigint c("1");
	bigint d;
	
	std::cout << a <<std::endl;
	a = c;
	d = 5;
	std::cout << a <<std::endl;
	std::cout <<" b is " <<b <<std::endl;
	std::cout << c << std::endl;
	std::cout << d << std::endl;
}

/* these return a new value
 * + 
 * pre ++
 * post ++
 * << bitshift
 * >> bitshift
 * +=
 *
 * these point return bool
 * > greater than 
 * < less than
 * == equal
 * >= 
 * <=
 * !=
*/
