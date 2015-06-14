#ifndef Big_Uint
#define Big_Uint
#include <string>
#include <iostream>
using namespace std;

class BigUint
{
public:
	BigUint();
	BigUint(long unsigned val);
	BigUint(long unsigned *digits, int unsigned numDigits);
	BigUint(const BigUint &copy);
	BigUint operator =(const BigUint &rhs);
	~BigUint();

	//string toString();
	void printDigits(ostream &outs);

	BigUint operator +(const BigUint &rhs);
private:
	long unsigned *digitArray;
	int unsigned length;
};
#endif