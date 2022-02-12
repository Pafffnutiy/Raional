#include "Header.h"
#include <iostream>
#include <cassert>
#include <cmath>

int main()
{
	//Rational Drob1(4,15);
	Rational Drob2(-2,3);
	Rational Drob3(3,4);
	Rational Drob4(-2, -4);
	//Rational Drob5(-2, -5);
	//Rational Drob6(3, 8);
	
	//std::cout << Drob1 << '\n' << Drob2 << '\n' << Drob3 << '\n' << Drob4 << '\n';

	//std::cout << "2/5+(-2/3) = " << Drob5 + Drob2 << '\n';
	//std::cout << "3/8+3/4 = " << Drob6 + Drob3 << '\n';
	//std::cout << "-2/3-3/4 = " << Drob2 - Drob3 << '\n';
	std::cout << "1/2-3/4 = " << Drob4 - Drob3 << '\n';
	//std::cout << "2/5*3/8 = " << Drob5 * Drob6 << '\n';
	//std::cout << "5*4/15 = " << 5 * Drob1 << '\n';
	std::cout << "-2/3*1/2 = " << Drob2 * Drob4 << '\n';


	return 0;
}