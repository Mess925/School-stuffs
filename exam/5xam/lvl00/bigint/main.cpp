# include "bigint.hpp"
int main(){
	bigint a;
	bigint b(0);
	bigint c("1");
	bigint d;
	
	std::cout <<"a is " << a ;
	// a = c;
	d = 5;
	std::cout <<"a is " << a ;
	std::cout <<"b is " << b ;
	std::cout <<"c is " << c ;
	std::cout <<"d is " << d ;

	std::cout << "BOOL TEST CASES" << std::endl;
	std::cout << (a < b) << std::endl;
	std::cout << (a > b) << std::endl;
	std::cout << (a == b) << std::endl;
	std::cout << (a >= b) << std::endl;
	std::cout << (a <= b) << std::endl;
	std::cout << (a != b) << std::endl;

	//object type return 
	std::cout << "OBJECT TEST CASES" << std::endl; 
	a = 98;
	c = 1;
	std::cout << " a + c is = " << (a + c);
	std::cout << a++ ;
	std::cout << ++a ;
	std::cout << ( c += a  );
	c =  123456;
	std::cout << (c << 3 ) ;
	std::cout << (c >> 3 ) ;
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
