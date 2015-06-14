#include "stdafx.h"
#include "BigUint.h"
#include <iostream>
using namespace std;

BigUint::BigUint()
{
	digitArray = nullptr;
	length = 0;
}

BigUint::BigUint(long unsigned val)
{
	digitArray = &val;
	length = 1;
}

BigUint::BigUint(long unsigned *digits, int unsigned numDigits)
{
	digitArray = new long unsigned[numDigits];
	for (int i = 0; i < numDigits; i++)
		digitArray[i] = digits[i];
	length = numDigits;
}

BigUint::BigUint(const BigUint &copy)
{
	length = copy.length;
	digitArray = new long unsigned[length];
	for (int i = 0; i < length; i++)
		digitArray[i] = copy.digitArray[i];
}

BigUint BigUint::operator =(const BigUint &rhs)
{
	if (this == &rhs)
		return *this;
	if (rhs.length != length)
	{
		delete[] digitArray;
		length = rhs.length;
		digitArray = new long unsigned[length];
	}
	for (int i = 0; i < length; i++)
		digitArray[i] = rhs.digitArray[i];
	return *this;
}

BigUint::~BigUint()
{
	if (length == 1)
		delete digitArray;
	else if (length > 1)
		delete[] digitArray;
}

void BigUint::printDigits(ostream &outs)
{
	for (int i = 0; i < length; i++)
		cout << digitArray[i] << " ";
}

BigUint BigUint::operator+(const BigUint &rhs)
{
	BigUint result;
	bool overflow = false;
	long unsigned left;
	long unsigned right;
	long unsigned *arrayWithCarry;
	result.length = rhs.length > length ? rhs.length : length;
	result.digitArray = new long unsigned[result.length];
	for (int i = 0; i < result.length; i++)
	{
		left = i < length ? digitArray[i] : 0;
		right = i < rhs.length ? rhs.digitArray[i] : 0;
		result.digitArray[i] = left + right + overflow;
		overflow = result.digitArray[i] < left || result.digitArray[i] < right;
	}
	if (overflow)
	{
		result.length++;
		arrayWithCarry = new long unsigned[result.length];
		arrayWithCarry[result.length - 1] = 1;
		for (int i = 0; i < result.length - 1; i++)
			arrayWithCarry[i] = result.digitArray[i];
		delete[] result.digitArray;
		result.digitArray = arrayWithCarry;
	}
	return result;
}