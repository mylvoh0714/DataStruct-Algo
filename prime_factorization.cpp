#include <iostream>
#include <stdio.h>
#include <string>
using namespace std;

string primeFactorization(unsigned int _number);

int main(int argc, char** argv)
{
	if ( argc < 1 ) return -1;

	unsigned int number;
	sscanf(argv[1], "%u", &number);

	cout << primeFactorization(number) << endl;
	return 0;
}

string primeFactorization(unsigned int _number)
{
	string result = "";
	unsigned int i, expon, operand;
	operand = _number;

	for ( i = 2; i < _number; i++ )
	{
		expon = 0;
		while ( operand%i == 0 )
		{
			operand = operand / i;
			expon += 1;
		}

		if ( expon > 0 )
		{
			if ( result == "" )
				result += std::to_string(i) + '^' + std::to_string(expon);
			else
				result += " x " + std::to_string(i) + '^' + std::to_string(expon);
		}
	}

	return result;

}
