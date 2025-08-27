# include <iostream>
void test()
{
	int x = 100;
	if(x <100)
	{
		std::cout<<"less than 100"<<std::endl;
	}
	else
		throw 120;
}

int main()
{
	try {
		test();	
	}
	catch(...)
	{
		std::cout<<"HELLO"<<std::endl;
	}
}
